---
layout: page
title: Slovnik
description: Slovník
has_children: false
nav_exclude: true
---

		#ifndef SLOVNIK_H
	#define SLOVNIK_H

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <time.h>

	int pocet_slov(char soubor);
	int pridat(char soubor[]);
	int preklad(char soubor[], char prekladd[]);
	void testovani(char soubor[]);
	void rand_test(char soubor[], int pocet);
	void odstraneni(char soubor[],char slovo_odstr[]);
	#endif