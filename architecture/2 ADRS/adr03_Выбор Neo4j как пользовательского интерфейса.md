# ADR02 Выбор Neo4j как пользовательского интерфейса

---
status: proposed 
date: 2022-08-17
deciders: Дзюбва Дмитрий
---

## Context and Problem Statement

В целях поиска закономерностей/отладки и просто нахождения информации о объектах в базе нужен пользовательский интерфейс.

## Considered Options

* Написание отдельного портала для просмотра
* Использование встроенных средств Neo4j
* Использование портала backstage.io

## Decision Outcome

Пока остановимся на выборе встроенных средств Neo4j (для этого в нем должны быть ключевые данные)

### Positive Consequences

* экономия трудозатрат
* возможность использовать Cypher для поиска данных

### Negative Consequences

* В интерфейсе не удобно просматривать много атрибутов узлов
* В интерфейсе будет видна только информация которая есть в neo4j
