---
layout: page
title: Slovnik
description: Slovník
has_children: false
---

    #ifndef ZLOMEK_H
    #define ZLOMEK_H

    #include <iostream>
    using namespace std;

    class Zlomek {
    public:
	    Zlomek();
	
	    friend istream& operator>>(istream& in, Zlomek &z);
	    friend ostream& operator<<(ostream& out, Zlomek z);
	
	    Zlomek operator+(Zlomek z);
	    Zlomek operator-(Zlomek z);
	    Zlomek operator*(Zlomek z);
	    Zlomek operator/(Zlomek z);
	
	    int porovnat(Zlomek z);
    private:
	    int cit, jmen;
	
	    Zlomek krac();
	    int gcd(int a,int b);
	    int lcm(int a, int b);
    };

    #endif