---
layout: page
title: A/D převodníky
description: Otázka č.5 - A/D převodníky
has_children: false
nav_exclude: true
princip: /assets/images/princip.jpg
vzork: /assets/images/vzork.jpg
kvant: /assets/images/kvant.jpg
kod: /assets/images/kod.jpg
analog: /assets/images/analog.jpg
dig1: /assets/images/dig1.jpg
dig2: /assets/images/dig2.jpg
par: /assets/images/par.jpg
pri: /assets/images/pri.jpg
pri2: /assets/images/pri2.jpg
sle: /assets/images/sle.jpg
apro: /assets/images/apro.jpg
apro2: /assets/images/apro2.jpg
dvoj1: /assets/images/dvoj1.jpg
dvoj2: /assets/images/dvoj2.jpg
dvoj3: /assets/images/dvoj3.jpg
sig1: /assets/images/sig1.jpg
sig2: /assets/images/sig2.jpg
---
# A/D převodníky

## Charakteristika
- Analogově-digitální převodník je elektronická součástka, který je určena pro převod analogového (spojitého) signálu na signál digitální
- Důvodem tohoto převodu je umožnění zpracování původně analogového signálu na číslicových počítačích
- Využívá se vždy ve spojení s mikroprocesorem v aplikacích, kdy je nutné měřit určitou analogovou veličinu
- V praxi se používá několik druhů převodníku, které pracují na různých principech a mají jiné vlastnosti
- Analogové signály lze přenášet po převodu na číslicový signál s menším zkreslením
- Opakem je DA převodník

## Princip přenosu
![Princip]({{page.princip | relative_url}})

### Vzorkování
- Vzorkování se provede tím způsobem, že rozdělíme vodorovnou osu signálu T na rovnoměrné úseky a z každého úseku odebereme jeden vzorek
- perioda T je vždycky stejně velká
- Hodnota se pošle do kondenzátoru, který slouží jako analogová paměť. Vzdálenost vzorků se bude lišit vzorkovací frekvencí, čím bude vzorkovací frekvence větší, tím bude více vzorků a kvalitnější převedený signál
![Vzorkovani]({{page.vzork | relative_url}})
- **Převod ovlivňují tyto vlastnosti:**
    - Přesnost převodu Vzorkovací frekvence
    - Citlivost
    - Rychlost převodníku
    - Zkreslení
    - Rychlost vzorkování
- **Chyby:**
    - Chyba zesílení
    - Chyba nuly
    - Chyba konstanty
    - Chyba linearity
    - Chyba způsobená dobou vzorkování
    - Integrální nelinearita
    - Diferenciální nelinearita
    - Kvantizační šum:
        - Je důsledkem kvantování
        - Je to rozdíl kvantovaného a vstupního spojitého signálu

### KVANTOVÁNÍ
- Kvantování probíhá podle toho, v jaké části se nachází vzorek, tak podle rozhodovací úrovně se zaokrouhli nahoru nebo dolů
- při zaokrouhlení vznikne zkreslení (kvantizační šum)
- kvantované hodnoty jsou označeny zeleně
![Kvantovani]({{page.kvant | relative_url}})

### KÓDOVÁNÍ
- Kódování znamená, že ke každému vzorku se přiřadí hodnota v binární podobě
- Příklad výstupního číselného kódu: 1011001
- První číslo zleva je MSB = bit s největší váhou, poslední číslo je LSB = bit s nejmenší váhou
![Kodovani]({{page.kod | relative_url}})

## Analogový signál
- Je spojitý v čase a v amplitudě
- Má nekonečné množství hodnot
- Je to přirozeně vytvořený signál (nejpřirozenější je řeč), napětí, tlak, světlo, radiové vysílání
- Lze uchovat na VHS kazetě, magnetofonových páskách, gramofonových deskách
- S opakovanou reprodukcí ztrácí na kvalitě
![Analog]({{page.analog | relative_url}})

## Digitální signál
- Spojitý v čase, ale nespojitý v amplitudě
![Dig1]({{page.dig1 | relative_url}})
- Nespojitý v čase ani v amplitudě
![Dig2]({{page.dig2 | relative_url}})
- Je tvořen posloupnosti vzorků, které mohou nabývat pouze omezeného počtu hodnot
- Po opakované reprodukci neztrácí na kvalitě
- Lze uchovat na flash discích, cd, disketách, hdd, ssd

## Paralelní převodník (FLASH)
- Nejrychlejší typ převodníku – rychlost je dána rychlostí komparátoru, řádově ns
- Pro n-bitový převodník je potřeba 2n-1 komparátoru (3 bitový = 7 komparátorů)
- Přesnost není moc velká (technologická náročnost výroby odporů)
- Pro snížení nákladů a zvýšení přesnosti je možné kaskádové zapojení
- Pracuje se vzorkovacími frekvencemi nad 100 MHz
- Používá se k digitalizaci obrazu
### Paralelní převodník - Funkce
- Komparátory porovnávají převáděné napětí Ux s referenčním napětím Uref
- Díky přesnému odporovému děliči je Uref rovnoběžně rozděleno na dílčí komparátory
- Ux = 0 V -> na výstupech komparátoru je log 0
- Ux = Uref -> na výstupech příslušného komparátoru je log 1
- Dekodér se postará o převod do binární podoby
- Ulsb je na každém odporovém děliči stejné
- Výstup z komparátoru je většinou ještě přivedené na D-klopný obvod a až potom do dekodéru
- Kvůli CLK je výstup z komparátoru přiveden na D-klopný obvod, a až pak na dekodér
![par]({{page.par | relative_url}})

## Přírůstkový (čítací) převodník
- Jedná se o kompenzační převodník
- Čítač je inkrementován na základě impulzů a výstupu z komparátoru
- Na začátku je obsah čítače vynulován
- Výstup komparátoru = “1“
- S každým impulzem je zvýšená hodnota čítače
- Čímž také narůstá napěti UDA
- UDA > Uvst -> Výstup komparátoru je “1“ -> konec čítání a hodnota převáděného napětí je uložená v čítači (v paměťové částí)
![pri]({{page.pri | relative_url}})
![pri2]({{page.pri2 | relative_url}})

## Sledovací (s vratným čítačem) převodník
- Princip stejný jako čítací
- Využití obousměrného čítače, může čítat vpřed i vzad
- Směr je řízen výstupem komparátoru, takže číslicový výstup sleduje změny vstupního napětí
- V každém taktu generátoru hodinových impulsů mění slova vždy o hodnotu LSB
- Špatně reaguje na rychlé změny signálu
- Poskytuje okamžitou hodnotu Ux
- Často používány převodník
![sle]({{page.sle | relative_url}})

## Převodník s postupnou aproximací
- Postupná kompenzace napětí od MSB po LSB
- Nejdříve je vynulován registr
- Na začátku cyklu převodu se nastaví hodnota převodu výstupu registru na 100000000
- MSB nastaven na „1“ -> DA vytvoří Uda = Uref / 2
- Uda < Ux => bit zachován
- Uda > Ux => bit nulován
- Má pevnou dobu převodu
- Vysoká přesnost
- Používá se u voltmetrů a digitálních osciloskopů
- Využívá konstantní napětí na vstupu během převodu (na vstupu kondenzátoru)
- Doba převodu je nižší než u čítacího převodníku a je nezávislá na vstupním napětí
- Změna vstupního napětí během převodu způsobí chybu, a proto na rozdíl od čítacího převodníku musí být vstup opatřen vzorkovacím obvodem
![apro]({{page.apro | relative_url}})
![apro2]({{page.apro2 | relative_url}})

## S dvojitou integrací
- Pomalý, ale velmi přesný
- Odolný proti brumu (něco co ruší signál, vzniká z transformátoru) a šumu
- Analogový signál je transformován na časový interval, který je následně digitalizován
- Převod je složen ze dvou fází
- Použití: multimetry
- Před první fázi je čítač vynulován a kondenzátor vybitý
- **1.fáze:**
    - Signálem „start“ se otevře hradlo a do čítače začnou přicházet impulzy, zároveň je na přepínači Uvst
    - Po konstantní dobu se integruje Uvst (Ui lineárně roste) a obsah čítače roste konstantní rychlosti Tx
    - Po naplnění se přepne přepínač na konstantní UREF (opačná polarita Uvst)
- **2.fáze:**
    - Na vstupu integrátoru je konstantní napětí opačné polarity -> začne klesat napěti na jeho výstupu
    - Čítač čítá příchozí impulzy od nuly po dobu TREF (vybití kondenzátoru)
    - Napěti Ui lineárně klesá rychlosti úměrnou velikosti UREF
    - Ui = 0 -> změna výstupu komparátoru, signál „stop“ -> uzavřená hradla -> hodnota uložena v čítači
    - Obsah čítače je úměrný času TREF, který je úměrný velikosti Uvst

    - Měřené napěti je úměrné době druhé integrace
    - UREF má opačnou polaritu než měřené napěti -> díky tomu se bude vybíjet kondenzátor
    ![dvoj1]({{page.dvoj1 | relative_url}})
    - Došlo k naplnění čítače a přetečení převodníku, přepnutí první fáze na druhou
    ![dvoj2]({{page.dvoj2 | relative_url}})
    ![dvoj3]({{page.dvoj3 | relative_url}})

## Sigma-delta převodník
- Rozdělen na analogovou a digitální část
### Analogová:
 - Jednoduchá, pomalejší (integrátor, komparátor, zdroj Uref, obvody pro slučování analogových signálů)
### Digitální:
 - Složitější, rychlá (číslicová filtrace a decimace vzorkovaného signálu)
 - Vzorkovací frekvence je n – krát větší než fmax vstupního signálu
 - Klasické A/D převodníky využívají Shannonův teorém
 - (fvz = 2*fmax)
 - Mnohem větší počet vzorků => oversampling
 - Na základě komparátoru se přepíná výstup z D/A převodníku

- Číslicový filtr:
    - Potlačuje šum způsobený vzorkováním
- Decimace signálu:
    - Redukce délky signálu -> odstranění vybraných vzorků (např. každý n-tý -> n-krát kratší signál
- Vzorkovací kmitočty:
    - 44,1kHz / 96kHz / 192kHz
- Doba převodu jsou jednotky μs
- Levné, vysoké rozlišení (24, 32 bit), nízká spotřeba
- Digitální filtr, potlačují kvantizační šum
- Vhodné pro audiotechniku
![sig1]({{page.sig1 | relative_url}})
![sig2]({{page.sig2 | relative_url}})