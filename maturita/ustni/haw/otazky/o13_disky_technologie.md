---
layout: page
title: Fyzická struktura pevných disků, charakteristika a technologie
description: Otázka č.13 - Fyzická struktura pevných disků, charakteristika a technologie
has_children: false
nav_exclude: true
tf1: /assets/images/13_tf_1.jpg
tf2: /assets/images/13_tf_2.jpg
mr: /assets/images/13_mr.jpg
lmr: /assets/images/13_lmr.jpg
pmr: /assets/images/13_pmr.jpg
geo1: /assets/images/13_geo1.jpg
geo2: /assets/images/13_geo2.jpg
prok: /assets/images/13_prokladani.jpg
hamr: /assets/images/13_hamr.jpg
mamr: /assets/images/13_mamr.jpg
---
# Fyzická struktura pevných disků, charakteristika a technologie
## Princip magnetického záznamu a čtení dat
- samotný disk je vyroben z nemagnetického materiálu – např. sklo, keramika nebo hliník
- povrch je pokryt vrstvou feromagnetického materiálu – většinou oxid železa
- např. oxid železitý, může být smíchán s dalšími látkami (oxid manganu nebo barya)
- má vysokou permeabilitu (vliv prostředí na magnetické pole)
- povrch je pokryt magnetickými doménami, které mají určitou orientaci
- při zápisu se mění jejich orientace pomocí hlavy, která obsahuje cívku
- uprostřed je cívka přerušena úzkou štěrbinou, která může být vyplněna látkou s nízkou permeabilitou, aby nedocházelo a nežádoucímu ovlivňování záznamu v nepravou chvíli
- čtení funguje na opačném principu než zápis (proud není převeden na indukci, ale naopak)
- magnetický záznam na vrstvě disku vyvolá na jádře cívky čtecí hlavy indukci, ta je převedena na elektrický proud, ten svou velikostí odpovídá uložené informaci
- nahrazeno modernějšími technologiemi jako MR, GMR

### Zápis (princip TF hlavy)
- Změnou polarity napětí na cívce se změní směr toku proudu v záznamové cívce magnetické hlavy, která způsobí změnu magnetického toku jedním nebo druhým směrem, který vnutí záznamové vrstvě orientaci -> 1 a 0
![TF]({{page.tf1 | relative_url}})
![TF2]({{page.tf2 | relative_url}})

### Čtení (princip MR hlavy)
- Jádrem MR hlavy je magnetorezistivní prvek, který je nad pohybující se záznamovou vrstvou, kde jsou různě orientované magnety, které změnou magnetického pole změní odpor, střída se 1 a 0
![MR]({{page.mr | relative_url}})

### Podélný zápis LMR
- Jednotlivé bity jsou uchovávaný vodorovně s plotnou disku
- Při vyšších hustotách dochází vlivem paramagnetismu k samovolné ztrátě uložených dat
- Jednotlivá magnetická pole (bity) se nedají uchovat izolovaná, vzájemně integrují a dochází ke ztrátě informace uložené na disku
![LMR]({{page.lmr | relative_url}})

### Kolmý zápis PMR
- Základními prvky jsou asymetrický elektromagnet a stabilizační vrstva.
- Stabilizační vrstva je umístěna pod záznamovou vrstvou a stará se o to, aby magnetické pole procházelo magnetizovatelnou látkou nikoli podélně, ale pokud možno kolmo.
- Asymetrická hlavička se stará o to, aby pole směřováno více do hloubky než do šířky.
- Tím jsou prvky záznamové plotny orientovány nikoli podélně, ale svisle.
- Díky svislé orientaci lze dosáhnout až pětinásobné hustoty zápisu
![PMR]({{page.pmr | relative_url}})

## Základní pojmy
### Hustota zápisu
- Počet bitů umístěních na jednotku plochy (bit/palec^2)
- Seagate dosáhl hustoty záznamu 1 Tbit/palec^2 (rok 2012)
### Záznamová vrstva
- Je tvořena z feromagnetického materiálu
- Jsou v ní uložená data
### Parkování hlaviček
- hlavičky parkují nejčastěji do středu disku
- pomalu se snesou po vzduchovém polštáři na plochu
- při nárazech zde hrozí porušení záznamové vrstvy
- bezpečnější je parkovat hlavičky mimo disk (vyjedou a zaparkují vedle)
### Vzduchový polštář
- tenká vrstva vzduchu, na které se vznáší hlavička nad povrchem disku
- jsou umístěny nad diskem v jednotkách mikrometrů
- recirkulační filtr – zachytává malé částečky prachu,
- které mohou vzniknout např. třením hlavy o povrch
- barometrický filtr – vyrovnává tlak uvnitř HDD přes ventil a to tak, že vzduch je buď nasáván, nebo vysáván
### Počet otáček za minutu
- udává se v RPM – rotates per minute
- u PC a notebooků nejčastěji 4200, 5400 a 7200 otáček za minutu
- u serverů nejčastěji 10000 a 15000 otáček za minutu
### Fyzické formátování - LOW LEVEL FORMAT
- formátování prováděné výrobcem pevného disku
- provádí se pomocí laseru a přesného nastavení hodnot proudu v cívce vystavovacího mechanismu
- cílem je přesné nastavení hlaviček vystavovacího mechanismu

## Charakteristika 
- PC zařízení, které slouží k trvalému nebo dočasnému ukládání dat, ukládají se zde všechny nainstalované programy, data, OS
- Data se uchovávají pomocí magnetické indukce
- Výhoda je rychlé čtení dat, nízká cena a velká kapacita disku
- Nevýhoda je spotřeba energie, mechanické řešení, snadné poškození při špatném zacházení

## Geometrie HDD
- Stopa
    - soustředná kružnice na povrchu plotny sloužící k záznamu dat
    - Současné pevné disky používají stopy s šířkou 50 až 30 nm, přičemž limitem perpendikulární technologie je 25 nm
    - Číslování od 0 od obvodu dovnitř
    - Hustota stop 30 000 – 50 000 tpi
- Sektor
    - Kruhová výseč jedné stopy
    - Nejmenší možný adresovatelný prostor
    - Čísluje se proti směru otáčení disku na jednotlivých stopách od 1
    - Skládá se z:
        - Identifikační části – adresa sektoru CHS
        - 512B dat
        - CRC zabezpečení dat
- Cylindr
    - Tvoří stopy se stejným průměrem na jednotlivých površích ploten nacházející se v zákrytu za sebou
    - Všechny stopy, které jsou pod sebou
    - Tolik, kolik je cylindrů, je i stop
    - Čísluje se od obvodu dovnitř
![GEO1]({{page.geo1 | relative_url}})
![GEO2]({{page.geo2 | relative_url}})

## Adresování CHS a LBA
### CHS
- Trojrozměrné číslování
- Určuje jednoznačnou pozici dat
- Adresace podle geometrie disku – Cylindr Hlava Sektor
- Číslování od 001, na začátku disku je Master boot record a partition table
### LBA
- 48 bitová adresa – dokáže zaadresovat až 2 na 48 – 128 milionu GB
- Modernější varianta adresování
- Používá lineární adresaci
    - Není třeba znát geometrii disku, který byla u nových disků prakticky k ničemu
- Číslování od 0 (LBA0, LBA1) CHS 001 = LBA0

## Vystavovací mechanismus
- Je to „strojek“ zajišťující pohyb hlavičky nad povrchem disku
- Kdysi krokový motor, kovový pásek
- V současnosti vystavovací cívka
    - Cívka s určitým počtem závitů a určité ploše uložena v permanentním magnetickém poli
    - Změnou proudu v cívce dojde k nasměrování hlaviček nad požadovanou stopu
    - Na stopu 0 se dostanu např proudem 2mA, na stopu 1 4mA
- Výhodou tohoto mechanismu je velká přesnost a spolehlivost

## Teplotní kalibrace (TCAL)
- Během provozu se pevný disk neustále zahřívá, tím může dojít k mírným změnám v umístění hlaviček nad příslušnými stopami, které mohou měnit teplotou své vlastnosti (roztahují se)
- Z tohoto důvodu se musí kontrolovat poloha hlaviček a musí být prováděna kalibrace (oprava polohy hlaviček nad stopou)
- zavedeno kvůli potřeby velké přesnosti umístění hlavičky nad stopou disku
- Na moderních discích se kalibrace provádí za pochodu

## Přístupová doba
- je to doba, za kterou je disk schopen pracovat s daty
- skládá se ze tří dob:
    - vystavovací doba – doba, než se hlavička dostane nad správnou pozici
    - rotační čekací doba – doba, než se plotna otočí na správnou pozici
    - přepnutí na jednotlivou hlavičku – hradlo, řádově nanosekundy
- průměrná přístupová doba je v jednotkách milisekund
- nejpomalejší jsou mechanické součásti pevného disku

## Prokládání
- rychlost otáčení pevného disku je poměrně vysoká, proto se může stát, že poté, co je přečten (zapsán) jeden sektor a data jsou předána dále, dojde k pootočení disku, takže se hlavičky nenacházejí nad následujícím sektorem, ale až nad některým z dalších sektorů
- muselo by se tedy čekat, než budou hlavy nad požadovaným sektorem a po provedení dalšího čtení (zápisu) by se situace znovu opakovala
- tento způsob by velmi zpomaloval práci pevného disku
- řešením je faktor prokládání pevného disku
- data nejsou zapisována (a posléze čtena) do sektorů hned za sebou, ale jsou vždy zapsána během jedné otáčky disku do každého n-tého sektoru
- faktor prokládání 1:n, kde číslo n je voleno tak, aby po přečtení a zpracování dat z jednoho sektoru, byla hlavička nad dalším požadovaným sektorem
![Prokldani]({{page.prok | relative_url}})

## Kódování
- data se na disk ukládají pomocí změn magnetického toku, tato změna může nastat buď z kladného toku na záporný, nebo naopak
- každá taková změna se při čtení projevuje jako impuls
- k reprezentaci dat se tedy používá přítomnosti nebo nepřítomnosti impulsu (mezera)
- teoreticky by mohla být „0“ zaznamenána pouze jako mezera, ale v praxi by nastal problém při větším počtu nul, kdy by řadič mohl ztratit synchronizaci, a tudíž by nebylo jasné, kolik nul (mezer) bylo doopravdy přečteno
- tento problém řeší kódování dat
- **FM = frekvenční modulace**
    - 0 se kóduje jako PN, 1 jako PP
    - P značí impuls a M mezeru
    - Zabírá mnoho místa, tímto se na disk vleze podstatně méně dat
    - Dnes se již nepoužívá
- **MFM = modifikovaná FM**
    - Snaha o zmenšení počtu impulsů
    - 0 je kódována jako PN, pokud je v řetězci 00
    - Pokud je v řetězci 10, je kódována jako NN
    - 1 je kódována jako NP
    - Zmenšení velikosti přibližně o 20%
- **RLL modulace**
    - Jednotlivé vzorky a jejich zakódování jsou voleny tak, aby mezi dvěma impulsy byly minimálně dvě a maximálně sedm mezer
    - Asi o 50% úspornější než MFM
    - Používáno u starších pevných disků
- **PRML, extended PRML, extended partial response**

## Prekompenzace
- Každý sektor na disku stejnou velikost a nezáleželo na jeho fyzickém umístění na disku
- Data ve středu disku byla velmi natěsnaná, to vedlo k magnetické nestálosti záznamu a slučování bitových informací
- U stop, které jsou ve středu kružnice, proto řadič ukládá data tak, aby pro vzájemném působení mag. sil byla správně uložena
- Pokud by se nevyužilo tohoto ošetření, byla by data na disku velmi nestálá a z pevného disku by se stalo nespolehlivé zařízení

## ZBR - Zone Bit Recording
- Zónový záznam
- plocha pevného disku je rozdělena na zóny, jedna zóna obsahuje více stop
- ZBR byl zaveden tak, že v delších stopách (na kraji disku) je sektorů více a v kratších stopách (uprostřed) je jich méně, ale jsou všude stejně velké
- Tím se předchází magnetickému uvolňování dat

## MTBF - Mean Time Before Failures
- střední doba mezi poruchami
- v praxi se vezmou pevné disky a jedou až do doby poruchy prvního a druhého, z těchto dvou časů se posléze udělá průměr a ten značí MTBF
- lze taky udělat pomocí různých simulací

## SMART - Self Monitoring Analzsis and Reporting Technology
- monitorovací systém pro pevné disky
- během provozu jsou uvnitř pevného disku sledovány různé parametry
- díky nich může správce disku předvídat různá selhání disku a včas zálohovat data
- Při detekci kritických hodnot dojde k odeslání varování operačnímu systému
- **Předvídatelné chyby**
    - Mezní výška hlaviček nad záznamovou vrstvou
    - Počet vadných sektorů
    - Čas potřebný k roztočení ploten
    - Teplota disku
- **Nepředvítalné chyby**
    - Náhlé napětí
    - Mechanická poškození
    - Nadměrné teplo
    - Vliv vnějšího magnetického pole

## SMR technologie
- Diskové hlavy zapisují pomocí silného magnetického pole do mírně se překrývajících magnetických stop
- Pro umožnění čtení tenčí stopy, stejně jak u kolmého zápisu

## HAMR
- HAMR dokáže zapisovat data do velice tenkých stop na diskové plotně, ovšem vyžaduje k tomu záznamovou vrstvu z materiálu, s jehož polaritou si lze hrát při vysokých teplotách. Využívá se laser pro zahřívání před zápisem- velice složité na výrobu.
- Díky technologii hamr bude možno bez problémů zdvojnásobit kapacitu současných disků
![HAMR]({{page.hamr | relative_url}})

## MAMR
- Zahřívá místo na disku, do kterého se má informace zapsat pomoci mikrovln
- Pro stejné účely jako HAMR
![MAMR]({{page.mamr | relative_url}})