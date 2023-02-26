---
layout: page
title: Konstrukční uspořádaní PC - typy paměti a jejich funkce v PC
description: Otázka č.17 - Konstrukční uspořádaní PC - typy paměti a jejich funkce v PC
has_children: false
nav_exclude: true
pam1: /assets/images/17_pameti1.jpg
ddr2: /assets/images/17_ddr2.jpg
ddr3: /assets/images/17_ddr3.jpg
porov: /assets/images/17_porov.jpg
cache1: /assets/images/17_cache1.jpg
lat: /assets/images/17_lat.jpg
scm: /assets/images/17_scm.jpg
dcm: /assets/images/17_dcm.jpg
log1: /assets/images/17_log1.jpg
log2: /assets/images/17_log2.jpg
---
# Konstrukční uspořádaní PC - typy paměti a jejich funkce v PC
## Typy a funkce paměti v PC
- Operační paměť v PC umožňuje čtení a zápis dat a slouží pro dočasné uložení zpracovávaných dat a spuštěných programů

## Základní parametry paměti
- Kapacita
    - Množství informací, které je možno do paměti uložit
- Přístupová doba
    - doba, kterou je nutné čekat od zadání požadavku, než paměť zpřístupní požadovanou informaci
- Přenosová rychlost
    - množství dat, které lze z paměti přečíst (do ní zapsat) za jednotku času
- Statičnost / dynamičnost
    - statické paměti: uchovávají informaci po celou dobu, kdy je paměť připojena ke zdroji elektrického napětí
    - dynamické paměti: zapsanou informaci mají tendenci ztrácet i v době, kdy jsou připojeny k napájení. Informace v takových pamětech je nutné tedy neustále periodicky oživovat, aby nedošlo k jejich ztrátě
- Destruktivnost při čtení
    - destruktivní při čtení: přečtení informace z paměti vede ke ztrátě této informace. Přečtená informace musí být následně po přečtení opět do paměti zapsána
    - nedestruktivní při čtení: přečtení informace žádným negativním způsobem tuto informaci neovlivní.
- Energetická závislost
    - energeticky závislé: paměti, které uložené informace po odpojení od zdroje napájení ztrácejí
    - energeticky nezávislé: paměti, které uchovávají informace i po dobu, kdy nejsou připojeny ke zdroji elektrického napájení
- Sekvenční přístup
    - před zpřístupněním informace z paměti je nutné přečíst všechny předcházející informace
- Přímý přístup
    - je možné zpřístupnit přímo požadovanou informaci
- Spolehlivost
    - doba mezi dvěma poruchami paměti

![Pam]({{page.pam1 | relative_url}})

## Paměti CMOS RAM, SRAM, DRAM podrobněji
### CMOS RAM
- energeticky závislá paměť na základní desce
- Uchovává svůj obsah i při vypnutí PC pomocí knoflíkového lithiového článku
    - Pouze data, žádné programy
- do paměti se dostaneme pomocí programu SETUP, kde ji můžeme editovat, spouštíme klávesovou zkratkou
- možnost vymazání paměti pomoci CLEAR CMOS na základní desce (zkrat jumperu) nebo vyjmutím baterie
- udržuje HW konfiguraci, rychlostní parametry HW, hesla a pořadí zavádění OS

### Drobné povídaníčko ohledně ujasnění rozdílu CMOS, ROM (BIOS)
- CMOS je malá paměť v každém PC, která slouží pro uložení nastavení počítače. Konfiguruje se pomocí SETUPu, což je utilita, kterou spouštíme tím, že po zapnutí PC (spojení PS-ON se zemi) stiskneme určitou klávesu (ta se liší od výrobce základní desky). Veškeré nastavení (povolení portu, nastaveni pořadí bootování, rychlosti,…) je uloženo právě v CMOS paměti
- BIOS je program, který provádí základní počáteční nastavení a konfiguraci PC. Řídí se údaji, které jsou uloženy právě v CMOS paměti, ale samotný program BIOS není uložen v CMOS
- BIOS byl kdysi uložen v ROM paměti (Read Only Memory), ale časem se ukázalo, že je zapotřebí jej čas od času inovovat, proto se používaly EPRO, ty jdou mazat světlem a programovaly se ve speciálním zařízení. Dnes je BIOS uložen v paměti typu FLASH, které se dají mazat i přepisovat elektricky

### SRAM - STATICKÁ RAM
- uchovává informace po celou dobu, kdy je připojená ke zdroji, po vypnutí se obsah smaže
- realizována jako bistabilní klopný obvod
- používá dva datové vodiče, jeden z nich je inverzní (hodnota na vodiči opačná než v paměti)
- pamět nepotřebuje periodickou obnovu (refresh jako u DRAM)
- používá se pro cache u procesoru (L1, L2, L3)
- má nízkou přístupovou dobu (1-20 ns)
- je dražší, má menší kapacitu, ale je značně rychlejší

### DRAM - DYNAMICKÁ RAM
- Energeticky závislá paměť, po odpojení od zdroje se data ztratí
- Informace uložená pomocí elektrického náboje na kondenzátoru
- Náboj má tendenci se vybíjet, i když je paměť připojena ke zdroji
- Aby se zabránilo ztrátě informací (způsobena vybitím C) je nutno periodicky refresh
- Vyšší přístupová doba (10 – 70 ns)
- Jednodušší na výrobu, levnější, má větší kapacitu
- Operační paměť PC
- Konstruovány do matice, 1 buňka se aktivuje pomocí 2 dekodéru (adresních vodičů)
    - 1024 x 1024 = 1MB atd.
- Adresa řádků i sloupce se předává po stejné sběrnici

## Technologie přenosu dat
### SDR - SINGLE DATA RATE
- Přenos se uskutečňuje pouze na jednu stranu CLK (naběžná/sestupná)
### DDR - DOUBLE DATA RATE
- Přenos se uskutečňuje na náběžnou i sestupnou hranu CLK
### QDR - QUAD DATA RATE
- Čtyřnásobnosti bylo dosaženo díky zavedení dvou nezávislých datových kanálů
- Jeden pro čtení a druhý pro zápis
- QPD = Quad Pumped Bus

## Počítání přenosové rychlosti
- množství dat přenesených komponentou
- b/s nebo B/s
- př. DDR 200 = PCI 1600
    - 200 znamená efektivní frekvenci = skutečná je 100, ale x2 (DDR) -> 200 MHz
    - Datová šířka modulu je 64 bit = 8 B
    - 200 MHz x 8 B = 1600 MB/s
    - Označení za PC (1600) udává přenosovou rychlost

### Paměťové moduly
### SIMM
- Používán u starších typů RAM
- 32 bit model
- U Intel Pentium musí být osazeny v párech, protože sběrnice byla 64 bit
- Řešením je modul DIMM
### DIMM
- Šířka přenosu 64 bit
- Má na obou stranách samostatné elektrické kontakty (SIMM byly zdvojené)
- 168 vývodů SDRAM
- 184 vývodů DDR SDRAM
- 240 vývodů DDR2 SDRAM, DDR3 SDRAM
### SO-DIMM
- Menší alternativa DIMM, z důvodu úspory místa (notebook)

## Operační pamět(RAM)
- Vnitřní paměť PC, kde jsou uloženy programy a data, se kterými uživatel pracuje
- Má krátkou přístupovou dobu a vysokou rychlost oproti vnější paměti – HDD
- Výrobci: HyperX, Kingston, Adata

## SDRAM - Synchronous Dynamic RAM
- Synchronní dynamická paměť
- Používá se v PC jako operační paměť
- Pracují synchronně s CPU
- Jsou rozděleny do banků
- Frekvence musí odpovídat systémové sběrnici
    - PC 66 – sběrnice s taktem 66 MHz
    - PC 100 – 100 MHz
    - PC 133 – 133 Mhz

## SDR SDRAM - Single Data Rate SDRAM
- První synchronní verze dynamické paměti RAM
- Přenos dat se uskutečˇuje pouze na jednu hranu CLK
- Nahrazena rychlejší DDR
- 3,3V

## DDR SDRAM - Double Data Rate SDRAM
- Rychlejší verze SDRAM, při stejné frekvenci dosahuje dvojnásobného výkonu
- Veškeré operace jsou synchronizovány s náběžnou i sestupnou hranou CLK
- SDRAM a DDR SDRAM jsou vzájemně nekompatibilní
- PC 1600 = DDR 200 – sběrnice s taktem 100 MHz (200)
- PC 2100 = DDR 266 – 133 MHz (266)
- PC 2700 = DDR 333 – 166 MHz (333)
- PC 3200 = DDR 400 – 200 MHz (400)
- Napájení 2,5 V
- 184 vývodů

## DDR2 SDRAM
- Standart vycházející z pamětí DDR
- Data jsou zapisována/čtena s nástupnou i sestupnou hranou CLK (jako u DDR)
- Vstupně výstupní část paměti pracuje s dvojnásobnou rychlostí oproti jejímu jádru
- Poskytuje dvojnásobnou přenosovou rychlost oproti DDR
- O 50 % menší spotřeba el. Energie
- Napájení 1,8 V
- DDR2 a DDR jsou vzájemně nekompatibilní
- Muže pracovat s dvojnásobnou frekvencí oproti jejímu jádru
- 240 vývodů

![DDR2]({{page.ddr2 | relative_url}})

## DDR3 SDRAM
- Standart vycházející z DDR2
- Data jsou přenášena s náběžnou i sestupnou hranou CLK (jako DDR a DDR2)
- Vstupně výstupní sběrnice pracuje se čtyřnásobnou rychlostí oproti jádru
- Poskytují vyšší přenosovou rychlost oproti DDR2
- Napájení 1,5 V
- O 30 % menší spotřeba než DDR2
- DDR3 a DDR2 jsou vzájemně nekompatibilní
- 240 vývodů

![DDR3]({{page.ddr3 | relative_url}})

## Porovnání DDR, DDR2 a DDR3

![Porov]({{page.porov | relative_url}})

- První představuje DDR paměti. Čipy jsou taktovány 200MHz a I/O buffer stejnou frekvencí, protože jsou data dodávány do řadiče (skrze "Data Bus") na náběžné i sestupné hraně, je efektivní frekvence 400MHz.
U těchto pamětí je počet spojení (banky) mezi čipem a I/O bufferem roven dvěma
- Druhý obrázek ukazuje, jak je dosaženo vyššího výkonu u DDR2. Frekvence paměťových čipů je stále
200MHz, I/O buffer pracuje ale rychleji na 400MHz. Zvýšení frekvence I/O bufferu by ale na vyšší výkon
nestačilo, je nutné dodat také dvojnásobné množství dat (bitů). Díky čtyřem spojením (bankům) čipů a
I/O bufferu (4n prefetch), je možné s využitím náběžné i sestupné hrany dosáhnout efektivního taktu
800MHz. Změna se tedy koná pouze na úrovni modulů, kde je nutné zdvojnásobit množství přenesených
bitů za jeden impulz.
- Poslední obrázek ukazuje DDR3, kde se opět změnilo to samé jako u DDR2 vůči DDR. Paměťové čipy stále
pracují na nízké frekvenci 200MHz, ale spojení (banků) I/O bufferu musí být opět dvakrát tolik (8n
prefetch). Frekvence I/O bufferu se také zvýšila, na 800MHz. Efektivní frekvence je tedy 1600MHz

## Paměťové banky
- Nejměnší jednotka paměti, která může výt do PC přidána/odebrána
- Velikost 1 banku je závislá na šířce datové sběrnice CPU
- Je nutné, aby šířka přenosu dat modulů v jednom banku byla stejná, jako šířka datové sběrnice
CPU

## Cache
- Je to mezisklad mezi různě rychlými částmi PC, který celkově urychluje tok dat při zpracování
- **SW CACHE**
    - Používá se jako vyrovnávací paměť pro pomalé vnější paměti – HDD
    - OS se snaží uchovávat informace, se kterými pracuje častěji, v rychlé OP a v případě
zápisu na disk ukládat v co nejvýhodnějším pořadí
- **HW CACHE**
    - Realizována paměťovými obvody
    - Použití u CPU a jeho podpůrných obvodech
    - Vyrovnává rozdíl mezi nepravidelným předáváním dat počítačem (sběrnicí) a pravidelným
    tokem dat do/z magnetické hlavy
    - V CPU ukládá kopie dat přetečených z adresy v OP
        - Pokud při čtení obsahu slova z adresy v paměti je tato položka nalezena v cache
        paměti, je její obsah přečten z cache, a ne z OP
    - **Interní (primární, L1) cache**
        - Paměť sloužící k vyrovnání rychlostí CPU a pomalejších pamětí
        - Integrována přímo na čipu CPU (paměť SRAM)
    - **Externí (sekundární, L2) cache**
        - Vyrovnávání rozdílu rychlosti
        - Osazena na základní desce CPU
        - Činnost řízena řadičem cache paměti

![CACHE1]({{page.cache1 | relative_url}})

## Latence paměti
- Latence = zpoždění paměti
- Udává počet taktů potřebný k různým operacím, které jsou prováděny v průběhu přístupu
k paměti
- tRCD
    - RAS to CAS Delay
    - Časová prodleva od okamžiku, kdy je vybrán řádek do doby, kdy je možné vybrat sloupec
    a potvrdit jej signálem CAS
- tCL
    - CAS Latency
    - Počet taktů potřebný k získání informace z pamětové buňky pote, kdy byl vybrán její
    sloupec
    - Největší vliv na rychlost paměti
- tRP
    - RAS Precharge Time
    - Počet taktů nutný pro ukončení přístupu k jednomu řádku paměti a pro zahájení přístupu
k řádku jinému
- tRAS
    - Active to Precharge Delay
    - Nejmenší počet taktů, po které musí být řádek aktivní, než může být opět deaktivován
    - Minimální doba, po kterou musí být signál RAS aktivní

![LAT]({{page.lat | relative_url}})

## Dual Channel
- technologie základních desek využívající paměti DDR, DDR2 a DDR3 SDRAM
- paměti pracují na 2 kanálech
- data se přenáší po 128 bitech (64bitů na každý kanál)
- minimalizují se doby, kdy není možné k paměti přistupovat
- teoreticky dvojnásobná přenosová rychlost (v reálu se nějaký čas spotřebuje na režii pamětí atd.)
- pro použití této architektury je potřeba:
    - podporující čipová sada (chipset)
    - paměťové moduly (DIMM) musí být zapojeny po dvojicích
    - oba moduly musí mít stejné parametry (kapacita, rychlost)
- DDR 200 = PC1600
    - single channel = 1600MB/s
    - dual channel = 3200MB/s
- DDR2 800 = PC2 6400
    - single channel = 6400MB/s
    - dual channel = 12800MB/s
- DDR3 1600 = PC3 12800
    - single channel = 12800MB/s
    - dual channel = 25600MB/s
- Single Channel Memory – obyčejné zapojení pamětí
![SCM]({{page.scm | relative_url}})
- Dual Channel Memory – zapojení do 2 kanálů, které spolupracují jako 1 velká paměť
![DCM]({{page.dcm | relative_url}})
- existuje i Triple Channel a Quad Channel

## Logická struktura operační paměti
- paměti musí být zpětně kompatibilní se starými programy a systémy (DOS)
- paměť se vnitřně dále dělí na části:
    - Konvenční paměť
        - 0 - 640kB (velikost 640kB)
        - do této části paměti je možný přístup i bez jakýchkoliv ovladačů
        - používá se při spouštění
        - dříve hlavní paměť v DOSu
    - UMA (Upper Memory Srea)
        - 640kB – 1MB (velikost 384kB)
        - tato část je vyhrazena pro HW a jeho ovladače (př. grafické karty)
        - je zde umístěn i BIOS a jeho součásti (př. program Setup)
    - XMS (Extended Memory)
        - nad 1MB (až 4GB)
        - hlavní paměť, která se používá až po načtení všech ovladačů a najetí do OS
![LOG1]({{page.log1 | relative_url}})
![LOG2]({{page.log2 | relative_url}})