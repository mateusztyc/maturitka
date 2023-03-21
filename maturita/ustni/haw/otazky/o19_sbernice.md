---
layout: page
title: Konstrukční uspořádaní PC - typy a charakteristiky sběrnic
description: Otázka č.19 - Konstrukční uspořádaní PC - typy a charakteristiky sběrnic
has_children: false
nav_exclude: true
---
# Konstrukční uspořádaní PC - typy a charakteristiky sběrnic
## Sběrnice
- Sběrnice je skupina signálových vodičů
- Slouří ke vzájemnému propojení CPU, OP a dalších zařízení (GPU, zvukovka, síťovka, řadič HDD)

![Obrazok](/maturitka/assets/images/o19/1.jpg)

## Typy vodičů sběrnic
- Řídící
    - Řízení komunikace
    - CLK, CS, CE, MEM read/write
- Adresové
    - Přenos adresy určitého zařízení (blok paměťi)
    - Šířka datové sběrnice je definována jako maximální velikost přenášené adresy
    - A+, A-
- Datové
    - Přenos dat
    - Počet vodičů sběrnice určuje, kolik dat je sběrnice schopná přenést najednou v 1 taktu
    - D+,D-

## Rozdělení sběrnic
- Paralelní sběrnice – PCI, PCI-x, ISA
- Sériová sběrnice – USB, PCI-express
- Interní sběrnice – ISA, PCI
- Externí sběrnice – USB, FireWare

## Základní parametry sběrnice
- Frekvence
    - Maximální frekvence, se kterou může sběrnice pracovat
- Šířka sběrnice
    - Dáno počtem vodičů, po kterých se data přenášejí
- Rychlost přenosu dat (propustnost)
    - Množství přenesených dat za jednotku času
- Přístupová doba
    - Střední doba čekání na uvolnění sběrnice

## Systémová sběrnice - FSB
- Front Side Bus
- Nejrychlejší sběrnice celého PC
- Fyzická obousměrná datová sběrnice, která přenáší veškeré informace mezi CPU a severním
můstkem

## Charakteristika paralelních sběrnic
- PCI
    - Paralelní, half-duplexní sběrnice (přenos oběma směry, ale ne zároveň)
    - Na rozdíl od ISA nemá adresní část oddělenou od datové
    - Vodiče slouží pro přenos dat i adres, adresa se posílá na začátku každé transakce
    - Podpora Plug & Play
    - 32 bit adresní sběrnice
    - Šířka přenosu 32 a 64 bit
    - Frekvence 33 MHz a 66 Mhz
    - Přenosová rychlost (propustnost) 133 MB/s nebo 266 MB/s
- PCI-X
    - Sběrnice pro rozšiřující karty
    - Náhrada za sběrnici PCI 2.3
    - Ztrojnásobená šířka datové sběrnice (64 bit), vyšší maximální frekvence (133 MHz)
    - Vysoká datová propustnost

![Obrazok](/maturitka/assets/images/o19/2.jpg)
![Obrazok](/maturitka/assets/images/o19/3.jpg)
![Obrazok](/maturitka/assets/images/o19/4.jpg)
![Obrazok](/maturitka/assets/images/o19/5.jpg)


- ISA
    - Pomalá sběrnice z roku 1984
    - Od ISA vznikla EISA
    - 16 bit datová sběrnice
    - 24 bit adresní sběrnice
    - Šířka přenosu 8 a 16 bitové verze
    - Frekvence 8 MHz
    - Přenosová rychlost 8 MB/s
- EISA
    - Nástupce MCA
    - EISA zachovává původní filozofii ISA, rozšiřuje ale počet datových a adresních linek
        - Datová i adresní 32 bit
        - Přenáší 8/16/32 bit adresu
    - Je zpětně kompatibilní s ISA
    - Synchronní sběrnice
    - Frekvence 8 MHz s důvodu kompatibility
    - Teoretická rychlost 33 MB / s
    - 4 řádky kontaktů místo 2 (ISA)
    - Má stejnou velikost jako ISA a stejné vývody (62 + 36) a má navíc ještě 59 vývodů umístěných mezi starými vývody ISA (při zasunutí do ISA sběrnice zůstanou nezapojeny)

![Obrazok](/maturitka/assets/images/o19/6.jpg)

- AGP
    - Accelerated Graphics Port
    - Určená výhradně pro připojení grafických karet (aby nezatěžovala ostatní sloty PCI)
    - Vznikla úpravou sběrnice PCI, je rychlejší, má vyhrazený kanál mezi slotem a CPU
    - Ve své podstatě se ani nejedná o sběrnici, nýbrž slot, protože do AGP lze připojit pouze jedno
    zařízení
    - 32 bit
    - 66 MHz / 133 MHz / 266 MHz
    - Přenosová rychlost se liší podle verze (od 266 – 2133 MB/s)

![Obrazok](/maturitka/assets/images/o19/7.jpg)
![Obrazok](/maturitka/assets/images/o19/8.jpg)


## Grafické srovnání sběrnic
![Obrazok](/maturitka/assets/images/o19/9.jpg)

## PCI EXPRESS
- Peripheral Component Interconnet Express
- Sériová (serio-paralelní) sběrnice
- Full duplex
- Základní modul sběrnice má jeden symetrický pár vodičů pro TX a druhý pro RX
- Existují 4 varianty (parametry pro PCI EXPRESS 1. x) :
    - X1    
        - Tunery
        - Propustnost 250 MB/s jedním směrem
    - X4
        - Řadiče
        - Propustnost 1 GB/s jedním směrem
    - X8
        - Grafické karty
        - Propustnost 2 GB/s jedním směrem
    - X16
        - Grafické karty
        - Propustnost 4 GB/s jedním směrem
    - Propustnost výše uvedeným typů se u PCI Expres 2.0 zdvojnásobila
- Princip přenosu, datový pár a lane
    - Pro přenos používá dva páry vodičů
    - Každý pár vodičů prování přenos jedním směrem s rychlostí 2,5 Gb/s (u verze 2.0 dvojnásobek)
    - Všechny čtyři vodiče, které tvoří dva páry (1 pár tam, 1 pár zpět), se nazývají LANE
    - Dva vodiče v každém směru tvoří uzavřenou proudovou smyčku, po kterých je možno přenášet data velmi vysokou rychlostí (nedojde k vyzařování signálu do okolí)
    - Přenosový rychlost cca 250 MB/s v obou směrech
    - Link tvoří datové páry (lane)
        - PCI x2 LINK znamená, že má dohromady 4 datové páry a 8 vodičů = 2 LANE
    ![Obrazok](/maturitka/assets/images/o19/10.jpg)
    ![Obrazok](/maturitka/assets/images/o19/11.jpg)
    - Číslo x1, x2,… v označení PCI expres znamená link
    ![Obrazok](/maturitka/assets/images/o19/12.jpg)
- Komunikace po PCI express
    - Není použitá klasická sběrnicová topologie, u které jednotlivé karty musí žádat o přístup
    na sběrnici a sdílet přenosové pásmo s ostatními zařízeními
    - Od všech konektorů vedou jednotlivé dráhy (lane) do přepínače (switch), který dokáže
    libovolné dvě dráhy propojit a vytvořit tak strukturu typu point-to-point
- Zařízení sběrnice PCI express
    - Root complex
        - Začátek sběrnice propojující sběrnice s mikroprocesorem a řadičem OP
        - Zajišťuje konfigurace celé sběrnice
    - Switch
        - Zajišťuje větvení a rozšiřování sběrnice PCI Express od Root complexu nebo
    switche k dalším zařízením
    - Bridge
        - Převod mezi PCI express a jiným typem sběrnice
    - Endpoint
        - Koncové zařízení, ke kterým proudí data
![Obrazok](/maturitka/assets/images/o19/13.jpg)

### Kompatibilita PCI express
- PCI express 2.0 je zpětně kompatibilní s PCI e 1
- PCI express 2.1 není kompatibilní s PCI e 1, protože bylo změněno napájecí napětí
- PCI express 3 je zpětně kompatibilní s předešlými verzemi
- Karty určené do sběrnice PCI e x1 je možné zapojit do všech širších PCI expres sběrnic x2,x4,x8 i x16
![Obrazok](/maturitka/assets/images/o19/14.jpg)
### Rozdíl mezi PCI, PCI-x, PCI express
- PCI a PCI-x jsou paralelní sběrnice a pracují v half-duplexním módu
- PCI expres je sériová sběrnice a je fullduplexní
- PCI-X je pro rozšiřující karty