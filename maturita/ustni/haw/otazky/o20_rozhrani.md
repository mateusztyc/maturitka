---
layout: page
title: Konstrukční uspořádaní PC -typy a charakteristiky rozhraní
description: Otázka č.20 - Konstrukční uspořádaní PC -typy a charakteristiky rozhraní
has_children: false
nav_exclude: true
---
# Konstrukční uspořádaní PC -typy a charakteristiky rozhraní
## Rozhraní
- Zařízení zajišťující správný přenos dat a komunikaci mezi dvěma zařízeními
### Rozhraní PATA (neboli IDE)
- Paralelní 16 bitové ATA rozhraní
- 40 žílový plochý kabel = kšanda
- Výpočet přenosové rychlosti
    - Např. ATA 100
        - Datová šířka 16 b = 2B
        - Frekvence 25 MHz (DDR)
        - 25 x 2 (DDR) = 50 MHz (ef.) x 2 B = 100 MB/s
- Problémy paralelního přenosu jsou vysoké frekvence, délky kabelů a spojů
- Verze ATA:
    - ATA 1 – 512 MB, PIO 0-2 mód, DMA 0-2
    - ATA 2 – 8 GB, PIO 0-4, DMA 0-2
    - ATA 3 – 128 GB, podpora SMART
    - ATA 4 – UDMA 0-2, podpora ATAPI CD-ROM
    - ATA 5 – UDMA 0-4, 80 žilový kabel
    - ATA 6 – 144 PB
    - ATA 7 – UDMA 0-6, SATA

### Rozhraní EIDE
- Enhanced Integrated Device Electronic od Western Digital
- Vychází z IDE (ATA) a zachovává kompatibilitu a odstraňuje nedostatky rozhraní IDE
- **Patří pod ATA-2 standart**
- Poskytuje vyšší přenosovou rychlost než IDE a může komunikovat prostřednictvím režimu
    - PIO – Procesor Input Output (zatěžuje CPU)
    - DMA – Direct Memory Access
- K připojení IDE disku se používá 80 žílový IDE kabel, kde 40 vodičů vede signál a dalších 40 má za úkol stínit signál ostatních
    - 80 žilový kabel nutno použít od UDMA 4 (přenosová rychlost je 66,6 MB/s)
- IDE konektor slouží pro propojení se základní deskou a např. řadičem disků
    - Konektor pro připojení napájení
    - Jumper
        - Propojení kontaktů, které umožňuje nastavit chování disku vůči druhému disku
    připojeného ke stejnému IDE kabelu
- Master Slave Cable select
    - BIOS si na základě kabelu určuje, kdo je master a kdo slave, podle toho kde je zařízení připojeno
    - Černý = master
    - Šedý = slave (nezapojen)
    - Modrý – na nákladní desku

![Obrazok](/maturitka/assets/images/o20/1.jpg)

### Rozhraní FDD - floppy disk drive
- 34 pinový kabel

### Rozhraní SCSI - Small Computer System Interface
- Vysokorychlostní paralelní rozhraní pro servery
- ULTRA320 SCSI, ULTRA640 SCSI
    - Číslo udává max přenosovou rychlost v MB/s

![Obrazok](/maturitka/assets/images/o20/2.jpg)

### Rozhraní SATA
- Serial ATA s datovou šířkou 1 bit
- Výhoda je použití tenčích kabelů a vyšší rychlosti
- Je možné zvýšit frekvenci rozhraní tak, aby dovolilo přenášet dostatečné množství dat sériovým
způsobem
- Verze SATA    
    - SATA I.
        - Maximální rychlost 150 MB/s = 1,5 Gb/s
            - Odlišné kódování přenosu – 10 bitové
        - Standart SATA/150
        - Pouze 1 bit šířka, ale frekvence 1500 MHz
    - SATA II. = SATA 3Gb/s = SATA IO
        - Maximální rychlost 300 MB/s
        - Standart SATA/300
    - SATA III.
        - Maximální rychlost 600 MB/s
        - Standart SATA/600

![Obrazok](/maturitka/assets/images/o20/3.jpg)
![Obrazok](/maturitka/assets/images/o20/4.jpg)

### eSATA
- External SATA
- Během probíhajícího přenosu zatěžuje CPU minimálně, na rozdíl třeba od USB
- Oproti externím diskům s rozhraním USB 2.0 nebo IEEE1394 FireWire dokáže poskytnout plný
    výkon SATA a také podporu SMART
    - K tomu je zapotřebí pouze eSATA kabel, který se připojí k eSATA konektoru v PC, ke
kterému vede normální datový SATA kabel
- Konektor eSATA má lépe zpracovaný konektor kvůli častému připojování a odpojování disků
    - Až 500 zasunutí oproti klasickému SATA s 50 zasunutím
    - Délka kabelu až 2 metry

![Obrazok](/maturitka/assets/images/o20/5.jpg)

### mSATA
- Mini SATA
- Oznámen v roce 2009
- Má stejný výkon jako SATA
- Liší se konektorem

### SATA express
- Slibuje rychlost 1 GB/s (jedním směrem)
- Podpora PCI express
- Skládá se z multiplikovaného SATA a PCI express
- V současnosti mrtvá technologie
- Každý konektor SATA Express v sobě nese dva porty SATA 6 Gb/s a dvě linky PCI express
- K připojení potřebujete speciální kabel, disk pak může komunikovat se systémem buď přes SATA
nebo PCI express
- Postupně jej nahradil slot M.2
![Obrazok](/maturitka/assets/images/o20/6.jpg)
![Obrazok](/maturitka/assets/images/o20/7.jpg)

### SATA M.2
- Čtveřice PCI express linek, dvojce kanálu SATA 6 Gb/s, trojice kanálu USB, PCM audio
- Jedná se o univerzální konektor, k jehož funkcím je nutné přistupovat klíčováním

### Srovnání rychlostí SATA
![Obrazok](/maturitka/assets/images/o20/8.jpg)

### Technologie SATA II. a III. - NCQ
- Native Command Queuing
- Přirozené řazení požadavků
- Ponechává rozhodování o pořadí čtení dat na logice disku
- Posloupnost čtení dat si seřadí tak, aby k tomu potřeboval co nejméně otáček a přesunu hlav
![Obrazok](/maturitka/assets/images/o20/9.jpg)

### Technologie SATA II. a III. – HOT SWAP
- Dovoluje připojit a odpojit disk za běhu počítače tak, aby je OS rozpoznal

### Technologie SATA II. a III. – Staggered Spin Up
- Po startu PC minimalizuje energetické nároky na zdroj
- Dokáže řídít a ovládat postupný náběh všech HDD, takže nemusí rozběhnout všechny najednou

### Technologie SATA II. a III. - Port Selector
- Umožňuje připojit dva řadiče k jednomu disku kvůli zamezení výpadku v případě poruchy jednoho z nich

### Technologie SATA II. a III. – Port Multiplier
- Slouží k tomu, abychom mohli s jedním řadičem obsloužit více pevných disků
![Obrazok](/maturitka/assets/images/o20/10.jpg)

### Technologie AHCI
- Advanced Host Controler Interface
- Univerzální rozhraní pro komunikaci se SATA řadiči
- HW vrstva mezi čipsetem a SATA zařízením
- Jeho účelem je umožnit komunikaci mezi SW a SATA disky či mechanikami na úrovni, kterou PATA
řadiče nedokáží
- Charakteristika
    - AHCI nabízí metodu pro detekci, konfiguraci a programování SATA/AHCI adapterů
    - AHCI oddělen od SATA 3 Gb/s, ačkoliv obsahuje pokročilé schopnosti SATA (NCQ, Hot
Swap)
- Zpětná kompatibilita
    - Mnoho SATA řadičů nabízí režimy provozu PATA, AHCI nebo RAID
    - V IDE módu jsou podporovány max. 4 zařízení
    - PCI IDE podporuje hlavní a vedlejší kanál se dvěma zařízeními na kanál

### Technologie NVMe
- Rozhraní pro komunikaci mezi flash pamětí a jejím řadičem
- Navrženo pro využití hlavních výhod flash pamětí oproti mechanickým diskům
- Optimalizováno pro maximální využití nízké latence a vysoké propustnosti dat
- Operuje na HW ovladači a zařizuje komunikaci mezi SSD diskem a CPU
- Procesor komunikuje s diskem přímo, nepotřebuje k tomu řadič, tudíž zcela odpadá zpoždění na
řadiči a jeho ovladači
- Narůst 7x přenosové kapacity 3x se snížila latence (zpoždění)
- Technologie vyvinutá speciálně pro SSD disky připojené PCI expres rozhraním
![Obrazok](/maturitka/assets/images/o20/11.jpg)

## SAS rozhraní = Serial Attached SCSI
- Pokračovatel SCSI sériového rozhraní
- Použití u nejvýkonnéjších serverových disků
- Konektor se podobá SATA
- Datová propustnost 4,8 GB/s
- Rychlost 12 Gb/s

![Obrazok](/maturitka/assets/images/o20/12.jpg)

## FIREWIRE - IEEE1394
- Vysokorychlostní sériová sběrnice od Apple k propojení externích SSD disků
- Rychlost 800 Mb/s

![Obrazok](/maturitka/assets/images/o20/13.jpg)

## USB
- Universal Seriál Bus
- Sériové rozhraní
- Nezávislé na platformě
- Přenos dat v reálném čase
- Možnost napájení z konektoru
- Komunikace do 5 metrů s využitím kroucené dvojlinky
- Až 127 připojených zařízení (max 7 HUBU)
    - Každé zařízení má přidělenou jedinečnou adresu
    - Získána po připojení ke sběrnici
    - Během inventarizace sběrnice
- Využívá vrstvenou hvězdicovou architekturu
    - Založena na USB rozbočovačích = HUB, zároveň pracuje jako repeater – zesiluje signál
- Jedná se o řízenou sběrnici
    - Datové přenosy inicializuje hostitelský řadič spolu s OS
    - Žádné 2 USB zařízení spolu nemohou komunikovat přímo
- Podpora Plug & Play
    - Možnost připojení za chodu, není nutný restart
    - Známe ovladače se instalují automaticky
- Konektory
    - Typ A
    - Typ B - tiskárna
    - Typ MINI - foťák
    - Typ MICRO
    - Typ C
- 4 výhody
    - .+ 5V červená
    - Data- bílá
    - Data+ zelená
    - GND černá
- Verze USB
    - 1.X
        - 1996
        - Teoretická propustnost max 12 Mb/s (full speed)
        - Low speed – 1,5 Mb/s
        - Half duplex
            - V jednom okamžiku jdou data buď přijímána, nebo vysílána
        - Bez podpory prodlužovacího kabelu
        - Čtyř pinový konektor
        - Konektory A, B
    - 2.0
        - Navýšení rychlosti
        - Half duplex
        - Zpětná kompatibilita s USB 1. x
        - Nejvyšší rychlost 480 Mb/s
            - Díky omezení přístupu ke sběrnici je možné dosáhnout rychlosti 280 Mb/s
        - Konektory A, B, Mini, Micro
    - 3.0
        - Full duplex
            - Data jsou současně vysílána i přijímána
            - Zpětně kompatibilní s USB 2.0
            - Teoretická propustnost max 4,8 Gb/s
            - 8 vodičů  
                - 6 datových
                - 2 napájecí
            - Reální přenosová rychlost bývá sotva poloviční
            - Max 900 mA
- Napájení u USB
    - Hub dodává 4.75 – 5.25V
    - Zařízení odebírá max 100 mA
- Organizace USB
    - One master, tj PC, veškerá aktivita vychází z něj
    - Zařízení může zahájit přenos jen po vyzvání
    - USB 1.0 a 2.0 poloviční duplex
    - USB 3.0 plný duplex – lze komunikovat v obou směrech současně
- Kompatibilita USB
    - Pokud bude třeba připojit zařízení USB 2.0 ke konektoru USB 3.0 na PC, bude vše v pořádku, opačně však všechny nové konektory do staršího USB 2.0 připojit nepůjdou
    - Zpětná kompatibilita je zajištěna tak, že konektor USB 3.0 "obsahuje" zachovaný starý konektor USB 2.0, do kterého lze zařízení USB 2.0 i připojit.
    - Obráceně to však již nepůjde u všech typů konektorů
![Obrazok](/maturitka/assets/images/o20/14.jpg)
![Obrazok](/maturitka/assets/images/o20/15.jpg)
![Obrazok](/maturitka/assets/images/o20/16.jpg)
![Obrazok](/maturitka/assets/images/o20/17.jpg)

## Thunderbolt
- Rychlé HW rozhraní umožňující připojit k PC periferie přes rozšiřující sběrnici
- Vyvinut společnosti INTEL s technickou spolupráci firmy APPLE
- Thunderbolt spojuje PCI express a DisplayPort do sériového datového rozhraní
- Specifikace:
    - Využívá rozhraní PCI express 2.0 x4 (max 16 Gb/s)
    - Propustnost po jednom kabelu 10 Gb/s
    - Řadič zvládne až 40 Gb/s
    - Odezva 8 ns
    - Max výkon 10 W
    - Lze připojit až 7 zařízení na jeden port
    - Maximální délka kabelu je 3m