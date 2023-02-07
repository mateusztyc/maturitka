---
layout: page
parent: Výuka
title: Operační systémy
description: Materiály k předmětu OPS.
subject: ops
---

# (OPS) Operační systémy

Materiály k předmětům OPS3 a OPS4.

[Školní HAL - next gen. ]({{ site.baseurl }}/files/spse_stm32kit.zip){: .btn .btn-green }
[HAL - čistý]({{ site.baseurl }}/files/stm32_kit_clean-1.0.0.zip){: .btn .btn-blue}
[HAL - RTOS]({{ site.baseurl }}/files/stm32kit_rtos.zip){: .btn .btn-purple}

{% for module in site.modules %}
{% if module.subject == page.subject %}
{{ module }}
{% endif %}
{% endfor %}
