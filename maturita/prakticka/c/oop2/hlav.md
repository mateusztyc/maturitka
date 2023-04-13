---
layout: page
title: Databaze OOP
description: Databaze OOP C++
has_children: false
nav_exclude: true
---

    #ifndef HLAVICKA_H
    #define HLAVICKA_H

    #include <iostream>
    #include <fstream>
    #include <cstring>
    using namespace std;

    class hokejista{
    private:
        int cislo;
        string jmeno;
        string prijmeni;
        int rok;
        int body;
        
    public:
        hokejista();
        hokejista(int icislo);
        hokejista(int icislo, string ijmeno);
        hokejista(int icislo, string ijmeno, string iprijmeni);
        hokejista(int icislo, string ijmeno, string iprijmeni, int irok);
        hokejista(int icislo, string ijmeno, string iprijmeni, int irok, int ibody);
        int Dejcislo(){return cislo;}
        string Dejjmeno(){return jmeno;}
        string Dejprijmeni(){return prijmeni;}
        int Dejrok(){return rok;}
        int Dejbody(){return body;}
        friend ostream&operator<<(ostream &vystup, hokejista x);
        friend istream&operator>>(istream &vstup, hokejista &x);
        
    };

    class klub{
    private: 
        hokejista pole[100];
        int pocet;

    public:
        klub();
        int Dejpocet(){return pocet;}
        friend ostream &operator<<(ostream &vystup, klub x);
        bool pridat(hokejista novy);
        bool uloz();
        bool nacti();
        int odstranit();
        int hledcis();
        int hledjm();
        int rozsah();
        void razb();
        void razp();
        void nej();
        void minmax();
        int soucet();
    };


    #endif