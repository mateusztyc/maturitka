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

    class zak{
    private:
        int ID;
        string jmeno;
        string prijmeni;
        int mat;
        int cej;
        int cja;
        string hodnoceni;
        
    public:
        zak();
        zak(int iID);
        zak(int iID, string ijmeno);
        zak(int iID, string ijmeno, string iprijmeni);
        zak(int iID, string ijmeno, string iprijmeni, int imat);
        zak(int iID, string ijmeno, string iprijmeni, int imat, int icej);
        zak(int iID, string ijmeno, string iprijmeni, int imat, int icej, int icja);
        zak(int iID, string ijmeno, string iprijmeni, int imat, int icej, int icja, string ihodnoceni);
        int DejID(){return ID;}
        string Dejjmeno(){return jmeno;}
        string Dejprijmeni(){return prijmeni;}
        int Dejmat(){return mat;}
        int Dejcej(){return cej;}
        int Dejcja(){return cja;}
        string Dejhodnoceni(){return hodnoceni;}
        friend ostream&operator<<(ostream &vystup, zak x);
        friend istream&operator>>(istream &vstup, zak &x);
    };

    class trida {
    private:
        zak pole[100];
        int pocet;
        
    public:
        trida();
        int Dejpocet(){return pocet;}
        friend ostream &operator<<(ostream &vystup, trida x);
        int pridat(zak novy);
        bool uloz();
        bool ze_souboru();
        int hledaniid();
        int hledanijm();
        int odstraneni(int hledid);
        void editace();
        void razeni();
        void nejvysl();
        void prmr();
    };


    #endif