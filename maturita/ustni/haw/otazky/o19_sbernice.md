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

![Obrazok](./assets/images/x/speaker.JPG)

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

## Rozdělení sběrnic
- Paralelní sběrnice – PCI, PCI-x, ISA
- Sériová sběrnice – USB, PCI-express
- Interní sběrnice – ISA, PCI
- Externí sběrnice – USB, FireWare

## Základní parametry sběrnice
- Frekvence
    - Maximální frekvence, se kterou může sběrnice pracovat
- Šířka sběrnice
    - Dáno počtem vodičů, po kterých se data přenášejí
- Rychlost přenosu dat (propustnost)
    - Množství přenesených dat za jednotku času
- Přístupová doba
    - Střední doba čekání na uvolnění sběrnice

## Systémová sběrnice - FSB