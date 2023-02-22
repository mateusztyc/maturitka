---
layout: page
title: Programovatelné a neprogramovatelné logické obvody
description: Otázka č.3 - Pogramovatelné a neprogramovatelné logické obvody
has_children: false
nav_exclude: true
plda: /assets/images/plda.jpg
pal1: /assets/images/pal1.jpg
pal2: /assets/images/pal2.jpg
pla1: /assets/images/pla1.jpg
pla2: /assets/images/pla2.jpg
gal: /assets/images/gal.jpg
cpld: /assets/images/cpld.jpg
fpga1: /assets/images/fpga1.jpg
fpga2: /assets/images/fpga2.jpg
archi1: /assets/images/archi1.jpg
makrobunka: /assets/images/makrobunka.jpg
webpack: /assets/images/webpack.jpg
x74164: /assets/images/x74164.jpg
x74164x: /assets/images/x74164x.jpg
x74166: /assets/images/x74166.jpg
x74166x: /assets/images/x74166x.jpg
x74959x: /assets/images/x74595x.jpg
x74595x: /assets/images/x74595x.jpg
x74573: /assets/images/x74573.jpg
x74573x: /assets/images/x74573x.jpg
x74244: /assets/images/x74244.jpg
x74244x: /assets/images/x74244x.jpg
x74244: /assets/images/x74244.jpg
x74245: /assets/images/x74245.jpg
x74245x: /assets/images/x74245x.jpg
x74988: /assets/images/x74688.jpg
x74988x: /assets/images/x74688x.jpg
x74988xx: /assets/images/x74688xx.jpg
x74193: /assets/images/x74193.jpg
and: /assets/images/and.jpg
nand: /assets/images/nand.jpg
or: /assets/images/or.jpg
xor: /assets/images/xor.jpg
nor: /assets/images/nor.jpg
xnor: /assets/images/xnor.jpg
---
# Programovatelné a neprogramovatelné logické obvody

## PLD - Programmable Logic Device
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
    - **PLA**
        - Programmable Logic Array
        - Druh PLD určený k realizaci logických obvodů
        - Obsahuje sadu vzájemně propojených programovatelných polí AND, vedoucí k programovatelným polím OR, které mohou být případně doplněny za účelem vytvoření výstupu
        - mají 2N hradel AND pro N vstupních proměnných a pro M výstupů z PLA by mělo být M hradel OR, každé s programovatelným

    - ![PAL]({{page.pla1 | relative_url}}) ![PAL2]({{page.pla2 | relative_url}})

    - **GAL**
        - Generic Array Logic
        - malé programovatelné hradlové pole
        - inovace obvodu PAL
        - Možnost smazání a přeprogramování

    - ![GAL]({{page.gal | relative_url}})

    - **CPLD = COMPLEX PLD**
        - Obsahují více SPLD obvodů na jednom čipu s důvodu realizace složitějších funkcí
        - Počet makro buněk v řádek stovek
        - Většina pinů je univerzálních
        - Obvod COOLRUNNER

    - ![CPLD]({{page.cpld | relative_url}})

    - **FPGA = FIELD PROGRAMABLE GATE ARRAY**
        - Mají nejobecnější strukturu a obsahují nejvíce logiky => nejsložitější
        - Makro buňky jsou nahrazeny logickým blokem
        - Obsahují až 6 milionu hradel (AND)

        - ![FPGA]({{page.fpga1 | relative_url}})

        - Vstupně výstupní bloky (IOB) obsahují registry, budiče, multiplexory a ochranné obvody
        - Jednotlivé bloky (LB) jsou propojeny navzájem globální propojovací maticí (=GPM)

        - ![FPGA]({{page.fpga2 | relative_url}})

        - Některé signály sousedících bloků je možné propojit přímo bez použití GPM -> menší zpoždění a umožňují tak realizovat například rychlé obvody šíření přenosu, což je nezbytné pro sčítačky nebo násobičky
        - Kromě základních bloků IO a LB obsahuje většina FPGA obvodů rychlé synchronní statické RAM paměti a další specifické bloky (HW násobičky; PLL, DLL)
        - Využití extérní EEPROM
        - **Architektura FPGA**
            - IOB
                - Vstupně výstupní blok
                - Řídí tok dat mezi I/O pinem a vnitřní logikou
                - Možno zařadit zpožďovací obvod, paměťový člen
            - CLB
                - Configurable logic block
                - Paměťové členy, tabulky logických funkcí na principu RAM
                - Přidána logika pro zřetězení se sousedními CLB
            - Block RAM
            - Multiplier
                - Násobička
            - DCM – digital CLK manager, rozvod CLK ke všem CLB
            
            - ![ARCHI]({{page.archi1 | relative_url}})

### Makro buňka vs. Logický blok
- #### Makrobuňka
    - OLMG = OUTPUT LOGIC MACRO CELL
    - Možno vytvářet SLO
    - Základní části je D-klopný obvod
        - Doplněný o pomocná hradla
    - Skládá se z kombinatoriky AND OR hradel a klopného obvodu a v podstatě každá buňka může představovat malou booleovskou rovnici
    - V každé makro buňce může být vytvořena logická funkce s až 16 logickými součiny
    - Složení makro buněk dohromady nám dává logický blok
- #### Logický blok
    - Je základním stavebním prvkem technologie programovatelného hradlového pole
    - Bloky mužou obsahovat třeba budič nebo registr a jiné obvody
    - Logický blok v FPGA může být stejně jednoduchý a malý jako makro buňka, ale taky velký a komplexní, nicméně nejsou nic víc, než například pár tabulek logických funkcí nebo klopného obvodu
    - Logické bloky jsou nejběžnější architekturou FPGA a jsou rozloženy do pole logických bloků

    ![Makrobunka]({{page.makrobunka | relative_url}})

### Webpack
- ISE WEbPACK je sada nástrojů sloužící k překladu zdrojových kódů a syntéze FPGA konfigurace na základě popisu systému pomocí HDL jazyka
- Vstupy jsou nutné napsat ve formě, kterou je systém schopen převést na model této konstrukce
- Programování závislé na předchozích krocích. Jednotlivé kroky však nemusíme provádět postupně, prakticky stačí pouze spustit poslední krok, tj. programování (pomocí aplikace iMPACT). Systém již sám provede všechny potřebné kroky, které musí předcházet - tzn. syntézu a implementaci.
- Hlavním uživatelským rozhraním ISE Webpacku je Project Navigator, který zahrnuje design hierarchii, editor kódu a výstupní konzoli Všechny nástroje jsou přístupné přes stromové menu vlevo dole a nabízí tyto nástroje: 

![Webpack]({{page.webpack | relative_url}})

### PLD metodika návrhu
- Formální zápis
    - Určení vstupů a výstupů
- Popis problému
    - Funkční a přechodové tabulky, booleovské rovince, orientovaný graf, časové průběhy, minimalizace, schéma zapojení
- Simulace
    - Odhalení řady chyb
- Realizace

### PLD Kompilátor
- Umožňuje definovat návrh číslicového obvodu bez ohledu na konkrétní typ PLD, jež bude nakonec použit
- Převádí definice logických funkcí do implementačního prostřední konkrétního PLD
- Dříve výstupem soubor .jedec dnes .bit
    - Programuje se do konkrétního PLD přes LPT nebo USB
- Transformace zápisu včetně minimalizace
    - Zjednodušení návrhu
    - Doplněno optimalizací pro konkrétní PLD
        - Minimalizace vstupů, výstupu, makro buněk

## NPLD
- Funkce pevně daná při výrobě, nelze nijak upravit
    - HW řešení
- Vyskytují se v podobě integrovaného obvodu
- Jde o obvody složené z jednoduchých hradel a dokážou tak vykonávat nějakou složitější funkci
- Posuvné registry, záchytné registry, posilovač sběrnic, komparátor, čítač,…

### 74164
- 8 bitový posuvný registr
- Převádí sériovou informaci na paralelní
- Výstup je tedy 8 bitový paralelní a vstup sériový
- 8 kaskádově spojených D-klopných obvodů
- Se vstupem CLK se informace posune o jednu pozici
- Používá se jako převodník sériového kódu na paralelní (vysílací jednotka)
- Použití jako rozšíření počtu výstupů mikroprocesoru, kdy 1 pin CPU zabere, ale 7 nových se jich objeví
- Vstup A je pro zavádění dat (informace)
- Vstup B je povolovací (možnost blokovat data), povolen v 0
- Výstupy Qa – Qh
- CLK je hodinový signál a CLR smaže registry (aktivní v 0)

![74164]({{page.x74164 | relative_url}}) ![74164x]({{page.x74164x | relative_url}})

### 74166
- 8 bitový posuvný registr
- Převádí paralelní informaci na sériovou
- 8 bitový paralelní vstup
- 8 bitový sériový výstup
- 8 vstupů a 1 výstup
- Vstup je 8x D-klopný obvod
- Hradla typu Shift/Load = posuň informaci a načti ji (SH/\LD)
- CLK INH je pro pozastavení CLK (aktivní v 1)
- Pro celý převod je potřeba 9 CLK – 1 CLK na načtení a 8 CLK na výstup
- Používá se pro převod paralelní informace na sériovou například u přijímací jednotky nebo pro rozšíření počtu vstupů u mikroprocesoru

![74166]({{page.x74166 | relative_url}}) ![74166x]({{page.x74166x | relative_url}})

### 74595
- 8 bitový posuvný registr
- Má třístavový výstup (0, 1, vysoká impedance)
- Sériový vstup a paralelní výstup
- Vychází ze struktury 74164, plní stejnou funkci, jen má navíc třístavové zesilovače
- 1 sériový vstup, 8 paralelních výstupů
- Je tvořen RS obvody
- SRCLK je sériový clock
- Těsně před výstupem je 8 třístavových zesilovačů řízených OE
- Na výstupu je další registr, na kterém se zachytí stav posuvného registru a je řízen RCLK
- Použití ve světelné tabuli, rozšíření počtu výstupů v mikroprocesorech
![74595]({{page.x74595 | relative_url}}) ![74595x]({{page.x74595x | relative_url}})

### 74573
- 8 bitový záchytný registr
- Latch register = střadač
- 8 vstupů a 8 výstupů
- Má třístavový výstup
- Vstup LE v 1 slouží k uložení informace ze všech vstupů D-klopného obvodu, to způsobí propojení D-Q
- Na výstupech je možno aktivovat třetí stav
    - Vysoká impedance
    - Vstupem je \OE v 1, to však neovlivní uložená data v záchytných D-klopných obvodech
- Vstupy a výstupy jsou v páru
- Použití k rozšíření vnější paměti mikroprocesoru a rychlému zachytávání informací na sběrnici
![74573]({{page.x74573 | relative_url}}) ![74573x]({{page.x74573x | relative_url}})

### 74244
- Posilovač sběrnice
- Jednosměrný budič
- 4 vstupy a 4 výstupy
- Vstup je 3,3 nebo 5 V
- Třístavový výstup
- Řízen signálem OE (open enable)
- Z výstupu můžeme brát větší proud než je na vstupu (proudový zesilovač)
- Používá se k vytvoření adresní sběrnice (vysílač) a možnost spínat náročnější součástky
![74244]({{page.x74244 | relative_url}}) ![74244x]({{page.x74244x | relative_url}})

### 74245
- Posilovač sběrnice
- Oboustranný budič
- Vstup 3,3V nebo 5V
    - Výstup je pak opačný
- Výstup je třístavový
- 8 vstupů a 8 výstupů
- Převádí 3,3V na 5V nebo naopak
- Zesilovač pro datové sběrnice
- Umožňuje přenos dat oběma směry
- DIR přepíná směr převádění
- OE open enable
    - 0 funguje
- DIR1 z A do B
- DIR2 z B do A
![74245]({{page.x74245 | relative_url}}) ![74245x]({{page.x74245x | relative_url}})

### 74688
- 8 bitový komparátor
- 3 stavový výstup
- Složen z hradel XNOR
- Výstupy z XNORu se dále porovnávají v AND
- Výstup z ANDu se nakonec porovnává NAND
- Pokud jsou všechny vstupy stejné, výstup je 0
- Použití pro porovnávání 2 8bitových slov, nebo jako adresní dekodér (1 vstup pevně dány)
![74688]({{page.x74245 | relative_url}}) ![74688x]({{page.x74245x | relative_url}}) ![74688xx]({{page.x74688xx | relative_url}})

### 74193
- 4 bitový obousměrný čítač
- Kaskádové zapojení
- Možnost přednastavení vstupů
- Vratný čítač s předvolbou
- Složen ze 4 JK-klopných obvodů
- Má oddělené vstupy CLK pro čítání dolů a nahoru
- Použití pro čítač událostí / odpočet, pořadník
![74193]({{page.x74193 | relative_url}})

## Hradla
- ### AND
    ![AND]({{page.and | relative_url}})
- ### NAND
    ![NAND]({{page.nand | relative_url}})
- ### OR
    ![OR]({{page.or | relative_url}})
- ### XOR
    ![XOR]({{page.xor | relative_url}})
- ### NOR
    ![NOR]({{page.nor | relative_url}})
- ### XNOR
    ![XNOR]({{page.xnor | relative_url}})