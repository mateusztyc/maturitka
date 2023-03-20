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

![Obrazok](https://mateusztyc.github.io/maturitka/assets/images/o19/1.jpg)

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
![Obrazok](https://mateusztyc.github.io/maturitka/assets/images/o19/2.jpg)
![Obrazok](https://mateusztyc.github.io/maturitka/assets/images/o19/3.jpg)
![Obrazok](https://mateusztyc.github.io/maturitka/assets/images/o19/4.jpg)
![Obrazok](https://mateusztyc.github.io/maturitka/assets/images/o19/5.jpg)

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

![Obrazok](https://mateusztyc.github.io/maturitka/assets/images/o19/6.jpg)