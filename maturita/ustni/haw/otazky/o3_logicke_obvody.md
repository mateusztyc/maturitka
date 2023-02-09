---
layout: page
title: Programovatelné a neprogramovatelné logické obvody
description: Otázka č.3 - Pogramovatelné a neprogramovatelné logické obvody
has_children: false
nav_exclude: true
plda: /assets/images/plda.jpg
pal1: /assets/images/pal1.jpg
pal2: /assets/images/pal2.jpg
---
# Programovatelné a neprogramovatelné logické obvody

### PLD - Programmable Logic Device
- Číslicový obvod, které lze konfigurací naprogramovat
    - Vytvářením/přerušováním propojek nebo zápisek do paměťových buněk
- Nahrazují kombinační a sekvenční logické obvody
    - Sestaveny z obvodů střední inteligence
        - Hradla, čítače, registry,…
- Slouží jako prostředek pro návrh a realizaci kombinačních a sekvenčních logických obvodů
- Funkce a rovnice lze vyjádřit pomocí součtu součinů booleovských proměnných
    - Disjunktivní forma
    - Implementace formou vhodného zapojení hradel
- Obvod má na čipu určité množství logických prvků, umístěných do maticové struktury
- Prvky lze vzájemně propojit pomocí konfigurovatelné propojovací sítě
- Několik desítek vertikálních a horizontálních vodičů
    - Jejich konfigurace pomocí programovatelných propojek v místě křížení vodičů
![PLDA]({{page.plda | relative_url}})
- **Výhody PLD**
    - Přehledné
    - Snížený počet pinů
    - Vyšší spolehlivost
    - Snadná modifikace
    - Vysoká výkonnost
- **Nevýhody PLD**
    - Nutnost znát programovací jazyk pro PLD
    - Při poruše je nutné vyměnit celý obvod
    - Vyšší cena
- #### Výrobci
    - Xilinx
    - Lattice
    - Altera
- #### Programovací jazky 
    - HDL
    - VHDL
        - Otevřený standart - není třeba licence
        - Umožňuje pracovat na návrhu, aniž je předtím zvolen cílový obvod (ten může být zvolen až v okamžiku, kdy známe požadavky)
        - Možnost provést simulaci navrženého na základě zdrojového kódu
    - Verilog

### Rozdělení PLD
- #### SPLD= SIMPLE PLD
    - Každá vodorovná čára v programovatelné matici AND představuje vždy jedno součinové hradlo
    - Na výstup každého hradla lze připojit libovolnou kombinaci vstupních signálů, zpětných vazeb a jejich negaci
    - Počet vstupů každého součinového hradla je omezen
    - Obvody typu PAL a PLA
    - GAL
    - **PAL**
        - Programable Array Logic
        - Oproti PLA nemají obvody součtovou matici a výstupy jsou fixovány do součtových hradel OR -> omezený počet vstupů
        - Přímo by bylo možné realizovat pouze funkce s maximálně 8 součinovými termy
        - ![PAL]({{page.pal1 | relative_url}}) ![PAL2]({{page.pal2 | relative_url}})