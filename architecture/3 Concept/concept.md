# Концептуальная диаграмма первого этапа

```plantuml
!include https://raw.githubusercontent.com/plantuml-stdlib/C4-PlantUML/master/C4_Container.puml

Container(scheduler,"Import Scheduler","Python/Airflow?")
ContainerDb(staging_db,"База данных для промежуточной загрузки","PostgreSQL")
ContainerDb(core_db,"База данных для хранения графа","Neo4J")
ContainerDb(entity_db,"База данных для хранения сущностей","Mongo")


Container(jira_importer,"Jira importer","С++")
Rel(scheduler,jira_importer,"Запуск по расписанию")
Rel(jira_importer,staging_db,"Загрузка данных о инициативах продукта")
Rel(jira_importer,staging_db,"Добавление новых продуктов")



```