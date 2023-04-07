---
layout: page
title: Praktická maturita - PRG Slovník
description: Slovník
has_children: false
parent: c
---

[slovnik.h](./slovh.md){: .btn .btn-purple }
[slovnik.c](./slovc.md){: .btn .btn-purple }
[main.c](){: .btn .btn-purple }

## Pokročilá práce s textovým souborem
- Napište program v jazyce C, který umožní překládat a testovat slovíčka. Použijte textový soubor, který obsahuje informace o slovíčkách (anglické, české, číslo lekce)


### Požadavky:  
- vhodně použijte projekt a vlastní hlavičkový soubor
- vytvořte vlastní funkce podle zadání
- nepoužívejte pole pro uložení sady slov ze souboru
- program pracuje se souborem, jeho název zadá uživatel v programu, předávejte soubor jako parametr do funkcí
- údaje pro jedno slovíčko jsou uloženy v souboru na jednom řádku, oddělené oddělovačem. Pro testování programu použijte určený textový soubor
- každý pojem v češtině nebo v angličtině nemusí tvořit jednotlivé slovo, ale může se jednat o slovní spojení (více slov)
- realizujte překladový slovník: program umožní přeložit zadané slovo (česky->anglicky, anglicky->česky)
- vytvořte pro uživatele testování ze slovíček z vybrané lekce: zobrazují se postupně všechna slovíčka ze zadané lekce, uživatel píše anglický překlad slov. Před zadáním čísla lekce se zobrazí seznam lekcí (bez opakování), aby uživatel věděl, jaké lekce jsou k dispozici
- testování uživatele ze slovíček, náhodně vybraných ze souboru. Uživatel zadá počet slov pro testování. Slova se neopakují. Vhodně použijte dynamické pole
- po každém testování vypsat statistiku (počet slovíček, počet správných odpovědí, procento úspěšnosti). Uživatel má možnost uložit statistiku do vlastního souboru
- program umožní přidat na konec souboru nová slovíčka. Uživatel nemůže uložit do souboru slovní spojení, které tam už je
- odstraní slovní spojení (řádek) ze souboru
- vytvořte vhodnou uživatelskou nabídku pro práci se souborem slovíček
- navrhněte vhodný způsob kontroly vstupních údajů a ošetření možných chyb při běhu programu, vlastní funkcí vyřešte problém velkých a malých písmen při zadávání
- použijte komentáře pro zpřehlednění a popsání kódu
- pro uživatele vytvořte popis aplikace
