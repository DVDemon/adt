# ADR01 Выбор механизма для управления загрузкой из внешних источников

---
status: proposed 
date: 2022-08-17
deciders: Дзюбва Дмитрий
---

## Context and Problem Statement

Некоторые типы источников данных для цифрового двойника не поддерживают механизмы стриминга изменений. Необходимо организовать загрузку данных на периодической основе через различные выгрузки.

## Considered Options

* Использование cron и custom-утилит для загрузки
* Использование apache airflow
* Spark?

## Decision Outcome


### Positive Consequences


### Negative Consequences



