---
layout: page
title: Konstrukční uspořádaní PC - sockety, chlazení, chipsety
description: Otázka č.12 - Konstrukční uspořádaní PC - sockety, chlazení, chipsety
has_children: false
nav_exclude: true
---
# Konstrukční uspořádaní PC - sockety, chlazení, chipsety
## Vnitřní struktura a popis jednotlivých částí základní desky

- Účelem základní desky je propojit jednotlivé součástky PC do fungujícího celku a poskytnout jim elektrické napájení
- Nejdůležitější IO jsou zabudovány v čipové sadě
- Skládá se z:
    - Sokety
    - Paměťové sloty
    - Non - volatile paměť (Flash ROM) - obsahuje firmware nebo BIOS
    - CLK generátor - produkuje hodinový signál za účelem synchronizace různých komponent
    - Sloty pro karty (grafické, síťové) - PCI express
    - Napájecí konektory
    - Konektory předního panelu
    - Baterie
    - BIOS
    - Konektory pro periférie
    - SATA konektory pro disky
    - I/O řadiče
    - Sběrnice - AGP, ISA

## Chipset
- Nejdůležitější logická obvod základní desky
- Umožnuje procesoru komunikovat s ostatními částmi PC -> řídí komunikaci
- V obvodech čipové sady jsou integrovaný řadiče, které na základě zpracování instrukcí generují řídící signály pro tato zařízení
- Sběrnice jsou uspořádány hierarchicky od nejrychlejší (FSB) po nejpomalejší (ISA)
- Obsahuje mosty pro propojení různých sběrnic mezi sebou
    - Severní most
    - Jižní most
- Dělení:
    - Čipová sada s obvody severního a jižního mostu
    - Čipová sada s integrovaným řadičem paměti v CPU
    - Čipová sada s integrovaným severním mostem

- Severní most = North Bridge
    - Systémový řadič, nazýván MCH (Memory Controller Hub)
    - Přímo komunikuje s COU, OP a GPU
        - S jižním mostem pomocí speciální sběrnice DMI