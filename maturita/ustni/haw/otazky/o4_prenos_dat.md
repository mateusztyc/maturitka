---
layout: page
title: Přenos dat, rozdělení pamětí a jejich organizace
description: Otázka č.4 - Přenos dat, rozdělení pamětí a jejich organizace
has_children: false
nav_exclude: true
image1: /assets/images/4_parametry_bus.jpg
image2: /assets/images/4_3stav_opamp.jpg
image3: /assets/images/4_otkolek1.jpg
image4: /assets/images/4_otkolek2.jpg
image5: /assets/images/4_i2c.jpg
image6: /assets/images/4_spi.jpg
image7: /assets/images/4_rs232.jpg
image8: /assets/images/4_rs232-1.jpg
image9: /assets/images/4_ieee1284.jpg
image10: /assets/images/4_mem_map.jpg
image11: /assets/images/4_delka_dat_slov.jpg
image11: /assets/images/4_hloub_mem.jpg
---
# Přenos dat, rozdělení pamětí a jejich organizace

## Sériový přenos dat
- Přenos dat probíhá postupně po jednotlivých bitech za sebou (sekvenčně)
- Sériová komunikace se používá na dálkových linkách a většině PC sítí, kde činí synchronizační potíže paralelní komunikace nepraktickou
- Sériová komunikace odstraňuje problémy paralelního přenosu jako například parazitní kapacity, přeslechy, synchronizace hodin
- Vylepšená technologie sériového přenosu učinila přechod od paralelní PCI sběrnice na PCI express, která je sériová
- USB, FireWire, SPI, Ethernet

## Paralelní přenos dat
- V jednom taktu lze přenášet více bitů najednou
- Zpočátku rychlejší než sériová, ale při vyšší frekvenci dojde k rušení
- Zpočátku využití pro tiskárny
- Sběrnice ISA, ATA, SCSI, PCI a FSB

## Paralelní vs. sériový přenos dat
- Rychlost
    - rychlost paralelního datového spojení = počtu bitů zaslaných najednou * přenosová rychlost každé jednotlivé linky
    - zdvojnásobení počtu bitů odeslaných najednou, zdvojnásobuje rychlost přenosu dat. V praxi hodiny snižují rychlost každé linky podle nejpomalejší z nich.
- Délka kabelu
    - omezení paralelního přenosu je dáno vzdáleností, protože kterékoli zpoždění na některém z drátů znamená nesrozumitelný znak při příjmu
    - to klade horní limit na délku paralelního datového spojení, které je obvykle kratší než sériové připojení.
- Složitost
    - paralelní datová spojení, jsou snadno realizovány v hardwaru, což je logickou volbou
    - vytvoření paralelního portu v počítačovém systému je poměrně jednoduché, vyžaduje pouze klopný obvod na kopírování dat na datovou sběrnici
    - v kontrastu, musí být většina sériové komunikace nejprve převedena zpět do paralelní podoby univerzální pomocí asynchronního přijímače/vysílače (USART), před tím, než může být připojen přímo k datové sběrnici.
- klesající náklady na výrobu integrovaných obvodů v kombinaci s větší poptávkou spotřebitelů po rychlosti a délce kabelu, vedlo ke kritice paralelního přenosu ve prospěch přenosu sériového
    - paralelní port IEEE 1284 vs. USB
    - Parallel ATA vs. Serial ATA
    - SCSI vs. FireWire

## Princip připojení s otevřeným kolektorem

![kompiler]({{page.image3 | relative_url}})

- Typ provedení výstupu, který se používá u integrovaných obvodů
- Výstup je tvořen jedním tranzistorem typu NPN – ten spíná výstup
    - Na výstup je přiveden kolektor tranzistoru
    - Emitor je spojen se společným potenciálem
- Použit Pull-Up rezistor, který zajistí, aby na výstupu sběrnice byla log 1 (z důvodu, aby se rozlišila chyba = kolizní stav)
- PODROBNĚ
    - Báze vstupního tranzistoru je připojená k logickému členu
    - Stav členu závisí na vstupních signálech
        - Tranzistor není sepnutý, kolektor není spojen s žádným potenciálem (logická úroveň L)
        - Tranzistor je sepnutý, výstup je spojen se zemí (logická úroveň H)
    - Pull-up rezistor je připojen k otevřenému kolektoru
- Otevřený kolektor umožňuje připojení zátěže s vyšším proudovým odběrem ve stavu, kdy je tranzistor sepnut
- Výstup nijak nezatěžuje sběrnici

![kompiler]({{page.image4 | relative_url}})

- Sběrnice může vzniknout v paralelním spojení obvodů s otevřeným kolektorem (propojením více obvodů na jednu linku = I2C)
- Komunikaci může zablokovat kdokoliv, kdo vnutí na sběrnici log 1
- Používá se tam, kde hrozí vysílání více zdrojů současně

## Princip připojení s třístavovým zesilovačem

![kompiler]({{page.image2 | relative_url}})

- Výstup obvodu má kromě stavu log 0 a 1 také třetí stav – vysoká impedance
- Výstup obvodu má kromě stavu log 0 a 1 také třetí stav – vysoká impedance
- Když jeden obvod vysílá, výstupy ostatních obvodů musejí být odpojeny (nezatěžují sběrnici)
- Používá se u systémových sběrnic v PC

## Sběrnice

![kompiler]({{page.image1 | relative_url}})

- Sběrnice je svazek vodičů, který propojuje jednotlivá zařízení nebo obvody mezi sebou
- Zajištuje přenos dat, adres a řídících signálů, popřípadě chybových hlášení
- Každá periferie v PC je připojená na nějakou sběrnici
    - Ty jsou přivedeny k severnímu nebo jižnímu mostu
        - Severní můstek
            - CPU, GPU, OP RAM
        - Jižní můstek
            - Ostatní periferie - HDD, mechanika, zvuková karta,...
- Rychlost samotné sběrnice podstatně ovlivňuje běh a rychlost celého systému
- Sběrnice můžeme rozdělit na 2 části
    - Lokální
        - Přímo připojená k mikroprocesoru nebo v ráci chipsetu
        - Nejrychlejší - FSB, QPI, DMI
    - Rozšiřující
        - Systémové
        - Umožňují připojení dalších komponentů
        - Pomalejší než lokální
        - Zakončeny slotem nebo portem
- Parametry a sběrnice
    - Šířka přenosu
        - Počet bitů, které lze po sběrnici současně přenášet
        - Bit
    - Frekvence
        - Maximální frekvence, s jakou může sběrnice pracovat
        - Hz
    - Přenosová rychlost = propustnost
        - Počet přenesených bitů za jednotu času
        - Bit/s (T/s)
    - Přístupová doba
        - Doba čekání na uvolnění sběrnice
        - Sekundy

## Rozdělení sběrnic
- **Řídící**
    - CLK, chip select, data read/write
- **Datové**
    - označeny například D0-D7
- **Adresní**
    - označeny například A0-A7
- Typy přenosu
    - Sériové/paralelní
        - **Sériové**
            - Jednotlivé bity jsou posílány za sebou v rámci CLK
            - RS 232
            - I2C, SPI
            - USB, FireWire
            - PCI express
            - SATA, eSATA
        - **Paralelní**
            - Všechny bity jdou současně s CLK
            - IEEE 1284 (LPT)
            - ISA, SCSI
            - PCI
            - PATA
    - Synchronní/asynchronní
        - **Synchronní**
            - Jeden CLK, který generuje master a posílá ho všem slave zařízením
            - I2C, SPI
        - **Asynchronní**
            - Každé zařízení má svůj CLK, v době přenosu se musí sesynchronizovat
            - RS 232
- Směr
    - **Simplex**
        - Může přenášet pouze jedním směrem
        - LPT
    - **Half duplex**
        - Může přenášet oběma směry, ale né současně
        - I2C
    - **Full duplex**
        - Může současně přenášet oběma směry
        - USB 3.0

## Sběrnice I2C

![kompiler]({{page.image5 | relative_url}})

- Inter Integrated Circuit od firmy Philips
- Vlastnosti
    - Dvou-vodičová = SDA a SCL
    - Obousměrná
    - Synchronní
    - Sériová
    - Externí
    - Half-duplex
    - Multi master a slave
- Pro připojení na sběrnici je potřeba výstup s otevřeným kolektorem
- Použití pro nízko rychlostní periferie
    - LCD, AD převodník, DA převodník, externí paměť
- Master-Slave
    - Master generuje CLK a řídí komunikaci
- V případě vysílání více zdrojů současně poskytuje detekci kolize a prevenci proti jejímu poškození
- Zařízení jsou adresovány, buď 7 nebo 10 bitová -> 128 nebo až 1024 zařízení
- Přenosová rychlost sběrnice v standartním módu je 100 kb/s (maximum 3,4 Mb/s)
- Princip přenosu
    - 1 obvod je master -> pakliže bude vysílat, všichni ostatní poslouchají
    - Ten, kdo chce vysílat nebo přijímat data musí nejdříve definovat adresu příjemce a určit, zda půjde o čtení nebo zápis
    - Druhé zařízení na základě adresy pozná, že jsou data pro něj a ozve se
    - V klidovém stavu je na sběrnici log 1 (díky pull-up rezistoru)
    - Přenos je zahájen START BITem (= změna úrovně vodiče SDA) -> přejde z 1 do 0
    - řenos dat je po 1B = 8 bitů
        - Od MSB po LSB
        - S jedním CLK přenese + bit
    - Hodnota SDA se mění, pokud je SCL v log 0
    - Ukončení přenosu pomocí STOP BITu, opět se změní hodnota SDA z 0 do 1 v tu chvílí, kdy bude SCL v 1
    - Je tam ACK, což je potvrzovací bit, který potvrzuje správnost
        - ACKNOWLEDGE BIT
        - Generuje se po každém 1 B příjemcem
        - Pokud je ACK v 0 = přenos je v pořádku
        - Pokud je ACK v 1 = opakuje se přenos dat

## Sběrnice SPI

![kompiler]({{page.image6 | relative_url}})

- Seriál Peripheral Interface od firmy Motorola
- Vlastnosti
    - Čtyř vodičová
    - Obousměrná
    - Synchronní
    - Sériová
    - Externí
    - Full duplenxí
    - Multi - slave
- Jednoduchá na správu
- Použití pro nízko rychlostní periférie (stejně jako I2C)
    - LCD, AD a DA převodníky, externí paměť
- Přenosová rychlost cca 1-66,7 Mb/s
- Master řídí komunikaci pomocí CLK a určuje, se kterým zařízením na sběrnici bude komunikovat pomocí CS = chip select
- Slave vysílá podle hodinového signálu
- Pouze 1 master -> nutno použít 4 vodiče

- MISO = Master in Slave Out
- MOSI = Master Out Slave in

## Sběrnice RS 232 - Sériový port (COM)

![kompiler]({{page.image7 | relative_url}})

- Full duplexní sběrnice
- Možnost připojit 2 zařízení
    - Vysílač
    - Přijímač
- Asynchronní přenos
    - Každý má svůj CLK, v době přenosu bitu se musí všechny sesynchronizovat
- Maximální vzdálenost 15 metrů
    - Čím větší vzdálenost, tím pomalejší komunikace
- Maximální rychlost 115200 Bd (baudů)
    - Modulační rychlost = počet změn stavu přenosového média za jednotku času
- Možnost použít různé kódování
    - např. ASCII
- Řízený přenos dat
    - HW
        - Vodiče sběrnice zabrání vysílání dat dříve, než je přijímač připraven
    - SW
        - Speciální znaky synchronizují komunikaci zařízení
- Datový rámec
    - START BIT, STOP BIT + paritní bit
        - Od LSB po MSB
        - Paritní bit(doplnění na sudou nebo lichou paritu)
        - 2 stop bity

![kompiler]({{page.image8 | relative_url}})


## Sběrnice IEEE 1284

![kompiler]({{page.image9 | relative_url}})

- LPT = Line Protector Terminal
- Paralelní port
    - Umožňuje přenášet více bitů v jednom CLK
- Původně byl simplexní = z PC ven, později half duplex
- Obsahuje 25 vodičů
    - 8 datových 
    - 9 řídících
    - 8 zemnících
- Maximální vzdálenost do 5 metrů (ideál 2m)
- Použítí u tiskáren

## Příklady dalších sběrnic
- Sériové 
    - RS 422 a RS 485 - kroucená dvojlinka
    - FireWire - kdysi konkurent USB
- Paralelní 
    - GPIB(IEEE 488)

## USB - Universal Serial Bus
- Slouží pro připojení nejrůznějších periferií k danému zařízení
- Nástupce RS 232
- Umožňuje
    - Přenos informací mezi 2 zařízeními
        - PC-mobil, PC-externí disk,...
    - Napájení zařízení
        - Lampy, větráčky, mobily, powerbanky
- Podpora Plug & Play
    - Možnost připojení za chodu a není nutný restart zařízení
- Hvězdicová architektura
    - V centru je vždy jeden HUB
- Možnost připojení až 127 zařízení
    - Každé má jedinečnou adresu

### Rozdělení USB
- USB 1.0
    - Čtyř pinový konektor 
        - 2x data, napáení a GND
    - Half duplex
    - Maximální teoretická rychlost 12 Mb/s
    - Konektory A a B
- USB 2.0
    - Zpětná kompatibilita
    - Half Duplex
    - MAximální teoretická rychlost 480 Mb/s
    - Mini A, Mini B
    - Micro USB
- USB 3.0
    - Zpětně kompatibilní 
    - Maximální teoretická rychlost 5 Gb/s
    - Full duplex
    - 8 vodičů
        - 6 datových
        - 2 napájecí

### Princip činnosti USB (jednoduše)
- Po sběrnici neustále kolují rámce – datové a servisní
- Hostitelský řadič vyšle USB paket, který obsahuje typ a směr přenosu, adresu zařízení
    - Konkrétní zařízení rozpozná svou adresu a připraví se k přenosu
- Zařízení vysílá datový paket (součástí je i kontrolní bit)
- Ukončení transakce nastane, když je vyslán handshake paket, který potvrdí úspěšnost přenosu

## Rozdělení paměti a jejich popis
- **Závislé na napájení (při odojení se data ztratí) = RWM**
    - READ WRITE MEMORY
        - RAM = random access memory (s nahodilým přístupem)
            - SRAM = statická
                - Cache
                - Dražší, rychlejší, menší kapacita
            - DRAM = dynamická
                - Operační paměť
                - Levnější, pomalejší, větší kapacita
                - V každé jedné paměťové buňce je kondenzátor (refresh)
                - Adresa je vystavována dvakrát
        - NoRAM (přímy přístup dat)
            - FIFO (fronta), LIFO(zásobník)
- **Nezávislé na napájení (po odpojení od zdroje data zůstanou) = ROM**
    - ROM
        - Jen pro čtení, naprogramování z výroby pomocí masky
        - Velká živnost
        - Použití pro firmwarerůzných zařízení
        - ROM BIOS
            - Paměť, ve které byl uložen BIOS (program spuštěný 1. na startu)
            - Nelze přepsat bežným způsobem (jen při zvýšeném napětí)
            - Nepotřebuje napájet
    - PROM
        - Programovatelná ROM (OTP = one time programable)
        - Použití u firmwaru
        - Umožňuje jeí programování
    - EPROM
        - UVE PROM
        - Mazatelná UV světlem
        - Nutno programovat přes speciální programátor
        - K její aktualizaci nutno smazat celou
    - E2PROM (EEPROM)
        - Elektricky mazatelná i přepisovatelná ROM
        - Firmware, PLD obvody pro konfiguraci
    - FLASH paměť
        - Nepotřebuje speciální programátor
        - Energeticky mazatelná, přepisovatelná
## Statická paměťová buňka - SRAM
- uchovává informace po celou dobu, kdy je připojená ke zdroji, po vypnutí se obsah smaže
- realizována jako bistabilní klopný obvod
- používá dva datové vodiče, jeden z nich je inverzní (hodnota na vodiči opačná než v paměti)
- pamět nepotřebuje periodickou obnovu (refresh jako u DRAM)
- používá se pro cache u procesoru (L1, L2, L3)
- má nízkou přístupovou dobu (1-20 ns)
- je dražší, má menší kapacitu, ale je značně rychlejší
- Tří stavy (klidový, zápis, čtení)
    - Klidový režim je stav, kdy buňka není zaadresována
    - **Zápis ‚1‘ do buňky**
        - Data = '1'
        - Data neg. = '0'
        - Aktivujeme adresu, tím že sepneme tranzistory pro zaadresování (T1,T2), adresa ‚1‘
        - Na bázi tranzistoru pro uchování informace T4 ‚1‘ (z data) a sepne ho, na collectoru T4 ‚0‘ (z data neg.), která se přenese na bázi T3 a rozepne ho -> stabilní stav
        - Na adresu přivedeme ‚0‘, buňka se odpojí od datových vodičů
        - (při zápisu ‚0‘ vše stejné, tranzistory se sepnou (rozepnou opačně)
        - (Při přivedení napětí se porovnávají T5 a T6, ten který je menší sepne opačný T3 nebo T4 (T5 < T6 -> T4 se sepne))
    - **Čtení**
        - Aktivujeme adresu
        - Na daných napětí se objeví napětí z tranzistorů
        - yž je T4 sepnutý, přivede napětí na DATA -> ‚1‘, T3 je přitom rozepnutý, tak na Data neg. Přivede ‚0‘
- Adresa každé buňky je tvořena řádkem (ROW select) a sloupcem (COLUMN select)
- Čtení/zápis je realizován přes 3- stavový zesilovač, pro zápis nutnost aktivního CHIP selectu

## Dynamická paměťová buňka - DRAM
- Energeticky závislá paměť, po odpojení od zdroje se data ztratí
- Informace uložená pomocí elektrického náboje na kondenzátoru
- Náboj má tendenci se vybíjet, i když je paměť připojena ke zdroji
- Aby se zabránilo ztrátě informací (způsobena vybitím C) je nutno periodicky refresh
- Vyšší přístupová doba (10 – 70 ns)
- Jednodušší na výrobu, levnější, má větší kapacitu
- Operační paměť PC
- ruovány do matice, 1 buňka se aktivuje pomocí 2 dekodéru (adresních vodičů)
    - 1024 x 1024 = 1 MB atd.
- Adresa řádků i sloupce se předává po stejné sběrnici
- K nastavení adres složí dva signály
    - RAS - Row Access Strobe = adresa řádku
    - CAS - Column Access Strobe = adresa sloubce
- Nutno nastavit oba
- **Zápis**
    - Na adresový vodič se přivede log. 1, tranzistor Q3 a Q2 se otevře (použitím většího napětí)
    - Na datovém vodiči je umístěná zapisovaná hodnota (např. 1)
    - Tato hodnota projde přes otevřený tranzistor Q3 a nabije kondenzátor C1 (zapamatování informace), pokud je na DATA Write log. 0, C1 zůstane vybitý)
    - V případě zápisu log. 0 dojde k případnému vybití C1, pokud byla dříve v paměti uložena log. 1
    - apětí na C1 se musí obnovovat (refresh)
- **Čtení**
    - Aktivujeme adresu (log 1)
    - Tranzistor pro čtení Q2 je sepnutý, ale tranzistor pro zápis Q3 zůstane rozepnutí, protože pro jeho sepnutí je potřeba vyšší napětí (kdyby byly sepnuty oba, bylo by napětí na C1 ovlivněno napětím z vodiče DATA write)
    - Kondenzátor C1 je nabitý a tím přivede log. 1 na bázi tranzistoru Q1, tím se sepne a na vodiči DATA Read se objeví napětí -> log. 1
    - Pokud kondenzátor není nabitý, Q1 se nesepne a na DATA read bude log. 0
    - Čtením se C1 vybije, a proto je potřeba ho znovu nabít

## Kapacita paměti
- Celkový objem dat, které lze do paměti uložit
- Počet paměťových buněk paměti
- Součin hloubky paměti a délky datového slova
    - 256 x 4 = 1024
- Udává se v bitech, nebo spíš bajtech

## Hloubka paměti

![kompiler]({{page.image12 | relative_url}})

- Počet adres, se kterýma je možno pracovat
    - Počet všech adres v paměti
    - Počet slov paměti -> jednotka: slovo
- Možnost rozšíření paralelním zapojením paměťových čipů

## Délka datového slova

![kompiler]({{page.image11 | relative_url}})

- Šířka datové sběrnice
- Počet bitů, které mohou být paralelně uloženy na adrese
- Řídí se délkou slova CPU
- Možnost rozšíření sériovým zapojením paměťových čipů

## Organizace paměti - paměťová mapa

![kompiler]({{page.image10 | relative_url}})

- Zápis kapacity paměti – hloubka a délka datového slova
16k(2k x 8)
- Informace je uspořádaná do N paměťových míst, které se označují jako slova s n bity
- Kapacita paměti = N * n
- Jedno z N slov je vybráno pomocí p-bitové adresy
    - N = 2p
- Počet adresových vodičů (p-bit adresa)
    - P = log N / log 2

## Obecně k pamětem (pro nahnání času)
- Paměť slouží k uchování a opětovnému vyvolání informace
- Jedná se o polovodičové moduly/obvody
- Složeny z paměťových buněk
    - 1bit = 1 paměťová buňka
- Maticové uspořádání
- Adresa
    - Zadávána binárně na adresní sběrnici (A0 – AN)
        - Popřípadě uvedena v hexa soustavě (0xFF)
    - Souřadnice řádku a sloupce
- Data
    - Datová sběrnice (D0 – DN)
- Paměťové místo
    - Nejmenší adresovatelná jednotka
    - Je dána adresou a počtem paměťových buněk, které jsou zde uloženy