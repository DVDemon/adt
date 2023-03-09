# ADR07 Способ хранения данных в EDT

---
status: proposed 
date: 2022-08-17
deciders: Дзюбва Дмитрий
---

## Context and Problem Statement

Нужно определить что мы будем хранить в EDT свми данные о сущностях, либо только идентификационные данные а данные о сущностях будут хранится в источниках

## Considered Options

- Хранить все данные о enterprise и клиентах
- Хранить только идентификационные данные сущностей, связи между ними, а остальнео в виде референса в БД-источник
- Хранить идентификационные данные, связи, события изменения сущностей, а остальнео в виде референса в БД-источник

## Decision Outcome



### Positive Consequences


### Negative Consequences