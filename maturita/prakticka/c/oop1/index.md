---
layout: page
title: Praktická maturita - PRG Databaze OOP 2
description: Databaze OOP C++ 1
has_children: false
parent: c
---

[hlavicka.h](./hlav.md){: .btn .btn-purple }
[zak.cpp](./zak.md){: .btn .btn-purple }
[trida.cpp](./trida.md){: .btn .btn-purple}
[main.cpp](./main.md){: .btn .btn-purple }
[Stahnout projekt](/maturitka/files/Trida.rar){: .btn .btn-green}

## OOP - Databáze v jazyce C++ - 1
- Napište program v jazyce C++ pro vyhodnocení výsledků testů žáků. Testy se konají z matematiky, jazyka českého a jazyka anglického, jsou hodnoceny bodově (1-100). Záznam o každém studentovi bude obsahovat jeho číslo, jméno a příjmení, body z jednotlivých částí testu a celkové hodnocení.


### Požadavky:  
- Navrhněte vhodné datové struktury – použijte třídy pro studenta a skupinu studentů
- Vytvořte konstruktory pro obě třídy
- Použijte přetížení pro operátory << a >>
- Pro žáka určete celkové hodnocení následovně: když má z každého testu maximálně 40 bodů, potom neprospěl. Když má z každého testu minimálně 85 bodů, prospěl s vyznamenáním. V ostatních případech žák prospěl
- Pro třídu, která bude reprezentovat skupinu žáků (použijte pole), sestavte funkční metody:
    - přidání jednoho žáka
    - výpis seznamu žáků
    - zápis dat do textového souboru a čtení ze souboru. Informace o jednom žákovi ukládejte na jeden řádek, zvolte vhodný oddělovač
    - 2 způsoby vyhledávání: podle příjmení a podle čísla
    - odstranění žáka podle čísla
    - editace údajů o žákovi
    - seřazení podle příjmení 
    - pro každý předmět určete žáka s nejlepším výsledkem 
    - vypočítejte průměrný počet bodů, které získali žáci
- Pro ovládání programu sestavte uživatelskou nabídku
- Navrhněte vhodný způsob kontroly vstupních údajů a ošetření možných chyb při běhu programu
- Použijte komentáře pro zpřehlednění a popsání kódu
