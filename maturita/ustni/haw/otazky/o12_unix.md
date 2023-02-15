---
layout: page
title: Unix
description: Otázka č.12 - Unix
has_children: false
nav_exclude: true
---
# Unix
## Charakteristika systému Unix
- Napsán v jazyce C
- Autoři Ken Thompson a Denis Ritchie
- Má hierarchický souborový systém – strom adresářů s jedním kořenem
- UNIX je víceuživatelský a více úlohový univerzální operační systém
- Víceuživatelský systém dovoluje pracovat současně více uživatelům
- Více úlohový systém dovoluje každému uživateli spustit více úloh najednou
- hlavní úlohou operačního systému je efektivně řídit přidělování paměti, procesoru, prostoru na disku, řídit obsluhu terminálů a všech zařízení připojených k počítači
- operační systém by měl uživateli poskytnout takové prostředí, aby mohl počítač používat k běžné práci
- operační systémy typu UNIX pracují i na velmi odlišných architekturách, od mnohaprocesorových superpočítačů až po osobní počítače typu PC
- na výkonných pracovních stanicích je téměř výhradně používaným systémem
- pro systémy UNIX se dodává široká škála programového vybavení:
    - textové editory (WordPerfect), kompilátory prakticky všech programových jazyků, databázové systémy (od dBASE až po Oracle), vývojové prostředky (AutoCad, OrCad) atd.
- díky univerzální historii systému existuje pro UNIX i velké množství kvalitních volně šířených programů, jako např. grafické uživatelské prostředí X Window, portabilní optimalizující kompilátor GNU C a C++ nebo typografický program TEX
- kromě toho se UNIX vyznačuje zejména těmito vlastnostmi:
    - jednoduché uživatelské rozhraní
    - kromě příkazové řádky je možné na speciálních terminálech používat i grafické uživatelské rozhraní
    - hierarchický souborový systém
    - vstup a výstup je nezávislý na zařízení
    - každé fyzické zařízení, od interaktivních terminálů až po hlavní paměť, je považováno za soubor, který je možno podobně jako obyčejný soubor číst nebo do něj zapisovat
    - velmi silný příkazový jazky
    - na rozdíl od interaktivních příkazových jazyků jiných systémů je jazyk UNIXového shellu opravdovým programovacím jazykem
    - obsahuje řadu primitiv pro výrobu složitějších programů z jednodušších - existují zde příkazy pro vyhledání textu v souborech, porovnávání a hledání rozdílů mezi soubory, prohledávání adresářů, úpravu a sázení textů, a to i včetně složitých tabulek a rovnic
    - součástí systému je kompilátor jazyka C a řada programátorských nástrojů, jako debugger a profiler, generátor lexikálních a syntaktických analyzátorů, programy pro spolupráci více programátorů na jednom projektu
    - síťové programové vybavení.
    - s operačním systémem se dodává základní programové vybavení podporující zapojení systémů UNIX do počítačových sítí

## Unix vs Windows
- Linux je open source operační systém, takže uživatel může změnit zdrojový kód podle požadavku, zatímco Windows OS je komerční operační systém, takže uživatel nemá přístup ke zdrojovému kódu.
- Linux je velmi dobře zabezpečený, protože je snadné odhalit chyby a opravit, zatímco Windows mají obrovskou uživatelskou základnu, takže se stává cílem hackerů zaútočit na systém Windows.
- Linux běží rychleji i se starším hardwarem, zatímco Windows jsou ve srovnání s Linuxem pomalejší.
- Periferní zařízení Linux, jako jsou pevné disky, CD-ROM, tiskárny, se považují za soubory, zatímco Windows, pevné disky, CD-ROM, tiskárny se považují za zařízení
- Soubory systému Linux jsou uspořádány ve stromové struktuře počínaje kořenovým adresářem, zatímco ve Windows jsou soubory ukládány do složek na různých datových jednotkách jako C: D: E:
- V systému Linux můžete mít 2 soubory se stejným názvem ve stejném adresáři, zatímco ve Windows nemůžete mít 2 soubory se stejným názvem ve stejné složce.
- V systému Linux najdete systémové a programové soubory v různých adresářích, zatímco ve Windows se systémové a programové soubory obvykle ukládají na jednotku C:

## Práce se soubory
- Soubor = sled bajtů
- Textové programy požadují řádky oddělené znakem asci LF
- Soubory jsou organizovány do adresářů ve tvaru stromu
- Adresáře jsou soubory s informacemi jak nalézt jiné soubory
- Relativní nebo absolutní cesta
    - Relativní cesta – pozice aktuálního adresáře se řeší tečkou
        - ./soubor.txt/trida/lavice
        - Dvě tečky vedle sebe nahradí adresář o jeden nad aktuální adresář
            - ../škola/soubor.txt ./trida/lavice
    - Absolutní cesta – vztahuje se vždy ke kořenu
        - Nezáleží na aktuální pozici
        - Nevýhoda je dlouhá cesta
        - /home/x0a_gorny/škola/soubor.txt

## Programátorský interface
- Systém souborů
    - Systém souboru poskytuje metody pro organizaci a uschování souboru
    - V UNIXu tvoří stromovou strukturu adresářů a souborů, ve kterém jsou umístěny všechny soubory včetně těch, které reprezentují vstupně/výstupní zařízení
    - Soubory jsou umístěny v adresářích, jejichž obsahem mohou být i další adresáře
    - Kořenový adresář má jméno „/“
    - Soubor může jednoznačně určit jeho absolutní cestu, začínající od kořenového adresáře
    - Absolutní cesta začíná lomítkem a skládá se ze seznamu adresářů oddělených lomítkem, kterými musíme projít, abychom dospěli k požadovanému souboru
    - Systém pro každý proces udržuje tzv. pracovní (aktuální) adresář
    - Pokud jméno souboru nezačíná lomítkem, soubor se vyhledává od pracovního adresáře
    - Délka jména souboru byla původně omezena na 14 znaků, ale současné systémy umožňují používat jména souboru až 255 znaků dlouhá
    - Jméno souboru může obsahovat libovolné znaky a rozlišují se v něm malá a velká písmena
    - Příkazy a zkratky:
        - DEV
            - všechny drivery – pro tiskárny, HDD atd.
        - BIN
            - nejpoužívanější příkaz UNIXu ve spustitelném tvaru
            - všechny příkazy OS
        - SBIN
            - Příkazy OS pro roota
        - ETC
            - Systémové programy a data
            - Startovací skripty serverů
        - HOME
            - Domovský adresář
        - LIB
            - Knihovna pro jazyk C
        - TMP
            - Dočasné soubory
        - VAR
            - Soubory, které během běhu mění svou velikost
        - MC -A
            - Midnight commander
        - MNT
            - Místo, kde se dají připojovat disky

## Procesy UNIX
- Proces je spuštěný program
- Každý proces má své ID
- Nový proces vytváří systémová funkce FORK
- Nový proces dědí adresní prostor
- Mateřský proces a potomek pokračují od programu instrukce po následující proces FORK, potomek využije EXECUE – může zavést nový program, který zruší kódy rodičovského procesu, potomek ruší svou činnost funkcí EXIT a jeho mateřský proces může čekat na tuto událost funkcí WAIT
- Funkce EXIT vrátí PID končícího procesu a rodič může určit, který potomek koncí ukončení procesu
- Potomek přejde do stavu ZOMBIE
- Řízení procesů:
    - Fork()
        - Vytváří kopii rodičkovského procesu
        - Je třeba ošetřit chybu "cannot fork"
    - Exec()
        - Překryje adresní prostor procesu zadaným programem
    - Wait()
        - Rodičovský proces čeká na skončení potomků
    - Exit()
        - Ukončí proces a předá rodičovskému procesu návratovou hodnotu
- Jeden z faktorů pro plánování procesů je jeho hodnota a současně kladné číslo
- Potomek dědí prioritu od otce
- Při startu je možné stanovit jinou prioritu
    - nice -n incr cmd
- Inkrement obvykle povolen v rozsahu +-20
- Pouze root muže zadávat záporné hodnoty
- Proces lze změnit prioritou
    - Renice -n incr PID
- Když je proces zabit (killed), může se stát, že bude i nadále zobrazován v PS listu, ale jako proces v Z stavu, tomuto stavu se říká ZOMBIE
    - Tento proces je dead a nemůže být použit

## PIPE
- Systémová vyrovnávací paměť, do které jeden proces data ukládá a další je z ni odebírá
- Pro označení toho mechanismu se používá oddělovač „|“
    - Command | filtr
        - Kde command zapisuje výstup do roury, ze které jsou čtena příkazem filtr, který pak výsledky vypisuje na standartní výstup
    - Ls –l | more
    - Příkazy, které jsou spojené pipou se nazývají kolona
    - Kolona může obsahovat několik členů, kteří si předávají své výsledky

## Mezi procesová komunikace
- Inter proces communication
- Semafor
    - Využíváme jej, pokud máme kritickou část programu, která potřebuje exkluzivní přístup jednoho procesoru k nějakému zdroji
    - 3 metody:
        - Zdroj obhospodařuje vlastní program, která je chráněn a žádný jiný program nemůže přistupovat přímo ke zdroji, kromě sprostředkovatele
        - Každá napsaná program periodicky testuje nějaká přepínač (semafor) a zjišťuje, jestli je volný. Tomuto algoritmu se říká detektiv. Tento algoritmus však spoléhá na tzv. kruhové blokování, kdy nějaký proces nepřetržitě běží a čeká, až se změní obsah nějakého místa v paměti. Ve více úlohovém prostředí to však znamená nepřijatelné plýtvání zdroji CPU
        - Semafor od Dijkstra
            - Semafor je speciální proměnná, která může obsahovat pouze kladná, celá čísla a provádí 2 operace
                - Čekání P a signál V
            - Př.
                - Proměnná A
                - P(A)
                    - Jeli proměnná A větší než 0, sniž její hodnotu
                    - Jeli nulová, pozdrž provádění tohoto procesu
                - V(A)
                    - Pokud byl nějaký jiný proces proměnnou A pozdržen, ať pokračuje v provádění
                    - V opačném případě zvyš hodnotu proměnné A
            - Může dojít k Deadlocku
                - Procesy se zablokují navzájem a čekají na sebe
- Sdílená paměť
    - Umožňuje nepříbuzným procesům přistupovat ke stejné logické paměti
    - Sdílená paměť je velice efektivním způsobem předávání dat mezi dvěma běžící proces
    - Paměť si vytvoří jeden proces a jiné procesy si ji můžou namapovat
    - Namapovaná sdílená paměť se sice jeví jako obyčejná paměť získána funkcí maloc, neexistují ale nástroje na mezi procesorovou synchronizaci
        - Zabránění druhému procesu ve čtení sdílené paměti dříve, než první proces dokončí zápis do ní
- Signály:
    - Umožnují obsloužit výjimečné situace, např. přerušení klávesnice, chyba procesu nebo asynchronní záležitosti např. signál hodin
    - Signál lze vytvořit systémovým příkazem KILL
    - Nejsilnější signál zrušení procesu lze vyvolat KILL –PID procesu
    - PID procesu zjistíme pomocí PS –a –l
    - SigInt – ekvivalent Ctrl+c
    - SigQuit – odložení procesu Ctrl+I
    - Sighup
    - Sigkill

## Uživatelský interface
- Uživatelský interface je grafický nebo textový
- Programátoři a uživatelé pracují především s již existujícími systémovými programy
- Většina společných systémových programů je orientována na soubory a adresáře
    - Mkdir, rmdir, cd, pwd
    - Ls, cp, mv, rm
- Shell
    - Proces, který zprostředkovává provedení jiných programů
    - typický příkaz:
        - jméno souboru s provedení schopného binárního objektu
    - provedení příkazů:
        - shell prochází vyhledávací cestu adresářem a hledá soubor s programem (příkazu), tento program zavede a vyvolá jeho provedení
    - svůj běh potlačí do ukončení provedení příkazu vyhledávací cesta
    - seznam přístupových cest adresářů
    - vesměs vždy jsou v ní obsaženy adresáře /bin a /usr/bin
- příkazy
    - find = vyhledává specifikovaný soubor v zadaném adresářovém prostoru
    - ls = list = výpis obsahu adresáře
    - pwd = print working direktory = zjištění aktuálního pracovního adresáře
    - cd = change direktory = změna aktuálního adresáře
    - mkdir = vytvoření adresáře
    - rmdir = zrušení adresáře
    - chmod = změna atributů
    - grep = prohledává soubory, vypisuje řádky, ve kterých nalezne text odpovídající zadanému
    - cat = používá se k zobrazení nebo spojení souborů
    - head = vypisuje začátek souboru na standartní výstup
    - tail = vypisuje konec souboru
    - diff = porovnává dva soubory po řádcích
    - cmp = porovnává dva soubory a ohlásí první nalezený rozdíl
    - sort = setřídí obsah souboru nebo spojí více souboru do jednoho setříděného

## Použití a popis služeb
### Telnet
- Telecomunication network
- Označení protokolu používaném v PC sítích, který pomocí stejnojmenné aplikace umožnuje uživateli připojení ke vzdálenému PC
- Protokol Telnet pracuje na aplikační vrstvě TPC/IP
- Používá se v internetu pro realizaci spojení typu klient-server protokolem TPC, přičemž přenáší osmibitové znaky oběma směry (duplex)
- Serverová část standardně naslouchá na portu číslo 23
- Součástí protokolu je vyjednání nastavení určitých voleb důležitých pro vzájemnou komunikaci
### SSH
- Secure Shell
- Program a zároveň zabezpečený komunikační protokol v PC sítích, které používají TCP/IP
- SSH byl navržen jako náhrada za Telnet a další nezabezpečené Shelly, které posílají heslo v nezabezpečené formě a umožnují tak jeho odposlechnutí při přenosu pomocí PC sítě
- Šifrování přenášených dat, které SSH poskytuje, slouží k zabezpečení dat při přenosu přes nedůvěryhodnou síť, jako je například internet
- SSH umožnuje bezpečnou komunikaci mezi dvěma PC, která využívá pro zprostředkování přístupu k příkazovému řádku, kopírování souborů a též jakýkoliv obecný přenos dat
- Zabezpečuje autentizaci obou účastníků komunikace, transparentní šifrování přenášených dat, zajištění jejich integrity a volitelnou bezdrátovou kompresi
- Server standardně naslouchá na portu TCP/22
### FTP
- File Transfer Protocol
- Protokol pro přenos souborů mezi počítači pomocí PC sítě
- Využívá protokol TCP/IP a může být používán nezávisle na použitém OS
- Používá se ke sdílení dat a správu účtu internetových stránek
### DNS
- Domain Name System
- Systém doménových jmen, který je realizován servery DNS a protokolem stejného jména, kterým si vyměnují informace
- Jeho hlavním úkolem a příčinou vzniku jsou vzájemné převody doménových jmen a IP adres uzlů sítě
- Dnes slouží jako distribuovaná databáze síťových informací
- Servery DNS jsou organizovány hierarchicky, stejně jako jsou hierarchicky tvořeny názvy domén
- Jména domén umožnují lepší orientaci lidem, adresy pro stroje jsou však vyjádřeny pomocí adres 32 bit (IPv4) nebo 128 bit (IPv6)
### DHCP
- Dynamic Host Configuration Protocol
- Protokol z rodiny TCP/IP, který se používá pro automatické přidělení IP adres počítače připojeným do PC sítě
- DHCP server přiděluje počítačům pomocí DHCP protokolu zejména IP adresu, masku sítě, výchozí bránu a adresu DNS serveru
- Platnost přidělených údajů je omezená, proto je na PC spuštěn DHCP klient, který jejich platnost prodlužuje

## Virtualizace Unixu na MS Windows
- Virtualizace PC je metoda, která umožnuje spuštění libovolného OS na již zapnutém PC
- Pro použití virtualizace je nutné mít základní desku, která virtualizaci podporuje (v dnešní době téměř všechny)
- Další podmínkou je zapnout v BIOS nastavení Virtual VM
- Důležitou součástí PC by měla být dostatečně velká OP RAM – minimum 2 GB
- Software pro virtualizaci:
    - VirtualBox - freeware
    - Microsoft Virtual PC - freeware
    - VMware Workstation
    - Parallels Workstation

## Skripty
- Př. 1 - signál
        #include<signal.h>
        #include<stdio.h>
        #include<unistd.h>

        Void ouch(int sig)
        {
            printf("ouch!-Mam signal %d\n" sig);
            (void)signal(sigint, sig_diff);
        }
        Int main()
        {
            (void) signal (sigint, ouch);

            While(1)
            {
                Printf(“Hello!\n“);
                Sleep (1);
            }
        }

- Př. 2 
        Nano skr2
        Echo “start….”
        Read B
        If [“$B“=“YES“]
        Then echo „dobry den“
        Else
        Echo „dobry vecer“
        Fi
        Echo „END….“

## Správa uživatelů
- Useradd = vytvoří nového uživatele
- Userdel = vymaže uživatele a soubory
- Usermod = modifikuje uživatelský účet
- Groupadd = vytvoří novou skupinu
- Groupdel
- Groupmod

**Př**
        Groupadd studenti
        useradd st1 -g studenti
        chmod g+rx st1
        Passwd st1
        st1/ nastavení hesla
        st1/ potvrzení hesla

## Konfigurace služeb
- /var/etc/rc.d/init.d      = rozjíždí skripty pro kofiguraci
- /var/etc      = konfigurační soubory 
- Chkconf
   -  --list
   -   --add
   -  --del
- Chkconf -list | more
- Apropos = nápovvěda
- Daemon
    - Spuštěný program
    - Odstřihne se od klávesnice
    - Něco dělá, nastavuje, ale není vidět
    - Internetový daemon = XINETD

## Konfigurace FTP
- /var/etc/vsftp/vsftp.conf
- /var/etc/rc.d/init.d/vsftp reload, start, stop

## Základní příkazy
- Ls        = listování
- Man       = manuál
- Q         = odchod
- Ls -all   = zobrazí vše
- Ls -al    = dlouhý výpis
- Cd        = skok do domovského adresáře
- cd..      = přepne o úroveň výše
- pwd       = ukáže celou cestu(to kde jsme)
- ls -l | grep x0a
- bin       = všechny příkazy OS
- sbin      = příkazy OS pro roota
- cd/       = přepne se do kořene
- dev       = drivery
- etc       = adresář, kde jsou startovací skripty serveru
- mnt       = místo, kde se dají připojit další disky
- tmp       = dočasný adresář
- var       = data, FTP server
- mc -a     = mid night commander
- cat       = katalog, vypíše obsah souboru
- more      = vypíše obsah souboru
- less      = vypíše obsah souboru, kde se můžeme vracet
- mkdir     = tvorba adresáře
- cp        = kopírování
- rm        = mazání
- ps        = zobrazí běžící procesy
- ps -ax
- find      = prohledává soubory a adresáře
- sort      = třídí