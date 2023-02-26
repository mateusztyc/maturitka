---
layout: page
title: Zdroje PC, BIOS, UEFI a proces bootování PC
description: Otázka č.16 - Zdroje PC, BIOS, UEFI a proces bootování PC
has_children: false
nav_exclude: true
konektory: /assets/images/16_konektory.JPG
tolerance: /assets/images/16_tolerance.JPG
atx: /assets/images/16_atx.jpg
konk: /assets/images/16_konk.jpg
spot: /assets/images/16_spot.jpg
ucin: /assets/images/16_ucin.jpg
uefi: /assets/images/16_uefi.jpg
rozd: /assets/images/16_rozdil.jpg
zav: /assets/images/16_zav.jpg
bios1: /assets/images/16_bios1.jpg
bios2: /assets/images/16_bios2.jpg
uefi2: /assets/images/16_uefi2.jpg
---
# Zdroje PC, BIOS, UEFI a proces bootování PC
## PC zdroj
- Napájí všechny součástí PC
- Převádí střídavé napětí 230 V na stejnosměrné napětí těchto hodnot:
    - +- 3,3 V – port AGP, paměti, chipset
    - +- 5 V – mechaniky, sběrnice
    - +- 12 V – ventilátory, sériové porty
- Obsahuje ventilátor, který odvádí teplo ze zdroje i ze skříně PC
    - Důležitým parametrem je hlučnost a maximální výkon uváděný ve Wattech
- Má pojistku, která jej při zkratu uvnitř PC odpojí
- Vyrábí se ve formátu ATX (BTX), což umožnuje SW vypnutí PC
- Impulzní zdroj nikdy nezapínat naprázdno
- PC zdroj musí zabezpečit napětí v určitém rozsahu, nesmí poklesnout pod stanovený limit ani při maximální maximálním zatížení zdroje

![Konektory]({{page.konektory | relative_url}})
![Tolerance]({{page.tolerance | relative_url}})

- Výrobci zdrojů
    - Gigabyte, Corsair, SilverStone

## Konektory
- Proti obrácení polarity jsou konektory klíčované anebo mají zkosené hrany
- Hlavní napájecí konektor
    - 20 nebo 24 pinů
    - Slouží pro připojení napájení k základní desce
- ATX 12V
    - 4 pinový napájecí konektor
    - Poskytuje zvláštní napájení pro procesor a napěťové regulátory
    - Pro silné desky a procesory je zapotřebí více energie (8 pinový nebo 4+4)
- 4 pinový periferní (MOLEX)
    - Napájení pevných disků a mechanik
    - Obsahuje čtyři vodiče
        - Dva černé (zem)
        - Jeden červený (+5V)
        - Jeden žlutý (+12V)
    - Dříve používán i jako napájení pro 8“ a 5,25“ disketové mechaniky
    - V některých případech jsou využívány jako dodatečné napájení pro různé karty
- 4 pinový Berg (Mini, mini molex)
    - Malý napájecí konektor pro 3,5“ disky
- SATA power
    - 15 pinový konektor pro komponenty, který používají disky nebo mechaniky
    - Dodává napětí +3,3, +5 a +12V
- 6 pinové PCI-e
    - Grafické karty
    - Na výstupu max 75 W
- 6+2 pinové PCIe
    - Pro účely zpětné kompatibility
    - buď 6pinové, nebo 8pinové karty, které mají být připojeny pomocí dvou samostatných modulů kabelového připojení do stejné zdířky, jeden s 6 kolíky a další se dvěma
![Atx]({{page.atx | relative_url}})
![konk]({{page.konk | relative_url}})

## Řídící signály
- 5VSB
    - Vede ze zdroje do základní desky (fialový vodič)
    - Napětí +5V i když jsou všechny ostatní napěťové okruhy vypnuty
    - Používá se k elektronickému zapnutí PC
    - Udržuje základní desku neustále pod napětím, aby se dal PC softwarově zapnout bez tlačítka
- PS-ON
    - Vede ze základní desky do zdroje (zelený vodič)
    - Zapíná všechny napěťové okruhy (+5V, +12V a 3,3V) zdroje
    - V podstatě zapíná zdroj (PC), který je možné zapnout tlačítkem, ale i SW
    - Krátký impuls zdroj zapne
    - Dlouhý impuls (přidržení tlačítka) zdroj vypne
    - SW signál muže vydat OS na základě PC programu
- PW_OK
    - Vede ze zdroje do základní desky (šedý vodič), PW_good (oranžový u AT zdrojů)
    - Přímo spjat s resetem CPU než se všechny napětí dosáhnou předepsaných mezí
    - Po jeho aktivaci se začíná provádět POST

## Spotřeba jednotlivých komponentů
![Spot]({{page.spot | relative_url}})

## Parametry zdrojů
- Výkon od 200-1500W
- Maximální poskytované proudy v jednotlivých napěťových větvích
- Stabilita Uvyst při zátěži
- Stabilita Uvyst při kolísání vstupního napětí 220V
- Schopnost odfiltrování „špiček“ ze sítě
- Účinnost zdroje

## Účinnost zdroje
- Udává množství spotřebované energie vyzářené v podobě tepla a využitelné energie, ta co se přenese na výstupní svorky zdroje
- Účinnost je vždy menší než 100%
- Čím vyšší je hodnota celkové účinnosti zdroje, tím menší množství tepla se v samostatném zdroji vyprodukuje do okolí
- Nejlepší účinnost je při 50 – 75% zatížení
- Pokud je zátěž zdroje nízká, jeho efektivita je malá
- Zdroje s certifikátem 80 plus mají účinnost kolem 80-90% při jakémkoliv zatížení
![Ucin]({{page.ucin | relative_url}})
- Účiník
    - Veličina vyjadřující poměr mezi činným a zdánlivým výkonem (u sinus)
- PFC = Power Factor Correction
    - Snaha účiníku ve zdroji o eliminaci rušení a výskyt vyšších harmonických složek, které deformují sinusový průběh
    - Aktivní PFC
        - Realizace pomocí tranzistorů spolu s kondenzátory
        - Komplexní zapojení, kde je použita aktivní součástka
        - Koriguje účiník nad hodnotu 0,9
        - Nevýhoda muže být rušení od tranzistorů -> řešením je odrušovací kondenzátor
    - Pasovní PFC
        - Obsahuje pouze pasivní součástky (R, C, L)
        - Realizace pomocí cívky, která je na vstupu zdroje
        - Snaží se omezit špičky, které zdroj odebírá a tím upravuje sinusový průběh -> menší deformace

## Ochranné funkce zdroje
- OCP = Over Current Protect
    - Ochrana při nadměrném proudu
    - Pokud je nastavená hodnota překročena, zdroj se vypne
- OVP = Over Voltage Protect
    - Odpojí zdroj při vyšším napětí na větvi, než povoluje norma a limity
- OPP = Over Power Protect
    - Odpojí zdroj, když je překročen maximální výkon zdroje daný výrobcem
- OTP = Over Temperature Protection
    - Ochrana proti přehřátí zdroje
    - Při překročení maximální teploty se zdroj vypne
- SCP = Short Circuit Protection
    - Ochrana při zkratu na sekundárním částí zdroje

## BIOS
- Basic Input Output Systém
- Souhrn všech základních funkcí a programů nutných pro spuštění PC
- Komunikace mezi HW a SW, a HW a uživatelem
- Skládá se:
    - BIOS základní desky
        - Uložen v EPROM, Flash paměti
    - BIOS rozšiřujících karet (firmware)
    - Drivery HW na základní desce
    - POST (Power On Self Test)
    - SETUP utilities
    - Zavaděč (boor loader)
    - API
- Výrobci BIOS:
    - AMI BIOS, Award BIOS, Phoenix BIOS

- POST
    - Power On Self Test
    - Prohledá BIOS rozšiřujících karet a vypíše verze jejich firmwaru
    - Provede komplexní HW test PC
    - Zobrazí tabulku s nalezeným HW
    - Nastaví rychlostní parametry HW podle hodnot uložených v CMOS
- Boot Loader
    - Zavaděč OS
    - Hledá na HDD Master Boot Record
    - Zavede jej do OP (RAM) a spustí v něm obsažený programový kód a předá mu řízení
        - MBR a PAT nalezne aktivní oddíl a zavede jeho boot record do OP
        - BR oddílu najde na zaváděcím log. Disku zaváděcí soubory OS a zavede do OP
- SETUP
    - Program pro nastavení HW konfigurace a rychlostním parametrů HW
    - Aktivuje se v průběhu začátku POST kombinací kláves
        - Kombinace kláves se liší od výrobce základních desek (DEL, F1, F2, F10,…)
    - Program se nachází v EEPROM nebo Flash a edituje data uložená v CMOS
- CMOS
    - Energeticky závislá paměť na základní desce
    - Obsah je při vypnutí PC udržován baterií
    - Neobsahuje programy, pouze data
    - Její obsah se edituje Setupem
    - Lze vymazat pomocí jumperu (spojení kontaktů, vyjmutí baterie přes noc)
- API
    - Aplikační programové rozhraní
    - Slouží k zjištění správné komunikace mezi HW a OS
        - Aplikace nekomunikují přímo s HW ale s API
- DUAL BIOS
    - Zdvojený BIOS
    - Na základní desce dva čipy, které obsahují totožnou verzi BIOS
    - První souží pro klasické využití
    - Druhý představuje zálohu prvního
## Upgrade BIOSu
- Nutno zjistit typ základní desky
- Nalezení a stažení nové verze BIOSu
- Zálohování důležitých dat
- Aktualizace přímo v BIOSu
- Upgrade BIOSu se používá v případě, že stále řada komponent nemusí ze současnou verzi BIOSu fungovat
- Vrácení BIOSu do původního stavu lze udělat pomocí propojky Clear CMOS na základní desce, kterou zkratujeme

## Start PC (BIOS)
- BIOS prohlédne všechny sloty (PCI, AGP, patice procesoru, paměti), z nich přečte informace a vytvoří API
- Aby to nemusel dělat pokaždé, uloží si je do CMOS jako tzv. ESCD
- BIOS provede POST, kterým ověří správnou činnost všech komponent a inicializuje ovladače
- Potom se objeví na obrazovce (podle nastavení) seznam HW
- Pokud je POST v pořádku, najde BIOS na základě nastavení programu SETUP zavaděč OS
- Po jeho nalezení ho načte do OP a ten dál načte všechny ovladače, aby mohli komunikovat s API

## Start Pc (UEFI)
![UEFI]({{page.uefi | relative_url}})

## UEFI
- Unified Extesible Firmware Interface
- BIOS má 2 základní nedostatky
    - Je založen na 16 bit assembleru – nemůže využít moderní 64 bit HW
    - Neexistuje jednotná specifikace – každá výrobce si vše dělá po svém
- UEFI specifikace, která definuje SW rozhraní mezi výrobci OS a firmwarem HW
- Náhrada a vylepšené firmwarové rozhraní než je BIOS
- Rychlejší bootování a obnovení z režimu hibernace
- Podpora disků větších než 2,2 TB
- Podpora moderních 64 bit zařízení
- Lze používat BIOS s hardwarem UEFI
- Lepší zabezpečení díky tomu, že pomáhá chránit proces před spuštěním proti útokům bootkit (Secure boot)
- Fáze bootování UEFI
    - PEI = Pre EFI Inicialization
        - Aktivuje se CPU, pamět a čipová sada
    - DXE = Driver Execution Environment
        - Inicializace zbytku HW (paralelně)
- Součástí standartu je GPT
    - GUID Partition Table
    - Standart pro členění disků na oddíly
    - Nahrazuje starší MBR a Pat tabulku, která neumožnuje použít disk větší než 2 TB
    - Lze vytvořit až 128 primárních oddílu (na MBR 4 nebo 3 + rozšířený)

## BIOS vs. UEFI
- Oba systémy představují nutný prvotní krok pro spuštění systému
- Je to prostředník mezi OS a firmwarem jednotlivých komponent
- Liší se:
    - Vzhled
        - BIOS má modrobílé prostředí
        - UEFI moderní uživatelské 3D prostředí
    - Ovládání
        - V BIOSu pouze klávesnice
        - UEFI plně podporuje kombinaci klávesnice a myši včetně scrollování kolečkem
    - Adresování paměti
        - BIOS vyrostl na 16 bit platformě, je schopen rozpoznat disky o velikosti max 2 TB, vše se váže na MBR, se kterým BIOS spolupracuje
        - UEFI si rozumí s 64 bit adresováním, podporuje GPT a dovoluje vkládat do systému větší počet disků, dovoluje používat média do velikosti 9,4 ZB, snadné ukládání několika zavaděčů současně a tak má přístup k několika různým systémům
    - Zabezpečení
        - UEFI využívá Secure Boot, pokud je v nastavení povolena, uživatel nemůže instalovat systémy, které nejsou originální, brání tak proti pirátství a brání instalací virů, které by se aktivovaly ještě před samotným startem systému
    - Rychlost
        - UEFI trvá příprava PC ke startu OS rychleji než BIOS

## Rozdíl v bootování mezi UEFI a BIOS
- UEFI oficiálně neumožňuje bootovat systém v souborovém systému NTFS (kromě DVD disku). Je
vyžadován souborový systém FAT 32.
- Bootování už ale probíhá odlišně. Zatím co u klasického BIOSu je vyhledán a spuštěn ve
spouštěcím sektoru systémového disku zavaděč operačního systému (často tedy boot manager
Windows), tak UEFI má již vlastní zavaděč operačního systému, do kterého jsou uloženy boot
managery operačních systémů. Tomuto zavaděči je na disku vyhrazena vlastní partition. Tedy
oddíl, který je naformátovaný souborovým systémem FAT 32. Jeho označení je ESP (Extensible
Firmware Interface System Partition)

![rozd]({{page.rozd | relative_url}})

- **BIOS**
    - Start - inicializace BIOS.
    - BIOS zkoumá a posuzuje všechny komponenty, jako například procesor, paměti a
    grafickou kartu.
    - Pokračuje tím, že kontroluje všechny zapojené mechaniky, zda z nich může bootovat
    - Start Windows
    - Windows nahrají ovladače zařízení
- **UEFI**
    - Start -> inicializace UEFI
    - UEFI inicializuje hardware – procesor a paměť, ostatní komponenty se pak mohou
    aktivovat paralelně
    - UEFI Shell může spustit software
    - UEFI rovnou ví, z kterého disku má bootovat
    - Start Windows
    - Windows mohou použít ovladače UEF

## UEFI PROCES VÝBĚRÚ A ZAVEDENÍ OS
- V první fázi probíhá kontrola, zda jsou všechny hlavní součástí PC, jako deska, CPU a paměť pod napětím, pak se spustí UEFI
- Boot manager načte data aplikace UEFI z paměťového media a z oddílu na pevném disku PC
- Spustí se zavaděč OS
- Ten startuje OS buď přímo, nebo prostřednictvím Boot manageru
- Startovací kód OS i Boot manager musí mít platnou certifikaci, jinak zavaděč start systému přeruší
- To stejné platí pro všechny další komponenty jádra OS, které boot manager postupně načítá
- Kontrola secure boot
    - Při aktivované funkci secure boot musí mít součásti OS – jádro, ovladače odpovídající certifikát

![Zav]({{page.zav | relative_url}})

## Instalace OS přes UEFI
- Vložíme paměťové médium s OS
    - Bootovatelný USB flash disk (nutno FAT 32) nebo např. CD
    - V SETUPu nastavíme pořadí, z jakého média má bootovat
- Pokud se nám rovnou nespustí instalace přes UEFI, najedeme do EFI Shell, z nabídky vybereme jednotku, ze které chceme instalovat, přepneme se do složky BOOT a následně do EFI, zde spustíme soubor bootx64.efi -> spustí se instalace

## Nastavení SETUPu v BIOSu
- Do SETUPu BIOSU se dostaneme stisknutím požadované klávesy
- Klávesa se liší od daného výrobce (DEL, F1,F2,F10,..)
- Modrobílá menu BIOSu se skládá z několika záložek
    - Main
        - Přehled verze BIOSu, informace o CPU, frekvence, povolení Hyper Threading
    - Advanced
        - Důležitá sekce, konfigurace periferií, logy, HW monitoring, nastavení USB
    - Performance
        - HW taktování
    - Security
        - Nastavení hesla, uživatelů, kontrola detekce zavřené skříně
    - Power
        - Nastavení napájení
    - Boot
        - Nastavení pořadí bootovacích medií
    - Exit
        - Uložení a opuštění BIOSu
- LOAD SETUP DEFAULT
    - Použijeme, pokud PC po startu vykazuje problémy (pokud nejde vůbec spustit, zkratujeme propojku Clear CMOS na základní desce)

![BIOS1]({{page.bios1 | relative_url}})
![BIOS2]({{page.bios2 | relative_url}})

## Nastavení SETUPu UEFI
- Prostředí UEFI působí naprosto intuitivně
- Podpora klávesnice i myši
- Na základní obrazovce je vše důležité, včetně pořadí bootování, jeho změna se pak provádí jednoduchým přetažením
- Upgrade UEFI
    - Zjistíme typ desky výrobce a nejdeme nejnovější verzi UEFI, kterou stáhneme na USB disk (nebo na pevný disk, USB jednodušší na hledání), přesuneme se do UEFI Setupu, zvolíme aktualizaci a vybereme uložiště se souborem a spustíme proces

![UEFI2]({{page.uefi2 | relative_url}})

## Nastavení hesla BIOS/UEFI
- Security
- Set Supervisior password – pro administrátora, má oprávnění vstoupit do setupu
    - Nastaví heslo, které je požadováno po startu, když chce uživatel vstupit do setupu BIOSu
- Set User password – pro uživatele, který může plně pracovat se systémem, ale nemá přístup pro konfiguraci BIOS