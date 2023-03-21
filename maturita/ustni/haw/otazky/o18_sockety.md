---
layout: page
title: Konstrukční uspořádaní PC - sockety, chlazení, chipsety
description: Otázka č.12 - Konstrukční uspořádaní PC - sockety, chlazení, chipsety
has_children: false
nav_exclude: true
---
# Konstrukční uspořádaní PC - sockety, chlazení, chipsety
## Vnitřní struktura a popis jednotlivých částí základní desky
![Obrazok](/maturitka/assets/images/o18/1.jpg)
![Obrazok](/maturitka/assets/images/o18/2.jpg)
![Obrazok](/maturitka/assets/images/o18/3.jpg)
![Obrazok](/maturitka/assets/images/o18/4.jpg)
![Obrazok](/maturitka/assets/images/o18/5.jpg)

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

![Obrazok](/maturitka/assets/images/o18/6.jpg)

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
- Patice (socket) je konektor pro připojení CPU k základní desce
- Slot = konektor, do kterého se procesor staví
- Typ patice určuje typ použitého procesoru
- Mají podobný tvar, ale liší se počtem otvorů pro piny procesoru
- INTEL
    - LGA 1151
        - Skylake
    - LGA 2011
        - Core i5, i7
    - Socket 1150
        - Haswell
    - Socket 1155
        - Sandy Bridge
    - Socket 1366
    - Socket 1156
- AMD
    - Socket AM4
        - Ryzen
    - Socket FM2+
    - Socket FM1, FM2
    - Socket AM3+, AM3, AM2, AM2+
- Intel vs. AMD
    - LGA = plošky
    - PGA = piny (háčky)
    - Intel používá plošky
    - AMD používá hlavně piny, ale i plošky
    - Liší se jinou definicí TDP

## TDP a návrh chlazení
- Thermal Design Power
- Udává, jaký tepelný výkon zařízení může vydávat (trvaly tepelný výkon)
- Slouží k dimenzování výkonu chladiče
- Čím větší TDP, tím větší a výkonnější chladič potřebujeme
- **Pasivní chlazení**
    - Kovová nepohyblivá součástka, která má na sobě navařená žebra pro zajištění co největší plochy z důvodu předávání tepla okolnímu vzduchu
    - Vyrobeno z mědi nebo hliníku
    - Chladič je uchycen pomocí šroubků na základní desce, mezi CPU a chladičem je nanesena tenká vrstva teplo vodivé pasty, která zlepšuje přenos tepla
    - Heatpipe
- **Aktivní chlazení**
    - Aktivní chlazení je prováděno proudícím vzduchem
    - Proud vzduchu je obvykle vytvářen ventilátorem
    - Použito pro chlazení CPU, GPU, zdroje nebo pevných disků
    - pomocí aktivních chladičů se vytváří tzv. „tunely“, v principu jde o dosažení lepšího proudění vzduchu skříní (na přední části je jeden aktivní chladič, který nasaje vzduch do skříně, ten se zde ohřeje a zdrojem nebo dalším aktivním chladičem pod zdrojem je vysáván mimo skříň)
    - Ventilátor
        - 3-pinové - které dodávají konstantní napětí – třetí vodič je snímač otáček
            - V případě 3pinového konektoru potřebujete dražší chladič, který si reguluje otáčky v závislosti na teplotě mikroprocesoru.
        - 4-pinové - (PWM – pulse-width modulation)
            - Ty jsou napojeny na elektroniku desky, která pulzně reguluje otáčky ventilátoru v závislosti na teplotě.
            - Pak stačí jednodušší a levnější ventilátor

- Vodní chlazení, chlazení tekutým dusíkem, oxidem uhličitým, tekutým kovem

## Heat pipe
- Slouží k přenosu tepla z jednoho místa na druhé za pomocí pracovní látky
- Jde o uzavřený kovový válec, který je naplněný tekutinou
- Na jednom konci je zasazeny do zdroje tepla a na druhém do chladiče
- Po dosažení teploty, na kterou je nastaven se začne pracovní látka (čpavek, voda, alkohol)
odpařovat a proudí směrem k ochlazovanému místu, kde kondenzuje
- Proud par se dává do pohybu na základě rozdílných tlaků v místě výparníku (vyšší tlak) a v místě
kondenzátoru (nižší tlak)
- Návrat kondenzátu zpět ke zdroji tepla je zajištěn kapilárními silami v porézním materiálu, který
kondenzát nasává zpět ke zdroji tepla (pomocí knotu)
- Umožňuje, aby pracoval v poloze, kdy je kondenzát níže než výparník

![Obrazok](/maturitka/assets/images/o18/7.jpg)
![Obrazok](/maturitka/assets/images/o18/8.jpg)

### Rozdíl mezi heat pipe a dvoufázovým termosifonem
-  Termosifonové chlazení na rozdíl od heat pipe dokáže vyvinout velký průtok úzkým průřezem a
odvést tak značné množství tepla z velmi malé oblasti
- Vyžaduje dostatečný výškový rozdíl, neměnnou orientaci a stabilní podmínky

![Obrazok](/maturitka/assets/images/o18/9.jpg)

## Teplená ochrana procesoru
- Teplo, které CPU vyprodukuje je potřeba spolehlivě odvádět
- Pokud by došlo k poruše chlazení, mohlo by to mít pro CPU katastrofální následky
- Proto existují technologie, které mohou stav kritické teploty ovlivnit

### Tepelné ochrany - Technologie
- TCC = Thermal Control Circuit
    - Vkláda nulové cykly
    - Tepelná dioda, která se používá k regulaci otáček ventilátoru
    - Při překročení teplotního limitu je vysílán signál, který aktivuje CPU throtling
    - Výsledkem je snížení napětí a frekvence CPU
- EIST = Enhanced INtel Speed Technology
    - CPU mění za běhu dynamicky taktovací frekvenci a napětí podle zátěže
- Inteligent Power Capatibility
    - Inteligentní řízení spotřeby
    - Funkce, která napájí jednotlivé sub systémy pouze v případě potřeby
- Cool'n'Quiet
    - Používáno AMD
    - Pracuje podobně jako EIST od Intelu
    - Dynamická změna taktovací frekvence a napětí na CPU podle zátěže
- Turbo Boost
    - Umožňuje jednotlivým jádrům CPU běžet rychleji, než je jejich základní frekvence za předpokladu, že to okolnosti dovolují
    - Dochází ke zvýšení výkonu jedno i více vláknových operací

## Vliv zátěže a taktovací frekvence na spotřebu
- Při přetaktování se spotřeba jednotlivých komponent několikanásobně zvyšuje
- Je třeba zvolit zdroj s dostatečnou výkonovou rezervou
- S vyšší frekvenci stoupá výdej tepla

![Obrazok](/maturitka/assets/images/o18/10.jpg)