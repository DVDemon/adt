# UC02:Импорт каталога продуктов Confluence
```plantuml
@startuml
    participant "Scheduler application" as scheduler
    participant "Confluence importer" as import_cnf_product
    participant "confluence" as confluence
    participant "PostgreDB staging" as pdb
    participant "Broker" as broker

    
    activate scheduler
    note over scheduler: Start once a day
        
    scheduler -> import_cnf_product : import()
    import_cnf_product -> confluence : "GET https://confluence.mts.ru/rest/api/content/{page_id}"

    note over import_cnf_product: Parse product, codes, persons
    import_cnf_product -> pdb : "insert into jira_staging"
    import_cnf_product -> broker : "send notification"
    @enduml
```