---
layout: page
nav_order: 1
title: Update Log
nav_exclude: false
description: Updates
---

# Update log

Aktuální informace ke změnám na webu

{% assign announcements = site.announcements | reverse %}
{% for announcement in announcements %}
{{ announcement }}
{% endfor %}
