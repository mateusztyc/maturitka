---
layout: page
parent: Výuka
title: Počítačové sítě
description: Materiály k předmětu POS.
subject: pos
---

# (POS) Počítačové sítě

Materiály k předmětu POS. **Prezentace jsou aktuálně dostupné pouze ve škole (AKA po připojení k intranetu)!**

{% for module in site.modules %}
{% if module.subject == page.subject %}
{{ module }}
{% endif %}
{% endfor %}
