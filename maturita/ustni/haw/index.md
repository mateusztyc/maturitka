---
layout: page
grand_parent: Maturita
parent: Ústní maturita
title: Ústní maturita Hardware
description: Otázky, odpovědi, materiály k ústní maturitě z hardwaru
has_children: false
---

# [1.Programovací jazyk C](otazky/o1_jazykC/)
 - Datové typy
    - Definice vs. Inicializace
 - Přetypování
 - Standartní vstupy a výstupy
 - Řídící struktury
    - Větvení
    - Cykly
- Práce s polem
    - Jednorozměrné, dvourozměrné
    - Načtení, výpis, manipulace s prvky
- Algoritmy třídění pole
- Funkce
    - Popis a použití
    - Definice, tělo, prototyp
    - Bez parametru, s parametrem
- Struktury a ukazatele
- Práce se soubory
    - Typy souborů
    - Deklarace proměnných pro práci se souborem
    - Přístupové funkce
- Knihovny

# [2.Mikroprocesor](otazky/o2_mikroprocesor/)
 - Co je mikroprocesor a jeho obecný popis
    - Řadič, ALU
 - Rozdíl mezi mikroprocesorem a mikrořadičem
 - Charakteristika mikroprocesoru ARM STM32F4
    - Architektura
    - Velikost a typy paměti, registry
 - Popis
    - Portů
    - Čitačů/časovačů, včetně realizace časových smyček
 - Charakteristika školního kitu
    - Včetně použitých periferií
 - Konfigurace projektu a práce v prostředí Keil uV5

# [3.Programovatelné a neprogramovatelné logické obvody](otazky/o3_logicke_obvody/)
 - Charakteristika, vznik a rozdělení PLD
 - Popis dílčích PLD obvodů
    - PLA, PAL, GAL, CPLD, FPGA
 - Makrobuňka vs logický blok
 - Vývojové prostředí WebPack
    - PLD kompilátor
 - Charakteristika NPLD
 - Popis a využití vybraných obvodů
    - 74164, 74166, 74595, 74573, 74244, 74245, 74245, 74688, 74193

# [4.Přenos dat, rozdělení pamětí a jejich organizace](otazky/o4_prenos_dat/)
 - Sériový vs paralelní přenos dat
 - Princip připojení s otevřeným kolektorem
    - Včetně vytvoření sběrnice
 - Princip připojení s třístavovým zesilovačem
    - Včetně vytvoření sběrnice
 - Popis vybraných sběrnic
    - I2C, SPI, RS-232, IEEE 1284, USB
 - Rozdělení paměti v PC včetně jejich popisu
    - RWM vs ROM paměti
 - Organizace paměti
    - Kapacita, hloubka paměti, délka datového slova
    - Paměťová mapa

# [5.A/D převodníky](otazky/o5_ad_prevodniky/)
 - Charakteristika, pouřití, přesnost a princip převodu    
 - Analogový vs digitální signál
 - Popis a funkce převodníků
    - Paralelní
    - Přírustkový
    - S vratným čitačem
    - S postupnou aproximací
    - S dvojitou integrací
    - Sigma-delta

# [6.Operační systémy a plánování procesů](otazky/o6_os_a_procesy/)
 - Charakteristika OS
 - Typy jader OS
 - Proces vs vlákno
    - Charakteristika
    - PCB vs TCP
 - Přepínání kontextu
 - Plánovače OS
    - Preemptivní vs. nepreemtivní
 - Plánovací algoritmy
    - FCFS
    - SJF
    - SRTF
    - RR
    - PS 
    - MFQS

# [7.Synchronizace procesů](otazky/o7_synchro_procesu/)
 - Problém producent vs konzument
 - Kritická sekce
    - Charakteristika a podmínky pro ošetření KS
    - Aktivní vs pasivní čekání
 - Sdílený prostředek
 - Řešení KS
    - Zákaz přerušení
    - Zamykací proměnná
    - Přesné střídání
    - Petersonovo řešení
    - Atomická instrukce
    - Sleep() a Wakeup()
    - Semafory a transakce
 - Klasické synchronizační problémy

# [8.Řízení operační paměti](otazky/o8_rizeni_op/)
 - K čemu slouží OP a co se v ní nachází
 - Strategie přidělování OP
    - Souvislá oblast
    - Po blocích
    - Stránkování
    - Segmentace
    - Segmentace se stránkováním
 - Výpadek stránky, pre-cleaning, thrashing
 - Čisté vs špinavé stránky
 - Algoritmy výměny stránek
    - Optimální
    - FIFO
    - LRU
    - Druhá šance
    - Hodiny
    - NUR/NRU
    - Random
    - NFU

# [9.Řízení vnější paměti](otazky/o9_rizeni_vnejsi_pameti/)
 - K čemu slouží vnější paměť
 - Charakteristika HDD
 - Metody přidělování místa na disku
    - Spojité
    - Spojitý seznam
    - Indexová alokace
 - Plánovací metody přístupu na disk
    - FCFS
    - SSTF
    - SCAN
    - C-SCAN
    - LOOK
    - C-LOOK
 - HDD vs SSD
    - Defragmentace

# [10.Komunikace a rozdělení datových sítí](otazky/o10_datove_site/)
 - Základní pojmy a značky používámé při návrhu datových sítí
    - PAN, LAN, MAN, WAN
    - ISP, IoT, QoS
    - IP adresa vs MAC adresa
 - Způsoby komunikace v datových sítích
    - Unicast, Multicast, Anycast, Broadcast
 - Topologie datových sítí
    - Sběrnice, kruh, hvězda, strom
 - Popis protokolů
    - CSMA/CD, CSMA/CA, Token ring
 - Kabeláž
    - 10Base5, 10Base2, 10BaseT
    - Přímý vs křížený kabel
 - ISO/OSI model
    - Základní rozdělení a charakteristika každé z vrstev
    - Popis průchodů dat datovou sítí - od odesílatele k příjemci v rámci jednotlivých vrstev - (de)encapsulation
    - Srovnání s TCP/IP modelem

# [11.IP adresace a směrování v datových sítích](otazky/o11_ip_adresace/)
 - Třídní adresace
    - Rozdělení jednotlivých tříd
    - Vyhrazené IP adresy
 - Pojmy
    - IP a MAC adresa
    - Síťová adresa
    - Výchozí brána
    - Všesměrová adresa
    - Prefix
    - Maska (pod)sítě
    - VLSM
    - CIDR
 - Zjíštění
    - Počtu (pod)sítí
    - Všesměrové a síťové adresy
    - Velikost bloku
    - Wild Card
 - Návrh topologie sítí v rámci VLSM
 - Sumarizace
 - Charakteristika směrovače a směrovací tabulky
 - Statické vs dynamické směrování
 - Směrovací protokoly
    - RIP, IGRP, EIGRP, OSPF
 - Ukázka prostředí Cisco Packet Tracer

# [12.Unix](otazky/o12_unix/)
 - Charakteristika systému
    - Srovnání s MS Windows
    - Adresářová struktura
 - Uživatelský a programátorský interface
    - Základní příkazy
    - Roury
    - Tvorba skriptů
    - Systémové proměnné
    - Vrstvy
 - Použití a popis služeb
    - Telnet
    - SSH
    - FTP
    - DNS
    - DHCP
 - Virtualizace unixového prostředí na MS Windows

# [13.Fyzická struktura pevných disků, charakteristika a technologie](otazky/o13_disky_technologie/)
 - Princip magnetického záznamu a čtení dat, základní pojmy a charakteristiky HDD 
 - Geometrie HDD – stopa, sektor, cylindr
 - Vystavovací mechanizmy, teplotní kalibrace
 - Přístupová doba, kódování, prekompenzace, ZBR, MTBF, SMART
 - Technologie SMR, HAMR, MAMR

# [14.Fyzická struktura pevných disků, charakteristika sytému Windows](otazky/o14_disky_win/)
 - Rozdělení disku na oblasti, MBR, EPT, GPT – typy a odlišnosti, souvislost s instalací OS
 - Struktura a popis PAT a EPT programem diskedit
 - Programy pro správu disků Acronis disk director a Paragon Partition Manager
 - Adresování CHS a LBA, souvislost s BIOSem a UEFI při bootování
 - Vysvětlení EFI systém partition, vznik, obsah, souvislost s bootováním a instalací

# [15.Souborové systémy FAT a FAT32, NTFS a exFAT](otazky/o15_file_sys/)
 - Struktura logického disku, číslování sektorů, cluster
 - Zaváděcí záznam, hlavní adresář, typy FAT, struktura podadresářů
 - Rozdíly FAT, VFAT16 a VFAT32, řešení dlouhých názvů
 - Chyby FAT systému (programy k tomu určené a způsoby jejich odstraňování)
 - Bezpečné odstraňování dat, fragmentace a defragmentace disku
 - Charakteristika a vnitřní struktura NTFS, porovnání s FAT
 - Metasoubory a jejich funkce, struktura logického disku NTFS

# [16.Zdroje PC, BIOS, UEFI a proces bootování PC](otazky/o16_zdroje_bios/)
 - Typy zdrojů PC a jejich charakteristiky, konektory, zapojování, napětí, signály
 - BIOS a jeho součástí, možnosti upgrade
 - UEFI a rozdíly v bootování
 - CSM, Secure boot, TPM – popis, princip fungování
 - Proces výběru a zavedení OS, instalace OS přes UEFI

# [17.Konstrukční uspořádaní PC – typy paměti a jejich funkce v PC](otazky/o17_pameti/)
 - Popis funkcí pamětí PC a jejich vzájemné souvislosti – ROM BIOS, CMOS RAM, DRAM, SDRAM, DDR, DDR2, DDR3 a DDR4 (provedení, moduly, datové šířky, rychlosti, technologie přenosu dat, banky)
 - CACHE (HW,SW) – popis a princip činnosti
 - Časování pamětí (latence) a Dual Channel
 - Logická struktura operační paměti (Base, UMA, XMS)

# [18.Konstrukční uspořádaní PC – sockety, chlazení, chipsety](otazky/o18_sockety/)
 - Vnitřní struktura, popis jednotlivých částí základní desky, chipset
 - Typy a charakteristiky socketů Intel a AMD
 - Vliv zátěže na  taktovací frekvence na spotřebu
 - TDP a návrhy chlazení
 - Typy a charakteristiky chlazení procesorů, princip fungování Heat pipe
 - Technologie TCC (Thermal Control Circuit), EIST (Enhanced Instel Speed Technology), Inteligent capatibility, Cool’n’Quiet a Turbo boost

# [19.Konstrukční uspořádaní PC – typy a charakteristiky sběrnic](otazky/o19_sbernice/)
 - Pojem sběrnice a typy a charakteristiky paralelních sběrnic
 - Charakteristika sběrnic OSA, PCI, AGP, PCI-X (konektory, datové šířky, taktovací frekvence, přenosové rychlosti)
 - Sběrnice PCI Express, princip fungování, datový pár, Link, označení, kompatibilita
 - Verze a charakteristiky PCE-e sběrnic, kódování, přenosové rychlosti, souvislost s chipsetem

# [20.Konstrukční uspořádaní PC – typy a charakteristiky rozhraní](otazky/o20_rozhrani/)
 - Rozhraní EIDF, vznik, složení, komunikační módy, principy zapojování
 - Rozhraní Serial ATA, typy, charakteristiky, rychlosti, technologie NCQ (Native Command Quening), Stagged Spin-Up, Port Multiplier, Port Selektor, Hot Swap
 - eSATA, mSATA, M.2 – porovnání, přenosové rychlosti, konektory
 - technologie AHCI a NVMe, princip fungování
 - rozhraní USB – verze, konektory, přenosové rychlosti, kompatibilita
 - rozhraní Thunderbolt – verze, konektory, přenosové rychlosti, kompatibilita
