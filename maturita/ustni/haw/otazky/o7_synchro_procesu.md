---
layout: page
title: Synchronizace procesů
description: Otázka č.7 - Synchronizace procesů
has_children: false
nav_exclude: true
---
# Synchronizace procesů
## Producent vs. Konzument
- 1 z nich bude počitadlo (counter) -> počítá hodnoty v bufferu
- 2 z nich bude buffer
- Producent přidá hodnoty do bufferu a konzument je veme

|Běží       |Akce       |Výsledek|
|:----------|:----------|:-------|
|Producent  |R0=count   |R0=3    |
|Producent  |R0++       |R0=4    |
|           |           |        |
|Konzument  |R1=count   |R1=3    |
|Konzument  |R1--       |R1=2    |
|           |           |        |
|Producent  |count=R0   |count=4 |
|           |           |        |
|Konzument  |count=R1   |count=2 |

- Po vykonání instrukce se může přepnout kontext
- Producent generuje data do vyrovnávací paměti (buffer) o velikostí n (společná paměť pro producenta a konzumenta)
- Konzument z bufferu odebírá
- Po vygenerování nových dat producentem se zvyšuje hodnota počitadla (count ++)
- Konzument po odebrání dat z bufferu sníží hodnotu count --
- Bez správného ošetření přístupu k bufferu a proměnné count není zaručen správný výsledek a může hrozit uváznutí procesu
- V jazycích vyšší úrovně je inkrementace otázkou jediného příkazu, ve skutečnosti je tato operace otázkou více instrukcí (assembler) a k přepnutí kontextu dochází až po provedení instrukce
- Je nutná komunikace mezi procesy například pomoci IPS
- Producent
    - Generuje data do vyrovnávací paměti s konečnou kapacitou (buffer)
- Konzument
    - Z této paměti data odebírá
- Buffer
    - Společná paměť slouží k výměně dat
- **Producent:**
    - pokud proměnná počítadlo má stejnou velikost jako velikost bufferu, nemůže nic
    produkovat, jinak vyprodukuje data, vloží do společné paměti a inkrementuje počítadlo
    (aktualizuje počet prvků v bufferu)
- **Konzument:**
    - pokud proměnná počítadlo je 0, tudíž v bufferu nejsou žádná data, nemůže také
    konzument nic z bufferu vybírat, pokud data v bufferu jsou, vybere data a sníží proměnnou
    počítadlo o 1

## Kritická sekce:
- část strojového kódu, kde dochází k přístupu ke sdíleným prostředkům
- hrozí zde přístup více vláken najednou
- **Podmínky KS:**
    - Žádné dva procesy nebo vlákna nesmí být současně uvnitř stejné kritické sekce
    - Na řešení nesmí mít vliv počet CPU
    - Žádný proces nesmí zůstat čekat nekonečně dlouho na kritickou sekci
    - Žádný proces mimo kritickou sekci nesmí blokovat jiný proces, který by do něj měl vstoupit
- **Řešení KS:**
    - Softwarová řízení na aplikační úrovni
        - Je v celé režii programátora, jedno ze základních řešení, je zde aktivní čekání
    - Hardwarová řešení
        - Pomocí speciálních instrukcí procesů a i zde je aktivní čekání
    - Softwarová řešení zprostředkované OS
        - Stára se o to jádro OS, je zde pasivní čekání
    - Aktivní čekání
        - testuje proměnou, jestli může vstoupit do kritické sekce
    - Pasivní čekání
        - uspí se a proces, který chce vstoupit do kritické sekce

## Řešení kritické sekce
- vzájemné vyloučení s aktivním čekáním
    - **zákaz přerušení**
        - Nejjednodušší řešení
        - Zákaz všech přerušení procesy, které právě vstoupily do kritické sekce
        - Opětovné povolení přerušení po opuštění kritické sekce
        - Pokud není povoleno přerušení, nedojde k přepnutí na jiný proces
        - Nevhodné řešení, protože uživatelský proces zasahuje do chodu systému tím, že zakazuje přerušení
        - Pokud opětovně nepovolil přerušení, tak systém spadne
        - Pokud je systém více procesorový, tak proces běžící na jiném procesoru může vstoupit do kritické sekce
    - **zamykací proměnná**
        - Každý proces dostane zamykací proměnnou lock, když je v 1 nemůže do kritické sekce, 0 můžu, je tam volno
        - Může nastat situace, že jeden proces ji nestihne načíst před přepnutím kontextu, druhý proces začne taky načítat lock proměnnou -> už jsou dva procesy v kritické sekci
    - **přesné střídání**
        - Vylepšení předchozího řešení (řešení č. 2)
        - Proměna turn určuje, který proces může vstoupit do kritické sekce
        - Proces otestoval turn, že je rovné 0, takže vstoupí do kritické sekce
        - Když P0 opustí kritickou sekci, nastaví turn na 1, což říká že P1 může vstoupit
        - Přijde P1, uvidí, že turn = 1, což znamená, že může vstoupit do kritické sekce, po vystoupení nastaví turn na 0
        - P0 blokuje P1 -> takže porušuje 3. podmínku kritické sekce, nepoužitelné
    - **Petersonovo řešení**
        - Funkční řešení a aktivním čekáním (while)
    - **Atomická instrukce**
        - enter_css: task lock
            - Kopíruj lock do CPU a nastav na 1
        - bez enter_css
            - Byl-li lock nenulový, skok na opakované testování = aktivní čekání
        - ref
            - Byl nulový -> návrat a vstup do kirtické sekce
        - leave_cs: mov lock, #0
            - vynuluj lock a odemkni kritickou sekci
        - Nutná hardwarová podpora
        - Procesor při vykonávání instrukce uzamkne datovou sběrnici
        - Proběhne celá jako jediná operace (nedělitelná)
        - Problém aktivního čekání je neustále testování zda může proces vstoupit do kritické sekce
        - Hrozí zde nejen plýtvaní procesorovým časem, ale také uváznuti při čekání na kritickou sekci
        - Dva procesy, růzá priorita
            - H, L
            - L -> je v kritické sekci, H příjde
            - H -> připraven vstoupit
            - H -> nemůže vstoupit, protože L je v kritické sekci
            - H -> aktivní čekání
    - **Bez aktivního čekání**
        - Jedná se o systémové volání, které uspí, nebo probudí daný proces
        - Voláním přijímá jeden parametr (id procesu)
        - V případě, že není žádná potřeba, tak se uspí
    - Producent vs. Konzument - sleep/wakeup
    |Běžící proces |Akce            |Výsledek   |
    |:-------------|:---------------|:----------|
    |Konzument     |Čtení count     |Ak = count |
    |Producent     |Vložení položky 
                    count ++, 
                    Zjíštění, že jde 
                    o první položku |count = 1, wakeup(konzument)|
    |Komzument     |?Ak==0?         |sleep(konzument)|
    |Producent     |Ukládá položky,?Ap==N?|Ap=count, sleep(producent)|