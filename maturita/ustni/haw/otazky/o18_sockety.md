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
        - S jižním mostem pomocí speciální sběrnice DMI¨
    - Propojen s CPU pomocí FSB (front Side Bus)
     - 64 bit
     - Od frekvence sběrnice se odvíjí taktovací frekvence CPU a OP
      - Během 1 CLK dokáže přenést data 4x
    - V případě víceprocesorového systému sdílejí CPU sběrnici FSB
        - Nemožnost komunikace CPU přímo mezi sebou
        - Snížení přenosové rychlost
- Jižní most = South Bridge
    - Nazván také ICH (Input Output Controler Hub)
    - Pomalejší než MCH
    - Umožnuje připojení periferních zařízení k MB
    - Obsahuje řadič disků (ATA, SATA, eSATA, RAID) a rozhraní (USB, PS/2)
    - Řídí komunikace na sběrnici PCIe
    - K obvodu muže být připojen zvukový adaptér, paměťový obvod BIOS, integrovaný síťový adaptér
    - Se severním mostem propojeno pomocí DMI

- Čipové sady s integrovaným řadičem OP
    - Severní most dostal označení IOH = Input Output Hub
    - Řadič operační paměti se přesunul z IOH do CPU
    - Místo FSB sběrnice se objevuje Quick Path Interconnect QPI
    - Rychlejší komunikace
    - Odolnější proti chybám vzniklých při přenosu
    - Lepší kompatibilita s OP
    - Lepší chlazení díky integraci v CPU
    - Vyšší teplo vyzářené z CPU
    - QUICK PATH INTERCONNECT
        - Umožnuje komunikaci více CPU přímo mezi sebou
        - Full duplex (2x20bit)
        - Každá IOH obsahuje 2 QPI
            - Využití jednoho IOH – pro každý CPU vlastní QPI
            - Využití dvou IOH – pro každý CPU vlastní IOH

- Čipová sada s plně integrovaným severním mostem
    - Kromě řadiče OP je integrován také řadič GPU sběrnice
    - Základní deska nově obsahuje PCH
        - Platform Controler Hub
        - Propojeno s CPU pomocí DMI
        - Zastává funkci jižního mostu

## Typy a charakteristika sockterů Intel a AMD
- 