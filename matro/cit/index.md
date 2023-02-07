---
layout: page
parent: Výuka
title: Číslicová technika
description: Materiály k předmětu CIT.
subject: cit
has_children: true
---

# (CIT) Číslicová technika

Materiály k předmětu CIT.

{% for module in site.modules %}
{% if module.subject == page.subject %}
{{ module }}
{% endif %}
{% endfor %}
