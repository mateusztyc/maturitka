---
layout: page
title: Praktická maturita - Dynamicky spojovy seznam
description: Spojovy seznam
has_children: false
parent: c
---
[seznam.c](./seznam.md){: .btn .btn-purple }
[Stahnout seznam](/maturitka/files/slovnik.c){: .btn .btn-green}

## Dynamický seznam
- Napište program v jazyce C pro vyhodnocení výsledků přijímacích zkoušek. Zkoušky se konají z matematiky, českého jazyka a fyziky. Záznam o každém studentovi bude obsahovat jeho číslo, jméno a příjmení, bodové hodnocení jednotlivých částí zkoušky. Pro uložení informací použijte lineární obousměrný seznam

### Požadadvky
- Navrhněte dynamickou strukturu pro řešení problematiky. Použijte vnořené struktury
- Pro ovládání programu sestavte přehlednou uživatelskou nabídku, pro jednotlivé operace se záznamy navrhněte vhodné funkce.
- Pro údaje o studentovi nastavte:
    - číslo studenta bude jedinečné
    - bodové hodnocení každé zkoušky je v rozsahu 0–20 bodů
    - automaticky vypočítejte celkový počet bodů pro každého studenta jako součet jednotlivých zkoušek
- Program umožní přidávat studenty (na konec seznamu) a zobrazit data na monitoru.
- K vyhledávání výsledků studenta použijte část jeho příjmení
- Uživatel vybírá způsob řazení. Studenty je možno seřadit podle příjmení, podle výsledků jednotlivých testů nebo podle celkového výsledku 
- Program umožní zápis dat do souboru a čtení ze souboru, použijte binární soubor
- Možnost odstranění studenta, určeného číslem 
- Možnost editování údajů o studentovi (kromě čísla)
- Určete studenta s nejlepším celkovým výsledkem
- Zobrazte studenty, kteří u přijímaček neuspěli. Jsou to ti, kteří měli alespoň z jedné zkoušky maximálně 5 bodů.
- Navrhněte vhodný způsob kontroly vstupních údajů a ošetření možných chyb při běhu programu. 
- Použijte komentáře pro zpřehlednění a popsání kódu
