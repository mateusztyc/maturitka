---
layout: page
title: Databaze OOP
description: Databaze OOP C++
has_children: false
nav_exclude: true
---

    #include "hlavicka.h"

    hokejista::hokejista(){
        cislo=0;
        jmeno="";
        prijmeni="";
        rok=0;
        body=0;
    }

    hokejista::hokejista(int icislo){
        cislo=icislo;
        jmeno="";
        prijmeni="";
        rok=0;
        body=0;
    }

    hokejista::hokejista(int icislo, string ijmeno){
        cislo=icislo;
        jmeno=ijmeno;
        prijmeni="";
        rok=0;
        body=0;
    }

    hokejista::hokejista(int icislo, string ijmeno, string iprijmeni){
        cislo=icislo;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        rok=0;
        body=0;
    }

    hokejista::hokejista(int icislo, string ijmeno, string iprijmeni, int irok){
        cislo=icislo;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        rok=irok;
        body=0;
    }

    hokejista::hokejista(int icislo, string ijmeno, string iprijmeni, int irok, int ibody){
        cislo=icislo;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        rok=irok;
        body=ibody;
    }

    ostream &operator<<(ostream &vystup, hokejista x){
        vystup << x.cislo << "|" << x.jmeno << "|" << x.prijmeni << "|" << x.rok << "|" << x.body << endl;
        return vystup;
    }

    istream &operator>>(istream &vstup, hokejista &x){
        cout << "Zadejte cislo hrace:" << endl;
        vstup >> x.cislo;
        fflush(stdin);
        cout << "Zadejte jmeno hrace" << endl;
        getline(vstup, x.jmeno);
        cout << "Zadejte prijmeni hrace" << endl;
        getline(vstup, x.prijmeni);
        fflush(stdin);
        cout << "Zadejte rok narozeni hrace" << endl;
        vstup >> x.rok;
        cout << "Zadejte body" << endl;
        vstup >> x.body;
        
        return vstup;
    }