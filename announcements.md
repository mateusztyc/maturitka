---
layout: page
nav_order: 1
title: Aktuality
nav_exclude: false
description: Aktualní příspěvky
---

# Nástěnka

Aktuální informace ke změnám ve výuce a jiné volatilní informace.

{% assign announcements = site.announcements | reverse %}
{% for announcement in announcements %}
{{ announcement }}
{% endfor %}
