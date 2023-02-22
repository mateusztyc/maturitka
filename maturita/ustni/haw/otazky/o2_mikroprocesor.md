---
layout: page
title: Mikroprocesor
description: Otázka č.2 - Mikroprocesor
has_children: false
nav_exclude: true
image1: /assets/images/mikropocitac.jpg
image2: /assets/images/cinnost.jpg
image3: /assets/images/neumann.jpg
image4: /assets/images/harvard.jpg
image5: /assets/images/soc.jpg
image6: /assets/images/ahb1.jpg
image7: /assets/images/moder.jpg
image8: /assets/images/idr.jpg
image9: /assets/images/odr.jpg
image10: /assets/images/bsrr.jpg
image11: /assets/images/trigger.jpg
image12: /assets/images/diagram.jpg
---
# Mikroprocesor
- Lze definovat jako sekvenční automat vyrobený technologií VLSI(Very Large Scale Integration)
- Je tvořen řadičem, ALU(aritmetická jednotka) a pracovními registry
- Bez podpůrných obvodů není schopen provozu
- Mikropočítač vznikne připojením k paměti vstupních a výstupních bloků (je rozšířen o paměť, vstupní a výstupní bloky)
- Mikropočítač doplněný o periferie umožňující komunikaci s uživatelem (monitor, klávesnice, myš, vnější paměť) pak tvoří mikropočítačový systém

![Mikropočítač]({{page.image1 | relative_url}})

## Mikroprocesor - abstrakce
- Výpočetní systém si lze představit jako člověka -> řadič
    - Ten ovládá kalkulačku -> ALU
        - Ovládání je dáno programem -> instrukce
- Člověk zadává údaje přes klávesnici
     - Vstupní jednotka
- Výsledky výpočtu jsou vidět na displeji
     - Výstupní jednotka
- Na stole jsou položeny hodiny
    - Každou minutu je proveden další příkaz (instrukce)
- Příkazy na papíru jsou zpracovány sekvenčně
    - Program Counter

## Mikroprocessor - činnost
![Činnost]({{page.image2 | relative_url}})

## Architektury
- ### Von Neumannova architektura
    - Vznikla 1945
    - Obsahuje 5 základních částí
    - **základem dnešních výpočetních strojů** - s jistými změnami jako je multitasking, víceprocesorové systémy, vstupně-výstupní zařízení, program nemusí být celý zaveden v OP
![Neumann]({{page.image3 | relative_url}})
    - Instrukce i data jsou členěny do slov/slabik stejného formátu (8-bit velikost) – jsou uloženy ve společné paměti a nejsou nijak speciálně rozlišeny
    - V společné paměti hrozí přepsání dat
    - Data zpracovává sekvenčně (posupně) oproti harvardské, která je zpracovává paralelně
    - **SPECIFIKACE:**
        - struktura PC je nezávislá na řešeném problému
        - V paměti jsou data uloženy společně s instrukcemi programu (binárně zakódovány)
        - Paměť je rozdělena na buňky stejně velikosti a přistupuje se k nim pomocí adresy
        - Program tvoří posloupnost instrukcí – jsou prováděny sekvenčně vyjma skokových instrukcí
- ### Harvardská architektura
![Harvard]({{page.image4 | relative_url}})
    - Snaží se řešit problém Von Neumannovy metody -> zavádí 2 paměti – 1 pro program a 1 pro data
    - Paměti můžou být různého typu a velikosti
    - Nedají se kombinovat – pokud dojde paměť pro data nemůžeme je uložit nikam jinam
    - 2 sběrnice pro každou jednu paměť -> náročnější na řízení (fyzické rozdělení paměti)
    - Nenastane situace vlastního přepsání
    - Je možné pracovat najednou jak s instrukcemi tak s daty (souběžný přístup) -> vyšší nároky na vývoj řídící jednotky
    - Řízení CPU je odděleno od řízení VV jednotek – nejsou napojeny přímo na ALU
    - Atmel 8051, ARM – většinou kombinace obou architektur

## ARM
-  První ARM vyrobila firma Acron Computers – 1978 Cambridge
- **Vize:** Vývoj osobního PC pro firmy a domácnosti, který by používal redukovanou instrukční sadu **RISC:**
    - zjednodušení příkazů (instrukcí)
    - zrychlení samostatného zpracování instrukcí
    - více jednoduchých po sobě následujícíh instrukcí místo složitých instrukcí vykonávající složité operace (CISC)

#### Acron Archimedes
- První PC vybavený ARMem. Projekt byl bohužel neúspěšný -> firma krachla

#### Newton MessagePad
- Postaven na ARM procesoru (ARM 610 RISC)
- Newton OS
- Osobní digitální asistent od firmy Apple(1993)

### Arm Holdings
- Britská společnost založena 1990
- Vyvíjí a následně licencuje své technologie
    - Drží duševní vlastnictví
    - Samotné procesory nevyrábí
        - Vyrábí/staví konkrétní modely až samotní výrobci
        - Apple, Nvidia, Qualcomm, Samsung,…

### ARM
- Advanced Risc machine (acron risc machine)
- 32/64 bit architektury označovány ARMvX
    - Názvy jader jsou označovány jako Cortex
        - Cortex-A55 -> ARMv8.2
        - tex-M4 -> ARMv7
- Nejrozšířenější architektura mikroprocesorů
    - Ročně vyrobeno přes cca 50 miliard
    - Mobily, tablety, přenosné herní konzole, ...
    - Routery, televize, automobilovém průmysl, …
- **big.LITTLE architektura**
    - V rámci jednoho pouzdra jsou obsaženy jak výkonné (big) čipy, tak ty úsporné (LITTLE)
    - Čipy mohou být aktivována jednotlivě
    - Rozložení výkonu (video, email, …)
- Load/Store architektura
    - S pamětí pracují pouze instrukce typu load a store
    - Všechny ostatní instrukce pracují s vnitřními registry
        - Operandy apod. jsou nachystány do těchto registrů
    - Rozdělení na dvě kategorie
        - Práce s pamětí (load/store)
        - Práce s registry a ALU
    - **Výkon** = V dnešní době dostatek výkonu pro zastoupení PC
        - Huawei Mate 20 Pro a Huawei Dock
        - Samsung Galaxy Note 9 a Samsung DexPad

### ARM jako součást SoC
- System on Chip – „vše“ na jednom čipu
- **Integruje:**
    - Grafické jádro
    - Operační paměť
    - Síťový čip
    - I/O rozhraní
    - Modul pro komunikaci v mobilní síti
    - Modem, ...
- **Výhody**:
    - Levnější výroba
    - Nižší spotřeba
    - Vysoká míra integrace
- Malá možnost HW konfigurace
![SOC]({{page.image5 | relative_url}})

## STM32F4
- STM32F407VGT6
    - TM32F407G-DISC1
- 32-bit ARM Cortex M4 s FPU
    - RISC architektura
    - 5ti stupňový pipeline
- 1MB Flash
- 192+4 KB RAM
- Memory protection unit
- CLK až 168 MHz
- Vnitřní 16 MHz nebo 32 kHz RC
- Debug nástroj ST-LINK/V2
- **Podpora pamětí typu:**
    - Compact Flash, NAND, NOR, SRAM, PSRAM
- 3x 12b A/D
- 2x 12b D/A
- **Podpůrné obvody:**
    - DMA, Watchdog, PLL, PWM
- 14 časovačů
    - 16/32b
- 140 I/O pinů s možností přerušení
- 3x I2C a SPI
- 4x USART
- Podpora USB 2.O
- Síťová karta 10/100 Mb/s
    - DMA
- Skutečný generátor náhodných čísel
- Výstup 3 nebo 5 V
- 8x LED
    - 4x uživatelské (PD12 - PD15)
- 2x tlačítko
    - Uživatelské (modré) a reset (černé)
- Porty A-K
    - Pro uživatele: A-E
- Napájení 5V
    - USB nebo externí zdroj
- Včetně programátoru
    - Možnost programovat i jiné desky

### Sběrnice
#### AHB
- Advanced High-performance Bus
    - Nástupce ASB (první generace AMBA)
- Pro velmi rychlou komunikaci mezi:
    - CPU
    - RAM
    - DMA
- Podpora dávkového přenosu dat
- Most pro komunikaci s APB

#### APB
- Advanced Peripheral Bus
- Nabízí jednoduchý interface pro připojení pomalejší a low-power periférií k procesoru
    - Čaovače
    - UART
    - I2C, SPI
- Periférie komunikují s CPU prostřednictvím mostu mezi AHB a APB

#### RCC->AHB1ENR – AKTIVACE PŘISLUŠNÉHO PORTU
![AHB1ENR]({{page.image6 | relative_url}})
#### GPIOx->MODER – nastavení modu příslušného portu
![MODER]({{page.image7 | relative_url}})
#### GPIOx->IDR – vstup dat
![IDR]({{page.image8 | relative_url}})
#### GPIOx->ODR – výstup dat
![ODR]({{page.image9 | relative_url}})
#### GPIOx->BSRR – nastavení/resetovaní bitu
![BSRR]({{page.image10 | relative_url}})

## STM32F4 - školní kit
- LCD 8x2
- Klávesnice 4x3
- 4x LED
    - Opačná logika než u vestavěných LED
    - Port E (piny 12-15)
- COM port
- Fotorezistor (10 kOhm)
- Reproduktor
    - Pod klávesnicí, né u všch

## Keil uVision 5
- uint8_t;
    - Unsigned integer 8 bit
    - _t -> standart pro "type" (typedef)
- 1UL
    - Unsigned long

## Časování
### Zdroje CLK
- Možnost celkem 3 různých zdrojů CLK
    - HSI oscilátor CLK
    - HSE oscilátor CLK
    - PLL
- HSI clock (High-Speed Internal clock)
    - Signál je generován z interního 16 MHz RC oscilátoru
    - Není potřeba žádných dalších externích součástek
    - Není tak přesný jako externí zdroj CLK
    - Možnost sw kalibrace (využití některého z TIMerů)
    - Po restartu je vybrán automaticky jako systémový CLK
- Využití: Ethernet, USB, I2C, UART, systémové hodiny, …

### System Tick Timer - SysTick
- Jednoduchý interní systémový časovač
- Součástí jádra Cortex
- Při odečtení vyvolá přerušení
    - Periodicky odčítá jedničku od uživatelem definované hodnoty
- Využití pro:
    - Pravidelná kontrola sériového kanálu, klávesnice, tlačítek
    - Práce s LCD – časování pro driver
    - Nebo pro začátek blikání LED
- Není možné přidělit prioritu, ani jinak nastavovat
    - O vše se stará SysTick_Config()
- SysTick_Config(“hodnota“);
    - Funkce pro konfiguraci přerušení od SysTick
    - Číslo musí být menší než 224 -> 16 777 216
    - Nejjednodušší zadat fJádra = 16 MHz (po resetu)
        - Podtečení každou 1s
- Nutno však definovat rutinu pro obsluhu přerušení SysTick_Handler()
- SystemCoreClockUpdate();
    - Nahrání frekvence jádra do SystemCoreClock
- RCC->CFGR & RCC_CFGR_SWS
    Zjíštění zdroje CLK

### TIM6, TIM7 - základní časovače
- 16 bit časovače respektive vzestupné čítače s možností auto-reload
- Součástí je i 16 bit programovatelný prescaler
    - Využívaná jako dělička frekvence
- Při přetečení nebo auto-reload může být generováno přerušení nebo signál pro DMA
- Možnost využít také pro řízení DAC
    - Vnitřně spojeny s DAC prostřednictvím „trigger output“
![Trigger]({{page.image11 | relative_url}})

## Bity
- Update Generation (UG)
    - Nastavuje se v TIMx_EGR
    - Povolení vyvolání přerušení pro přetečení časovače

- Auto-Reload Preload Enable bit (ARPE)
    - Nastavuje se v TIMx_CR1
    - Zda bude přednačzena hodnota z auto-reload registru

- Counter Enable Bit (CEN)
    - Nastavuje se v TIMx_CR1
    - Povolení časovače, jinak neběží

- Update Interrupt Flag (UIF)
    - Nastaven v TIMx_SR při přetečení
    - Nutno ručně nulovat

## Registry
- Control Register 1
    - TIMx_CR1
    - Základní nastavení časovače

- Control Register 2
    - TIMx_CR2
    - Určen k nastavení triggeru (Využito u DA)

- Status Register
    - TIMx_SR
    - Obsahuje informaci o přetečení časovače

- Counter Register
    - TIMx_CNT
    - Možnost čtení nebo zápisu hodnoty i za běhu časovače

- Prescaler Register
    - TIMx_PSC
    - Zde je uložena hodnota pro dělení signálu

- Auto-Reload Register
    - TIMx_ARR
    - Uložena hodnota, při které se má čitač restartovat

- Event Generation Register
    - TIMx_EGR
    - Obsahuje povolení generování UEV (update event), kdy dojde k aktualizaci čítače a jeho restartu

## ARM blokový diagram
![Diagram]({{page.image12 | relative_url}})