---
layout: page
title: Konstrukční uspořádaní PC - typy a charakteristiky sběrnic
description: Otázka č.19 - Konstrukční uspořádaní PC - typy a charakteristiky sběrnic
has_children: false
nav_exclude: true
---
# Konstrukční uspořádaní PC - typy a charakteristiky sběrnic
## Sběrnice
- Sběrnice je skupina signálových vodičů
- Slouří ke vzájemnému propojení CPU, OP a dalších zařízení (GPU, zvukovka, síťovka, řadič HDD)

![o1](../assets/images/o19/1.jpg)

## Typy vodičů sběrnic
- Řídící
    - Řízení komunikace
    - CLK, CS, CE, MEM read/write
- Adresové
    - Přenos adresy určitého zařízení (blok paměťi)
    - Šířka datové sběrnice je definována jako maximální velikost přenášené adresy
    - A+, A-
- Datové
    - Přenos dat
    - Počet vodičů sběrnice určuje, kolik dat je sběrnice schopná přenést najednou v 1 taktu
    - D+,D-