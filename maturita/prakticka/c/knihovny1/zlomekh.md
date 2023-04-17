---
layout: page
title: Knihovny 1
description: Knihovny 1
has_children: false
nav_exclude: true
---
    #ifndef ZLOMEK_H
    #define ZLOMEK_H

    #include<iostream>
    #include<numeric>
    using namespace std;

    class Zlomek {
    private:
        int cit,jm;

    public:
        Zlomek();
        
        int Dejcit(){return cit;};
        int Dejjm(){return jm;}
        friend istream& operator>>(istream& in, Zlomek &x);
        friend ostream& operator<<(ostream& out, Zlomek x);
        
        Zlomek operator+(Zlomek x);
        Zlomek operator-(Zlomek x);
        Zlomek operator*(Zlomek x);
        Zlomek operator/(Zlomek x);
        
        Zlomek kraceni(Zlomek x);
        int porovnani(Zlomek x);
        
        
    };

    #endif