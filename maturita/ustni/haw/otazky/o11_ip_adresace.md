---
layout: page
title: IP adresace a směrování v datových sítích
description: Otázka č.11 - IP adresace a směrování v datových sítích
has_children: false
nav_exclude: true
ip1: /assets/images/ip1.jpg
---
# IP adresace a směrování v datových sítích

## IP adresa
- SW adresa
- Jednoznačný číselný identifikátor, který je přiřazený každému zařízení v síti
- Označuje konkrétní umístění daného zařízení v síti
- 32 bit
    - Možno vygenerovat až 232 IP adresa (přes 4 miliardy)

## MAC adresa
- HW adresa
- Je pevně daná od výroby
- Přiřazena k siťové kartě (NIC)
- Využívá se při hledání hostitele v lokální síti

## Všesměrová adresa (broadcast)
- Adresa označující všechna připojená zařízení
- Obsahuje samé jedničky
    - FF:FF:FF:FF:FF:FF

## Prefix
- Počet bitů zleva, které identifkují síťovou část IP adresy
- Zapisuje se jako číslo za lomítkem po IP adrese
    - 192.168.0.20/**24**
- Prefix může být libovolné číslo od 0 do 32

## Maska sítě (podsítě)
- 32 bitová hodnota
- Umožňuje příjemci paketu rozlišit z IP adresy část NET ID a část HOST ID
![Maska]({{page.ip1 | relative_url}})

## VLSM
- Variable Length Subnet Mask
- Adresování s masou podsítí proměnné délky
- Umožnuje velkou podsíť rozdělit na několik podsítí různé velikosti
- Možno využít pouze s protokoly RIP, EIGRP a OSPF

## CIDR
- Classless Inter Domain Routing
- Zkrácený zápis masky
- Např. /24
- Využíváno u VLSM

### Třídní adresování - rpzdělení jednotlivých tříd
#### Třída A
- Slouží pro potřeby extrémně rozsáhlých sítí
- První bit prvního oktetu je vždy 0
    - 0xxx xxxx
- Rozsah třídy je 0 – 127
- Maska podsítě jako prefix je /8
    - 255.0.0.0
#### Třída B
- Slouží pro potřeby velkých a středních sítí
- První bit prvního oktetu je vždy 1 a druhý 0
    - 10xx xxxx
- Rozsah třídy je 128 – 191
- Maska podsítě jako prefix je /16
    - 255.255.0.0
#### Třída C
- Slouží pro potřeby malých sítí
    - Ale je přiřazována i větším sítím z důvodu šetření sítě A a B
    - První bit prvního oktetu je vždy 1, druhý také 1
        - 110x xxxx
    - Rozsah třídy je 192 – 223
    - Maska podsítě jako prefix je /24
        - 255.255.255.0
#### Třída D
- Využíváno pro multicastové vysílání
- Maska podsítě jako prefix je /32
    - 255.255.255.255
- 1. oktet je 224 – 239
#### Třída E
- Využíváno k výzkumným účelům a jako rezerva
- 1. oktet je 240 – 255

#### Zjíštění IP adresy sítě
- Logickým součinem IP adresy hosta a jeho masky
#### Zjíštění broadcastu (oběžník)
- Logickým součtem IP adresy hosta a inverzní masky (WILD CARD)
#### Zjíštění počtu hostitelů
- 2^počet nemaskovaných bitu -2
    - Nemaskovaný bit znamená tam, kde je 0
- Dvojka se odečítá z důvodu adresy podsítě a všesměrové adresy
#### Zjíštění počtu podsítí
- 2^počet maskovaných bitu -2
    - Maskovaný bit znamená tam, kde je 1
- Dvojka se odečítá z důvodu podsítě samých 0 nebo 1
#### Zjíštění velikostí bloku
- 256 je maska podsítě
- Prefixu /26 odpovídá velikost bloku 64
    - 256 - 192 = 64
#### Zjíštění platných podsítí
- Násobky velikosti bloku od 0 do dosažení masky
- Platné podsítě u prefixu /26 ( -> velikosti bloku 64)
    - 0, 64, 128, 192
#### Zjíštění všesměrové adresy podsítě
- Ta je určena vždy číslem, které předchází následující síti
- Všesměrová adresa prefixu /26 (velikost bloku 64)
    - .63, .127, .191, .255
#### Zjíštění platné hostitelské adresy
- Jdou dány čísly mezi podsítěmi
- Nutno však vynechat sekvence samých nul a jedniček
- Jedná se o čísla nacházející se mezi IP sítě a broadcastem
#### Rozdělelní na podsítě
- Možnost rozdělení sítě na několik nezávislých celků
- Není možné využít všechny IP adresy pro hosty
    - Jako například IP sítě nebo broadcast
- Protokoly, které pracují s třídním adresováním
    - RIP
    - IGRP

## Implementace VLSM
- Je nutné vědět, jak se masky skládají z velikosti bloku
- Velikost bloku nemůžeme stanovit jen tak by očko
    - Souvisí vždycky s maskou té dané sítě
- Počítání bloku je od 0
- Sítě se nesmějí překrývat
- První vždy začínáme od největší sítě

- příklad
    - Navrhni IP adresaci s použitím VLSM pro sítě
        - 192.168.10.0 třídy C
    - Pokud bychom chtěli síť rozšířit o další hostitelé, existují takováto řešení
        - Rozdělit novou sít mezi již existující a následně vytvořit síť novou
        - Využít zbylé místo prostoru pro novou podsíť a zbytek rozdělit mezi existující sítě
        - Změnit prefix

## Sumarizace
- Souhrnné cesty
- Jedná se o minimalizaci aktualizací mezi směrovači
- Dojde ke zmenšení směrovací tabulky
    - Rychleji nalezne cesty do vzdálené sítě
    - Zvýší přenosovou kapacitu a omezí výpočetní zátěž směrovačů
- Je nutná znalost velikosti bloků
    - Díky tomu můžeme zjistit masku sumarizační routy
    - Síťová adresa sumarizační routy vždy odpovídá první síťové adrese v bloku
