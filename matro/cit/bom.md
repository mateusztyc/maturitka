---
layout: page
grand_parent: Výuka
parent: Číslicová technika
title: Seznam součástek
description: Součástky potřebné na praktické cvičení
subject: cit
---

## Seznam součástek

Ve cvičeních budeme zapojovat některé z obvodů. Proto je potřeba abyste si pořídili tyto součástky:

### 1. pololetí

| Součástka         | Počet/Množství |  Popis                         | Poznámka                                        |
|:------------------|:--------------:|:-------------------------------|:------------------------------------------------|
| Baterie 4.5V      | 1              | plochá                         | *pro práci doma; ve škole bude zapůjčený zdroj* |
| Kontaktní pole    | 1              | nepájivé pole (breadboard)     | *pro práci doma; ve škole bude pole zapůjčeno*  |
| Vodiče            | 5m             | např. zvonkový drát            | **NÉ: lanko nebo vodiče pro Arduino**           |
| Sedmisegment      | 1              |                                | může mít společnou katodu nebo anodu            |
| LED               | 6              | min. 2 barvy (červená, zelená) | vhodné LED s nízkým příkonem                    |
| DIP (4IN)         | 2              | přepínače pro 4 vstupy         | **vyzkoušet rozteče na kontaktním poli!**       |
| Odpor 1k &#8486;  | 6              | ochranný rezistor; pro TTL 150 | Možnost použít i "odporový žebříček"            |
| Odpor 10k &#8486; | 4              | ochranný rezistor; pro TTL 1k  |                                                 |
| **Integrované obvody:** | | | |
| Dekodér BCD-7SEG  | 1              | 7447                           | Dekodér BCD pro zobrazení na 7-segmentu         |
| NAND              | 2              | 74HC00                         | technologie MOS[^1]                             |
| NOR               | 2              | 74HC02                         | technologie MOS[^1]                             |
| NOT               | 2              | 74HC04                         | technologie MOS[^1]                             |
| AND               | 1              | 74HC08                         | technologie MOS[^1]                             |
| OR                | 1              | 74HC32                         | technologie MOS[^1]                             |

### 2. pololetí

| Součástka         | Počet/Množství |  Popis                         | Poznámka                                        |
|:------------------|:--------------:|:-------------------------------|:------------------------------------------------|
| Čítač '90[^2]     | 1              | dekadický čítač (0-9)          |                                                 |
| Čítač '93[^2]     | 1              | 4-bitový čítač (0-F)           |                                                 |
| Čítač '193[^2]    | 1              | 4-bitový čítač s dvojím CLK    |                                                 |
| Generátor hodin   | 1              | složen z C, R a obvodů 555     | možnost hopostavit na bázi 74*04                |

[^1]: Technologie MOS používá jiné napětí než TTL. TTL obvody pak mají jsou bez písmen HC nebo mají naopak písmena HCT (příkklad. 7400, 74HCT04). V případě použití obvodu TTL musíte zvolit vhodné odpory!

[^2]: Apostrof (') je zástupný znak za skupiny znaků (např. 74HC90, 7490 a 74HCT90)
