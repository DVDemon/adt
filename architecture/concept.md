# Концептуальная диаграмма первого этапа

```plantuml
!include https://raw.githubusercontent.com/plantuml-stdlib/C4-PlantUML/master/C4_Container.puml
@startuml
left to right direction

Container(import_scheduler,"Import Scheduler","Python/Airflow?")
Container(export_scheduler,"Export Scheduler","Python/Airflow?")

ContainerDb(staging_db,"База данных для промежуточной загрузки","PostgreSQL")
ContainerDb(core_db,"База данных для хранения графа","Neo4J")
ContainerDb(object_db,"База данных для хранения сущностей","Mongo")
ContainerDb(broker,"Очередь нотификаций","Kafka")

Container(jira_importer,"Jira issues importer","C++")
Container(cnf_product_importer,"Confluence Product Importer","C++")
Container(cnf_adr_importer,"Confluence ADR Importer","C++")
Container(cnf_techcom_importer,"Confluence Techcom Importer","C++")
Container(git_arch_importer,"Gitlab architecture importer","C++")
Container(cnf_exporter,"Confluence Exporter","C++")
Container(mail_exporter,"Email exporter","C++")
Container(core_loader,"Core Loader","C++")


System(jira,"Jira")
System(gitlab,"Gitlab")
System(confluence,"Confluence")
System(email,"Email Server")

Rel(import_scheduler,jira_importer,"Запуск загрузки","shell")
Rel(jira_importer,jira,"GET https://jira.mts.ru/rest/api/2/issue/{key}","HTTP")
Rel(jira_importer,broker,"send notification","TCP")
Rel(jira_importer,staging_db,"Сохранение новых данных","SQL")

Rel(import_scheduler,cnf_product_importer,"Запуск загрузки","shell")
Rel(cnf_product_importer,confluence,"GET https://confluence.mts.ru/rest/api/content/{page_id}","HTTP")
Rel(cnf_product_importer,broker,"send notification","TCP")
Rel(cnf_product_importer,staging_db,"Сохранение новых данных","SQL")

Rel(import_scheduler,cnf_adr_importer,"Запуск загрузки","shell")
Rel(cnf_adr_importer,confluence,"GET https://confluence.mts.ru/rest/api/content/{page_id}","HTTP")
Rel(cnf_adr_importer,broker,"send notification","TCP")
Rel(cnf_adr_importer,staging_db,"Сохранение новых данных","SQL")

Rel(import_scheduler,cnf_techcom_importer,"Запуск загрузки","shell")
Rel(cnf_techcom_importer,confluence,"GET https://confluence.mts.ru/rest/api/content/{page_id}","HTTP")
Rel(cnf_techcom_importer,broker,"send notification","TCP")
Rel(cnf_techcom_importer,staging_db,"Сохранение новых данных","SQL")

Rel(import_scheduler,git_arch_importer,"Запуск загрузки","shell")
Rel(git_arch_importer,gitlab,"GET /projects/:id/repository/files/:file_path/raw","HTTP")
Rel(git_arch_importer,broker,"send notification","TCP")
Rel(git_arch_importer,staging_db,"Сохранение новых данных","SQL")


Rel(core_loader,broker,"Read notification","TCP")
Rel(core_loader,staging_db,"Read imported data","SQL")
Rel(core_loader,core_db,"Merge new grph data","CYPHER over BOLT")
Rel(core_loader,object_db,"Save new object data","TCP")

Rel(export_scheduler,cnf_exporter,"Start export","shell")
Rel(cnf_exporter,confluence,"PUT https://confluence.mts.ru/rest/api/content/{page_id}","HTTP")

Rel(export_scheduler,mail_exporter,"Start export","shell")
Rel(mail_exporter,email,"Send email","TCP")


@enduml

```