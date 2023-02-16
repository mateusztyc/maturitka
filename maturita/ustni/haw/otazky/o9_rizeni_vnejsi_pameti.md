---
layout: page
title: Řízení vnější paměti
description: Otázka č.9 - Řízení vnější paměti
has_children: false
nav_exclude: true
---
# Řízení vnější paměti

## Účel vnější paměti
- vnější paměť slouží k trvalému ukládání informací (programy a data)
- Obsah ve vnější paměti se po vypnutí počítače neztratí (jako u RAM paměti)
- Procesor nemá přímý přístup k disku
- OS používá k přístupu do vnější paměti ovladače zařízení
- Data jsou organizována do souboru na základě souborového systému, který je použit
- Výhody
    - Nízke náklady
    - Energetická nezávislost
    - Nedestruktivní čtení
        - přečtení informace žádným negativním způsobem tuto informaci neovlivní
- Stálá paměť: HDD, SSD
- Výměnná paměť: disketa, CD, DVD, USB flash disk

## Charakteristika pevného disku - HDD
- Hard Disk Drive
- Pevný disk je zařízení, které slouží k trvalému nebo dočasnému ukládání dat (nainstalované programy, data, OS)
- Data se uchovávají pomocí magnetické indukce
- Výhodou je rychlé čtení dat, nízká cena a velká kapacita
- Nevýhoda je mechanické řešení -> snadné poškození
- Samotný disk je vyroben z nemagnetického materiálu
- Jeho povrch je pokryt vrstvou feromagnetického materiálu (oxid železa)
- Zápis a čtení dat (o.13)
- Organizace pevného disku (o.14,15)

## Metody přidělování místa na disku - spojité přidělování
- Nejjednodušší způsob přidělování místa na disku
- Souvislá alokace, kde každá soubor zabírá množinu sousedních bloků na disku
    - Přesně vím, kde soubor začíná a kolik místa v paměti zabere
- Pokud se najde moc velký soubor, který se nevleze, je nutná defragmentace, aby vznikl souvislý prostor pro uložení tohoto souboru
- Pokud se soubor v průběhu zvětší, musí se přeuspořádat soubory na disku
- Přístup na disk je přímý i sekvenční
    - Sekvenční přístup
        - před zpřístupněním informace z paměti je nutné přečíst všechny předcházející informace
        - **postupně prochází od začátku místo v paměti**
    - Přímy přístup
        - je možné zpřístupnit přímo požadovanou informaci
        - **vím, kde soubor začíná a kolik zabere -> uloží rovnou na dané místo v paměti**
- Výhodou je malý pohyb hlaviček (vystavovacího mechanismu), neboť na sebe bloky navazují
- Problém vzniká při vzniku nových souborů, protože dopředu nevíme, kolik zaberou místa
- Při přidělování volného místa se řídí alokační strategií (algoritmy)
    - FIRST FIT
        - Obsadí 1. volný blok, do kterého se proces vejde
        - Nejčastější a nejjednodušší na implementaci
    - BEST FIT
        - Obsadí nejvhodnější blok -> zůstane málo volného prostoru
    - LAST FIT
        - Obsadí poslední volný blok
    - WORST FIT
        - Neřeší nic, umístí se do největšího vyhovujícího volného místa

## Metody přidělování místa na disku – spojitá alokace (seznam)
- Odstraňuje nutnost souvislého prostoru na disku
    - Stačí nám znát začátek souboru a konec (EOF)
- Soubor je uložen do volných bloků tak, aby byly jednotlivé části souboru co nejblíže u sebe
    - Minimalizace pohybu hlaviček
    - Prázdné bloky se zbytečně nepřidělují (nic dopředu)
- Přístup je pouze sekvenční, neboť při ukládání není nutné znát jeho velikost -> potlačení vnější fragmentace
    - Po přidáním FAT tabulky je umožněn i přístup přímý -> nalezneme informace o nezávaznosti a konci souboru
- Velikost alokačního bloku je dána v závislosti na použitém systému a kapacitě disku
    - Alokační blok je cluster
- Čím menší bude alokační blok (cluster), tím jich bude více a tím vznikne i větší fragmentace
- Příliš velké alokační bloky způsobí, že část posledního bloku bude nevyužitá a tím vzniká vnitřní fragmentace
- Bez použití FAT tabulky se na konci souboru nachází ukazatel na blok, kde pokračuje
    - Po upgradu FAT tabulky ukazuje soubor do tabulky, ve které se nachází číslo, které odkazuje na další blok
    - Pokud je blok poslední, je ve FAT tabulce uloženo EOF (end of file)
- Využití v MS DOS a WIN95/96

## Metody přidělování místa na disku – indexová alokace
- Indexy všech bloků souborů jsou umístěny pohromadě v indexovém bloku
    - Každý soubor má svůj indexový blok
- Z počátku jsou samé -1, které jsou postupně nahrazovány čísly, jak jdou bloky za sebou
- Vhodné pro přímý i sekvenční přístup
- Při práci ze souborem je indexový blok nahrán do operační paměti
- Je složitější na realizaci oproti ostatním, ale rychlejší
- Využití v UNIXu
- Vzniká vnitřní fragmentace (blok není využitý celý)
- Potlačená vnější fragmentace
- Snaha mít soubory co nejblíž k sobě z důvodu minimalizace pohybu hlaviček
- Snaha o co nejmenší indexový blok
    - Spojová struktura
        - Jeden, nebo více bloků za sebou, aby se pokryl celý soubor
        - Příklad, když má blok velikost 2048B a každý ukazatel v něm by zabral 4 B -> 512 ukazatelů (2048/4) => 512 * 2 = 1024B jsme schopni pokrýt
    - Víceúrovňový index
        - Hlavní indexový blok je pouze odkazem na další indexové bloky -> ty ukazují na konkrétní část souboru
    - Kombinovaný přístup
        - Kombinace předchozích dvou metod
        - Malé soubory nepotřebují indexový blok, použijí místo odkazu

## Plánovací metody přístupu na disk
- Tři části
    - SEEK
        - Přesun hlavy nad požadovanou stopu (cylindr)
        - Způsobuje největší zpoždění
    - LATENCY
        - Otočení disku na začátek požadovaného sektoru
    - TRANSFER
        - Přesun dat z disku nebo na disk

### FCFS
- First Came, first serve
- První, který přijde, bude nejdříve obsloužený
- Nejpomalejší
- Jednoduchý na programování
- Vhodný pro lehčí zátež

|Pořadí|Pozice hl.|cesta|
|:-----|:---------|:----|
|1     |53        |0    |
|2     |98        |45   |
|3     |189       |85   |
|4     |37        |146  |
|5     |122       |85   |
|6     |14        |108  |
|7     |124       |110  |
|8     |65        |59   |
|9     |67        |2    |

### SSTF
- Shortest Seek Time First
- Požadavek, který je nejblíže k hlavičkám má přednost a bude obsloužen jako první
- Hrozí hladovění požadavků, které budou daleko od hlavy
- Není ideální
- Je to rychlá metoda pro krátké vzdálenosti

|Pořadí|Pozice hl.|cesta|
|:-----|:---------|:----|
|1     |53        |0    |
|2     |65        |12   |
|3     |67        |2    |
|4     |37        |30   |
|5     |14        |23   |
|6     |98        |84   |
|7     |122       |24   |
|8     |124       |2    |
|9     |183       |59   |

### SCAN
- Hlava jezdí ze strany na stranu (od kraje, ke kraji) a postupně obsluhuje požadavky
- Hlavička disku začíná na začátku a přesunuje se na konec, zatímco zpracovává požadavky, které jsou po cestě, pak se vrací zpět

|Pořadí|Pozice hl.|cesta|
|:-----|:---------|:----|
|1     |53        |0    |
|2     |37        |16   |
|3     |14        |23   |
|4     |65        |14+65|
|5     |67        |2    |
|6     |98        |31   |
|7     |122       |24   |
|8     |124       |2    |
|9     |183       |59   |

### CSCAN
- Varianta SCAN, která se liší v tom, že když hlavička dojede na konec, nevrací se zpět, ale přesune se opět na začátek (tam kde začal) a pokračuje ve zpracovávání

|Pořadí|Pozice hl.|cesta  |
|:-----|:---------|:------|
|1     |53        |0      |
|2     |65        |12     |
|3     |67        |2      |
|4     |98        |31     |
|5     |122       |24     |
|6     |124       |2      |
|7     |183       |59     |
|8     |14        |30(229)|
|9     |37        |23     |

### LOOK
- Upravená metoda SCAN
- Hlava začíná na jedné straně disku (na začátku) u prvního požadavku a jde směrem k poslednímu požadavku na druhý konec a zpracovává požadavky, které jsou po cestě
- Jakmile obslouží poslední požadavek, otočí se a jede zpět a vrací se tam, kde začal

|Pořadí|Pozice hl.|cesta|
|:-----|:---------|:----|
|1     |53        |0    |
|2     |65        |12   |
|3     |67        |2    |
|4     |98        |31   |
|5     |122       |24   |
|6     |124       |2    |
|7     |183       |59   |
|8     |37        |146  |
|9     |14        |23   |

### CLOOK
- Vylepšená metoda LOOK
- Hlava začíná na jedné straně u prvního požadavku a pohybuje se na konec k druhému požadavku, zatímco postupně zpracovává požadavky, které jsou po cestě
- Jakmile dorazí na poslední požadavek, přesune se opět na začátek disku (na další první požadavek) a proces se opakuje

|Pořadí|Pozice hl.|cesta|
|:-----|:---------|:----|
|1     |53        |0    |
|2     |65        |12   |
|3     |67        |2    |
|4     |98        |31   |
|5     |122       |24   |
|6     |124       |2    |
|7     |183       |59   |
|8     |14        |169  |
|9     |37        |23   |

## HDD/SSD

### HDD
- Větší přístupový čas -> pomalejší
- Větší spotřeba elektřiny kvůli pohyblivým součástkám
- Dochází k fragmentaci dat -> zhoršení výkonu
- Hrozí poruchy z důvodu mechanických součástí disku – plotny, hlavy, vystavovací mechanismus
- Magnetická vrstva, která je na plotnách disku se může při vibracích nebo nárazech poškodit
- Hlučnější

### SSD
- Kratší přístupový čas -> rychlejší
- Žádné pohyblivé mechanické součástky -> odolnější proti poškození
- Nedochází k fragmentaci dat
- Jedná se o integrovaný obvod
- Je dražší

## Fragmentace
- Fragmentovaný soubor je takový, který není uložený do řetězce clusterů následujících za sebou – je rozházený po disku (leží na několika různých cylindrech)
- Takový soubor bude z disku načítán pomaleji
- Program pro záchranu dat má menší šanci opravit případné chyby vznikající při zápisu správně
- Fragmentace vzniká častým mazáním a zápisem nových souborů, které jsou delší než uvolněné místo po těch vymazaných

## Defragmentace
- Defragmentace znamená, že program spojí jednotlivé fragmenty souboru do jednoho celku tím, že jej přesune na místo, kam se soubor vleze celý
- Defragmentační programy:
    - V OS je to defragmentace
    - O&O Defrag
    - Diskeeper