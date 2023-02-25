---
layout: page
title: Fyzická struktura pevných disků, charakteristika systému Windows 
description: Otázka č.14 - Fyzická struktura pevných disků, charakteristika systému Windows 
has_children: false
nav_exclude: true
mbr1: /assets/images/14_mbr1.jpg
mbr2: /assets/images/14_mbr2.jpg
mbr3: /assets/images/14_mbr3.jpg
ept1: /assets/images/14_ept1.jpg
ept2: /assets/images/14_ept2.jpg
zav: /assets/images/14_zav.jpg
gpt: /assets/images/14_gpt.jpg
diske1: /assets/images/14_diske1.jpg
diske2: /assets/images/14_diske2.jpg
parag: /assets/images/14_parag.jpg
win1: /assets/images/14_win1.jpg
win2: /assets/images/14_win2.jpg
raid0: /assets/images/14_raid0.jpg
raid1: /assets/images/14_raid1.jpg
raid01: /assets/images/14_raid01.jpg
raid10: /assets/images/14_raid10.jpg
raid3: /assets/images/14_raid3.jpg
raid4: /assets/images/14_raid4.jpg
raid5: /assets/images/14_raid5.jpg
raid6: /assets/images/14_raid6.jpg
dyn1: /assets/images/14_dyn1.jpg
dyn2: /assets/images/14_dyn2.jpg
---
# Fyzická struktura pevných disků, charakteristika systému Windows 
## Rozdělení disku na oblasti
- Logická struktura disku se vytváří pomocí vysokoúrovňového formátování
- Slouží k organizaci dat uložených na pevném disku
- Umožňuje jeden fyzický pevný disk rozdělit na více oddílů, které se v OS tváří jako samostatné
disky

## MBR – Master Boot Record
- Je to rozhraní mezi výrobcem HW a tvůrcem OS, který bývá umístěn vždy na stejném místě na
disku (záznam je uložen na CHS 001)
- Velikost 512B (první bajty na disku)
- Umožňuje rozdělit disk na
    - 4 primární oddíly (partition)
    - 3 primární a jeden rozšířený (extended partiton)
        - Rozšířený oddíl lze dále dělit na logické disky pomoci tabulek rozšířených
segmentů – EPT
- Součástí MBR je krátký programový kód a tabulka rozdělení disku na oblasti = PaT (partition table)
- MBR se vytváří při instalaci OS v části výběru, nebo tvorby oddílu, nebo programem diskedit
- MBR nevytváří výrobce disku, ale první instalovaný OS, případně boot manager nebo
specializovaný SW pro výrobu oddílu (Acronis, Paragon)

![MBR1]({{page.mbr1 | relative_url}})
![MBR2]({{page.mbr2 | relative_url}})
![MBR3]({{page.mbr3 | relative_url}})

## PaT - partition table
- Tabulka rozdělení disku na oblasti
- má místo pouze pro 4 záznamy – proto pouze 4 oddíly
- Jeden z oddílu je nastaven jako bootovací
- Programový kód obsažený v MBR (nebo nějaký Boot manager) zjistí na základě tohoto nastavení ze kterého dalšího místa (CHS) má číst zaváděcí záznam (Boot Record) systémového oddílu a zavede jej do OP a předá mu řízení
- Na toto místo vždy ukazuje začátek oblasti - START CHS

## EPT - Extended partition table
- V rozšířeném oddílu lze vytvořit více logických disků (každý logický disk má svoji EPT)
- Její funkce je ukázat na další EPT v rozšířené oblasti a propojit tak jednotlivá oddělení disku
- Počet tabule EPT je tolik, kolik je logických disků uvnitř rozšířeného oddílu

![EPT1]({{page.ept1 | relative_url}})
![EPT2]({{page.ept2 | relative_url}})

## Bootování
- Zavádění souboru OS z energeticky nezávislého média (HDD, CD, Flash, disketa) do operační paměti RAM
- Určení pořadí zaváděcích zařízení je potřebné nastavit v Setupu Biosu

## Zaváděcí záznam
- krátký program spouštěný při startu BIOSem
- Načítá tabulku oblastí a hledá aktivní oblast, ze které je spouštěn OS
- Zaváděcí záznam kontroluje schopnost zavedení disku, obsahuje dva skryté soubory IO.SYS a MSDOS.SYS
- Pokud tyto programy existují, počítač je při startu načte a spustí je

![ZAV]({{page.zav | relative_url}})

## GPT - Guid Partition Table
- Standart pro členění pevného disku na oddíly
- Nahrazuje starší MBR a umožňuje adresovat disky vetší než 2TiB = 2,2 TB
- Je součástí standartu UEFI, který v dnešní době nahrazuje BIOS
- Dělení disku pomocí LBA
- Umožnuje vytvořit více primárních oddílu (až 128 z čehož 4 jsou vyhrazené)
- Na konci disku je záložní kopie tabulky
- Nepodporuje ho WIN XP nebo 32 bit systém

![GPT]({{page.gpt | relative_url}})

## Struktura a popis PAT, EPT programem diskedit
- Program umožňuje editovat harddisk jak ve fyzickém, tak logickém módu (fyzicky upravuje na bázi úplných sektorů)
- Je nutný pro editaci PaT, a tedy pro úplnou editaci disku
- Defaultní nastavení zobrazuje sektory v hexa nebo ASCII kódu – RAW MOD
- Po zformátování disku by měly být všechny sektory nulové, při poškození mají zvláštní označení

![diske1]({{page.diske1 | relative_url}})
![diske2]({{page.diske2 | relative_url}})

## Acronis Disk Director
- Pokročilý a profesionální nástroj pro komplexní správu pevných disků
- Hlavní funkce:
    - Vytváření a odstranění diskových oddílů
    - Obnova zaváděcí stopy, nalezení ztracených clusterů
    - Obnova diskových oddílů – nechtěně smazaných, poškozených, po HW nebo SW chybě
    - Defragmentace
    - Podpora Win8

## Paragon Partition Manager
- Obdoba programu Acronis, také umožňuje snadné a spolehlivé rozdělení pevného disku
- Plně funkční nástroj je vhodný jak pro domácí, tak pro profi použití
- Umí konvertovat mezi formáty FAT32 – FAT16 – NTFS

![parag]({{page.parag | relative_url}})

## Správa disku ve Windows
- Ve Správě počítače nalezneme Správu disku
- Lze zmenšovat oddíly, vytvářet nové
- Lze nastavit sdílení disků
- Ve Win8 lze nastavit formátování NTFS a exFAT

![win1]({{page.win1 | relative_url}})
![win2]({{page.win2 | relative_url}})

## Programy pro údržbu a optimalizaci disku v OS
- CCleaner
    - Odstraňuje všechny nepotřebné a neplatné položky registrů
    - Čistí dočasní soubory
    - Nástroj pro odebrání programů ze systému
- TuneUP Utilities
    - Optimalizace výkonu OS
    - Defragmentace registrů
- Defraggler
    - Defragmentace vybraných složek, souborů, disků, volného místa
    - Prověřuje disk z hlediska chyb

## Diskové pole RAID
- Redundant Array of Independent Disks
- Zabezpečení proti selhání disků
- Data jsou ukládána na více nezávislých discích
- Technologie řadičů, která koordinovaně řídí přístup ke dvěma nebo více diskům současně za účelem zvýšení kapacity, bezpečnosti nebo rychlosti
- SW RAID
    - Běžné základní desky neobsahují RAID, jen něco, co dokáže SW RAID nadefinovat
    - Když se SW RAID rozpadne a nemůžeme nabootovat OS, nebudeme schopni jej opravit
- HW RAID
    - Má vlastní procesor a paměť
    - Pro OS se chová zcela transparentně jako jeden disk

## Typy RAID
- RAID 0 - stripping = prokládání
    - v podstatě se ani nejedná o RAID, protože neposkytuje ochranu
    - Data jsou rozložena do menších bloků a ty se střídavě ukládájí na různé disky
    - Dochází k vyšší rychlosti, jelikož disky pracují zároveň
    - Při selhání jednoho z disků, dojde ke ztrátě všech dat

![raid0]({{page.raid0 | relative_url}})

- RAID 1 - mirroring = zrcadlení
    - Nejjednodušší, ale nejefektivnější ochrana
    - Data se zapisují na dva disky současně
    - Při selhání jednoho z disků o data nepřicházíme
    - Zápis muže být pomalejší, protože se zapisuje na dva disky zárověň
    - Nevýhodou je poloviční kapacita

![raid1]({{page.raid1 | relative_url}})

- RAID 0 + 1
    - Kombinace RAIDu 0 a 1
    - Je potřeba 4 disky
    - Data se ukládají pomocí prokládání na dva disky (A a B) a ty samé data na disky (C a D)
    - Nevýhodou je výsledná kapacita, která je také poloviční

![raid01]({{page.raid01 | relative_url}})

- RAID 10 
    - Podobné jako RAID 0+1
    - Tady se ale data nejdříve zapisují na disky AB zrcadlově, to samé s disky CD, obsah AB a CD je prokládaný
    - Odolnější vůči výpadku dat a rychlejší obnova
    - Nevýhoda je výsledná kapacita, která je také poloviční

![raid10]({{page.raid10 | relative_url}})

- RAID 3
    - Jsou zapotřebí alespoň 3 disky
    - Jeden z disku je paritní
    - Při výpadku paritního disku se s daty nic nestane
    - Při výpadku neparitního disku probíhá rekonstrukce dat za pomocí paritního disku
    - Nevýhodou je opotřebení paritního disku kvůli neustálému přístupu

![raid3]({{page.raid3 | relative_url}})

- RAID 2
    - Složitější RAID 3
    - Data jsou stripována po bitech na jednotlivé disky
    - Zabezpečení pomocí Hammingova kódu
    - Lze rozpoznat a opravit chyby při čtení
    - Výhoda – zkrácení doby odpovědi při dlouhých přístupech na disk (Paralelní spouštění)
    - Nevýhoda – malá propustnost

- RAID 4
    - Data jsou ukládána po blocích místo po bitech
    - Paritní disk taktéž
    - Nevýhodou je opotřebení paritního disku kvůli neustálému přístupu

![raid4]({{page.raid4 | relative_url}})

- RAID 5
    - Jsou zapotřebí alespoň 3 disky
    - Kapacitu jednoho zabírají samo opravné kódy, které jsou uloženy na členech střídavě oproti RAID 4
    - Výhoda – lze využít paralelního přístupu k datům, protože data jsou rozprostřena na více disků -> čtení je rychlejší
    - Nevýhoda – pomalejší zápis (Nutnost výpočtu opravného kódu)
    - Je odolný pouze proti výpadku jednoho členu

![raid5]({{page.raid5 | relative_url}})

- RAID 6
    - Obdoba Raid 5, minimálně 4 disky
    - Používá (dva paritní disky) kapacitu dvou paritních disků, na níž je parita vypočtena rozdílným způsobem
    - Paritní data jsou opět rozložena střídavě
    - Výhoda – odolnost proti výpadku dvou disků
    - Čtení stejně rychle jako RAID 5, zápis je pomalejší
    - Je vhodný při použití 5 a více disků

![raid6]({{page.raid6 | relative_url}})

## Dynamické svazky ve Windows
- Dynamické svazky umožňují přizpůsobit velikost a přidat další volný prostor ze stejného disku nebo i z jiných fyzických disků
- Rozložený svazek může obsahovat maximálně 32 disků
- Dynamické disky podporují rozdělení na několik diskových oddílů, základní disky ne
**Vytvoření dynamického svazku**
- Start -> Správa PC
- Úložiště -> Správa disku

![dyn1]({{page.dyn1 | relative_url}})

- Výsledek je změna barvy u oddílů na disku

![dyn2]({{page.dyn2 | relative_url}})