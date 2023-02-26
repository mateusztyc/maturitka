---
layout: page
title: Zdroje PC, BIOS, UEFI a proces bootování PC
description: Otázka č.16 - Zdroje PC, BIOS, UEFI a proces bootování PC
has_children: false
nav_exclude: true
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
|          |**AT**|**ATX**|**BTX**|
|**Napětí**|+-5V, +-12V|+-5V, +-12V a 3,3V|+-5V, +-12V a 3,3V|
|**Konektory vedoucí do zakl desky**|Dva 6 pinové P8 a P9, černýma k sobě|20 pinové main power +4 pinový PW +12V AUX power|24 pinový main power +6 pinový PW +12V|
|**Zapínání**|HW – přímo 220V|SW – pomocí PS_ON|SW – pomocí PS_ON|