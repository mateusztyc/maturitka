---
layout: page
title: Souborové systémy FAt a FAT32, NTFS a exFAT
description: Otázka č.15 - Souborové systémy FAt a FAT32, NTFS a exFAT
has_children: false
nav_exclude: true
struk: /assets/images/15_struk.jpg
chs1: /assets/images/15_chs1.jpg
chs2: /assets/images/15_chs2.jpg
struk1: /assets/images/15_struk1.jpg
struk2: /assets/images/15_struk2.jpg
struk3: /assets/images/15_struk3.jpg
---
# Souborové systémy FAt a FAT32, NTFS a exFAT
## Souborový systém
- Souborový systém je sada pravidel, podle kterých OS organizuje data na logickém disku
- Typy souborového systému: FAT12, FAT16, VFAT32, exFAT, NTFS

## Struktura logického disku
![struk]({{page.struk | relative_url}})

- Skládá se ze dvou hlavních oblastí
    - Organizační oblast
        - Boot Record
        - .1. FAT – Alokační tabulka (File Alocation Table)
        - .2. FAT
        - Root Directory
        - Vytvářejí se vysokoúrovňovým formátováním logického disku (přikaz format)
    - Datová oblast
        - Cluster- prostor pro soubory
    
## Číslování sektorů
- CHS – Cylindr Hlava Sektor
    - Číslování podle geometrie disku
    - Hlava a cylindr se čísluje od 0
    - Sektor se čísluje od 1
- LBA – Logical Block Addressing
    - Sektory na disku se číslují lineárně
    - Sektory se číslují postupně od 0 v jedné stopě za druhou
    - Sektor má velikost 512 B
    - Délka adresy je 28 bitu -> možné zaadresovat 2^28 sektorů

![CHS1]({{page.chs1 | relative_url}})
![CHS2]({{page.chs2 | relative_url}})

## Cluster
- Nejmenší adresovatelná jednotka na logickém disku, kterou může OS vyčlenit pro soubor (adresář)
- Velikost clusteru záleží na velikosti pevného disku a použitého typu FAT systému (12,16,32)
- Celkový počet sektorů lze vypočítat jako Kapacita logického disku/512B
- Počet sektorů v 1 clusteru lze vypočítat jako Celkový počet sektorů/2^32 (v případě FAT 32)
- Cluster se skládá z určitého počtu sektorů a obsahuje data souborů nebo adresářů
- Každý cluster má právě jeden jedinečný záznam ve FAT tabulce v datové oblasti
- Čísluje se od 2

## Zaváděci záznam = BOOT RECORD
- Skládá se ze dvou částí
    - Spouštěcí kód svazku
    - Blok parametrů disků
- Obsahuje krátký program spuštěný při startu PC BIOSem
- Jeho úkolem je načíst tabulku oblastí a najít aktivní oblast, ze které načte OS
- Vytváří se při rozdělení disku na oddíly
- Tvoří základ logické struktury, je součástí MBR
- Záznam je umístěný na začátku disku (CHS 001)

## Hlavní adresář = ROOT DIRECOTY
- Kořenový adresář obsahující informace o uložených souborech
    - Jméno souboru/adresáře
    - Přípona
    - Velikost
    - Datum a čas vytvoření, přístupu, editace
    - Atributy (vlastnosti pro čtení/zápis, skrytý soubor)
    - Číslo 1. clusteru, ve kterém soubor/adresář začíná
    - Kontrolní součet
- Nachází se za kopií FAT 1 (= FAT 2)

## FAT TABULKA
- File Alocation Table
- Od ní je odvozen název souborového systému
- Alokační tabulka
- Vytváří se High Level Formatem (vysokoúrovňové formátování)
- Obsahuje záznamy pro jednotlivé clustery
- Nachází se za Boot Recordem logického disku a jsou tam dvě (z důvodu bezpečnosti)
- 1 záznam tabulky nese informaci o jednom clusteru
    - Po naformátování to můžou být
        - 0 = cluster je volný, použitelný pro OS
        - BAD (FFF7h) = cluster je vadný, OS nebude tento cluster používat
    - Při ukládání souboru na disk se hodnota 0 v záznamu pro cluster přepíše na číslo dalšího clusteru, kde soubor pokračuje nebo na EOF (číslo větší než FFF8h) v případě, že se soubor vešel do jednoho clusteru nebo se jedná o poslední cluster souboru/adresáře

## Typy FAT
- Existují 3 typy FAT tabulek
    - 12 bit
        - Používán na disketách
        - Bez podpory podadresářů
        - Jeden záznam tabulky má šířku 12 bitu
        - Celkový počet záznamů v tabulce je 2^12
    - 16 bit
        - Podpora podadresářů
        - Jeden záznam tabulky má šířku 16 bitu
        - Celkový počet záznamů v tabulce je 2^16
    - 32 bit
        - Jeden záznam tabulky má šířku 32 bitu
        - Celkový počet záznamů v tabulce je 2^32
- VFAT
    - Podpora dlouhých jmén (delší než původních 8 znaku jmén a 3 znaky přípon)
- exFAT
    - vhodný pro flash disky, SSD disky
    - Počet sektorů ve svazku až 2^64 -1 (16 EiB)
    - Zvýšený výkon přidělování volného prostoru díky bitmapy
    - Podpora pro transakce
    - Clustery je možné označit jako špatné a tím zabránit zápisu na ně
    - Možnost až 255 znaků

## Rozdíl mezi FAT, VFAT16 a VFAT32
- První rozdíl je ve velikosti FAT tabulky 12/16/32 bit
- FAT umožnuje délku názvu v podobě 8 znaků pro název a 3 znaků pro příponu
- VFAT16 zavádí možnost dlouhých názvů souborů a 4 znaků pro příponu
    - Každý soubor s názvem delší než 8 znaků má pro sebe více záznamů v Root Directory
    - Nevýhodou je konstantní délka Root Dir, která může mít pouze 512 záznamů
- VFAT32 řeší tento problém umístěním hlavního adresáře (ROOT DIRECTORY) do 2. clusteru v datové oblasti a má variabilní délku (má delší Boot Record a větší FAT tabulku 32 bit)

## Řešení dlohých názvů
- U FAT 12 a FAT 16 je konvence 8.3, tzn 8 znaků pro název a 3 znaky pro příponu
- VFAT zavedl dlouhé názvy a 4 znaky pro příponu
    - Každý dlouhý název se rozloží na tolik položek adresáře, kolik tvoří podíl počtu znaků názvů/13 +1DOS ekvivalent
- VFAT 32 také podporuje dlouhé názvy a 4 znaků pro příponu, liší se tím, že umístil ROOT DIR do datové oblasti do 2. clusteru

## Struktura podadresářů
- Hlavní adresář (root dir) je vytvořen uživatelem nebo OS
- Podadresář je vytvořen uživatelem nebo OS v prvním volném clusteru
- Hlavní adresář (root dir) je umístěn v organizační oblasti
- Podadresář je umístěn v datové oblasti v určitém clusteru
- Hlavní adresář (root dir) má tzv. 0 velikost a atribut DIR
- Záznam pro cluster ve FAT se změní z 0 na EOF a podadresář vždy po založení zabere 1 cluster i když má v root dir 0 velikost)
- V tomto clusteru se ihned po založení vytvoří první dva záznamy
    - .a..
        - Tečka -> číslo 1 clusteru ukazuje na daný adresář (znovunačtení)
        - Dvě tečky -> číslo 1 clusteru ukazuje na nadřazený adresář (přechod o úroveň výš)

![struk1]({{page.struk1 | relative_url}})
![struk2]({{page.struk2 | relative_url}})
![struk3]({{page.struk3 | relative_url}})

## Záznam souboru na disk
- OS si ve FAT tabulce zjistí číslo 1. volného clusteru, od kterého muže začít soubor ukládat
- Do tohoto clusteru v datové oblasti uloží první část souboru
    - Pokud se tam vešel celý, zapíše do záznamu pro cluster ve FAT tabulce EOF
    - Pokud je větší než cluster, zjistí OS ve FAT tabulce číslo nejbližšího volného clusteru, kam může pokračování souboru uložit, záznam 0 ve FAT tabulce nahradí číslem clusteru, ve kterém bude soubor pokračovat a uloží další část souboru (tento proces se opakuje až do uložení celého souboru a v záznamu pro poslední cluster uloží OS EOF)
- Do hlavního adresáře uloží informace o jménu, příponě,… a číslo 1. clusteru, od kterého soubor začal ukládat

## Chyby FAT systém
- Ztracený cluster
    - Na cluster neodkazuje žádný jiný záznam ve FAT tabulce, i když v něm jsou data
- Překřížený cluster
    - Na jeden cluster ukazují dva záznamy ve FAT tabulce
- Poškozený FAT
    - Pokud je souboru přiřazen blok několika clusterů, avšak ukazatel v některém z těchto clusterů ukazuje na konec disku nebo oddílu
- Fragmentace
    - Fragmentovaný soubor je takový, který není uložený do řetězce clusterů následujících za sebou – je rozházený po disku (leží na několika různých cylindrech)
    - Takový soubor bude z disku načítán pomaleji
    - Program pro záchranu dat má menší šanci opravit případné chyby vznikající při zápisu správně
    - Fragmentace vzniká častým mazáním a zápisem nových souborů, které jsou delší než uvolněné místo po těch vymazaných
- Defragmentace
    - Defragmentace znamená, že program spojí jednotlivé fragmenty souboru do jednoho celku tím, že jej přesune na místo, kam se soubor vleze celý
    - Defragmentační programy:
        - V OS je to defragmentace
        - O&O Defrag, Diskeeper
    
## Mazání souborů z disků
- Je rozdíl mezi vhozením do koše a skutečným vymazáním souboru a bezpečným odstraněním souborů z disku
    - Vhození do koše pouze přesun souboru do složky KOŠ
    - Vymazání souborů znamená v OS přesání prvního znaku názvu souboru v adresáři znakem E5h
    - OS dále přepíše celý řetězec záznamů ve FAT tabulce číslem 0
    - Pro OS to znamená, že tyto clustery muže použít pro zápis, ale obsah souboru nadále zůstává v clusterech (v datové oblasti), dokud nedojde k jeho přepsání daty nově uloženého souboru
- Bezpečné odstranění dat – skartování
    - Neprovádí jej OS, ale specializované programy
        - WipeInfo, DiskWipe, Tune Up Shredder
    - Dojde nejen k vymazání prvního znaku názvu souboru, ale taky k odstranění celého záznamu názvu v adresáři a také k přepsání obsahu souboru novým obsahem
    - Metody skartování dat
        - Rychlá
            - Přepis 1x nějakým novým obsahem (0)
        - Bezpečné podle amerického MO
            - Přepis 3x nulou, 3x FFh a nakonec F6h a celý proces opakovat vícekrát
        - Gurmanova metoda – extrémně bezpečná, ale dost pomalá