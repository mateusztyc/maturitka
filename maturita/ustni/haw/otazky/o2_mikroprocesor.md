---
layout: page
title: Mikroprocesor
description: Otázka č.2 - Mikroprocesor
has_children: false
nav_exclude: true
---
# Mikroprocesor
- Lze definovat jako sekvenční automat vyrobený technologií VLSI(Very Large Scale Integration)
- Je tvořen řadičem, ALU(aritmetická jednotka) a pracovními registry
- Bez podpůrných obvodů není schopen provozu
- Mikropočítač vznikne připojením k paměti vstupních a výstupních bloků (je rozšířen o paměť, vstupní a výstupní bloky)
- Mikropočítač doplněný o periferie umožňující komunikaci s uživatelem (monitor, klávesnice, myš, vnější paměť) pak tvoří mikropočítačový systém

## Mikroprocesor - abstrakce
- Výpočetní systém si lze představit jako člověka -> řadič
    - Ten ovládá kalkulačku -> ALU
        - Ovládání je dáno programem -> instrukce
- Člověk zadává údaje přes klávesnici
     - Vstupní jednotka
- Výsledky výpočtu jsou vidět na displeji
     - Výstupní jednotka
- Na stole jsou položeny hodiny
    - Každou minutu je proveden další příkaz (instrukce)
- Příkazy na papíru jsou zpracovány sekvenčně
    - Program Counter

## Architektury
- ### Von Neumannova architektura
    - Vznikla 1945
    - Obsahuje 5 základních částí
    - **základem dnešních výpočetních strojů** - s jistými změnami jako je multitasking, víceprocesorové systémy, vstupně-výstupní zařízení, program nemusí být celý zaveden v OP
    - Instrukce i data jsou členěny do slov/slabik stejného formátu (8-bit velikost) – jsou uloženy ve společné paměti a nejsou nijak speciálně rozlišeny
    - V společné paměti hrozí přepsání dat
    - Data zpracovává sekvenčně (posupně) oproti harvardské, která je zpracovává paralelně
    - **SPECIFIKACE:**
        - struktura PC je nezávislá na řešeném problému
        - V paměti jsou data uloženy společně s instrukcemi programu (binárně zakódovány)
        - Paměť je rozdělena na buňky stejně velikosti a přistupuje se k nim pomocí adresy
        - Program tvoří posloupnost instrukcí – jsou prováděny sekvenčně vyjma skokových instrukcí
- ### Harvardská architektura
    - Snaží se řešit problém Von Neumannovy metody -> zavádí 2 paměti – 1 pro program a 1 pro data
    - Paměti můžou být různého typu a velikosti
    - Nedají se kombinovat – pokud dojde paměť pro data nemůžeme je uložit nikam jinam
    - 2 sběrnice pro každou jednu paměť -> náročnější na řízení (fyzické rozdělení paměti)
    - Nenastane situace vlastního přepsání
    - Je možné pracovat najednou jak s instrukcemi tak s daty (souběžný přístup) -> vyšší nároky na vývoj řídící jednotky
    - Řízení CPU je odděleno od řízení VV jednotek – nejsou napojeny přímo na ALU
    - Atmel 8051, ARM – většinou kombinace obou architektur

## ARM
-  První ARM vyrobila firma Acron Computers – 1978 Cambridge
- **Vize:** Vývoj osobního PC pro firmy a domácnosti, který by používal redukovanou instrukční sadu **RISC:**
    - zjednodušení příkazů (instrukcí)
    - zrychlení samostatného zpracování instrukcí
    - více jednoduchých po sobě následujícíh instrukcí místo složitých instrukcí vykonávající složité operace (CISC)
### Acron Archimedes
- První PC vybavený ARMem. Projekt byl bohužel neúspěšný -> firma krachla
### Newton MessagePad
- Postaven na ARM procesoru (ARM 610 RISC)
- Newton OS
- Osobní digitální asistent od firmy Apple(1993)
### Arm Holdings
- 