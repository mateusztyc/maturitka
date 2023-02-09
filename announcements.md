---
layout: page
nav_order: 1
title: Updates
nav_exclude: false
description: Updaty
---

# Nástěnka

Aktuální informace ke změnám na webu

{% assign announcements = site.announcements | reverse %}
{% for announcement in announcements %}
{{ announcement }}
{% endfor %}
