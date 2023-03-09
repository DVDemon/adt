# ADR06 Выбор способа хранения истории графа

---
status: proposed 
date: 2022-08-17
deciders: Дзюбва Дмитрий
---

## Context and Problem Statement

Необходимо вести историю изменения графа и эффективно ее анализировать

## Considered Options

- Хранение версии каждего объекта внутри
- Хранение версии изменений каждого объекта - отдельно
- Механизм baseline
- Не хранить версии

## Decision Outcome

JanusGraph + Scylla

### Positive Consequences


### Negative Consequences
