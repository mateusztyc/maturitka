---
layout: page
title: Databaze OOP
description: Databaze OOP C++
has_children: false
nav_exclude: true
---

    #include "hlavicka.h"

    klub::klub(){
        pocet=0;
    }

    ostream &operator<<(ostream &vystup, klub x){
        for(int i=0;i<x.Dejpocet();i++){
            vystup << x.pole[i] << endl;
        }
        return vystup;
    }

    bool klub::pridat(hokejista novy){
        int pridano=0;
        
        this->pole[this->pocet]=novy;
        this->pocet++;
        pridano++;
        
        return true;
    }

    bool klub::uloz(){
        ofstream soubor;
        soubor.open("bozka.txt");
        
        if(soubor.fail()){
            cout << "Chyba pri otevreni souboru";
            return false;
        }
        
        for(int i=0;i<pocet;i++){
            soubor << pole[i].Dejcislo() << "$";
            soubor << pole[i].Dejjmeno() << "$";
            soubor << pole[i].Dejprijmeni() << "$";
            soubor << pole[i].Dejrok() << "$";
            soubor << pole[i].Dejbody() << "$";
        }
        
        soubor.close();
        
        return true;
    }

    bool klub::nacti(){
        ifstream soubor;
        int i=0,ncislo,nrok,nbody;
        string radek, njmeno, nprijmeni;
        
        soubor.open("bozka.txt");
        
        if(soubor.fail()){
            cout << "Chyba pri otevreni souboru";
            return false;
        }
        
        while(getline(soubor,radek,'$')){
            i++;
            switch(i) {
            case 1:
                ncislo=atoi(radek.c_str());
                break;
            case 2:
                njmeno=radek;
                break;
            case 3:
                nprijmeni=radek;
                break;
            case 4:
                nrok=atoi(radek.c_str());
                break;
            case 5:
                nbody=atoi(radek.c_str());
                i=0;
                hokejista novy(ncislo,njmeno,nprijmeni,nrok,nbody);
                pridat(novy);
                break;
            }
        }
        
        soubor.close();
        return true;
    }

    int klub::odstranit(){
        int pom=0, hledcislo;
        
        
        cout << "Zadejte cislo hrace pro odstraneni:";
        cin >> hledcislo;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejcislo()==hledcislo){
                for(int j=i;j<pocet;j++){
                    pole[j]=pole[j+1];
                    pom=1;
                }
            }
        }
        
        pocet=pocet-1;
        return pom;
    }

    int klub::hledcis(){
        int pom=0,hlcis=0;
        hokejista g;
        
        cout << "Zadejte hledane cislo hrace: ";
        cin >> hlcis;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejcislo()==hlcis){
                g=pole[i];
                pom=1;
            }
        }
        
        cout << g.Dejcislo() << "|" << g.Dejjmeno() << "|" << g.Dejprijmeni() << "|" << g.Dejrok() << "|" << g.Dejbody();
        return pom;

    }

    int klub::hledjm(){
        int pom=0;
        hokejista g;
        string hlpj;
        
        fflush(stdin);
        
        cout << "Zadejte hledane prijmeni: ";
        cin >> hlpj;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejprijmeni()==hlpj){
                g=pole[i];
                pom=1;
            }
        }
        
        cout << g.Dejcislo() << "|" << g.Dejjmeno() << "|" << g.Dejprijmeni() << "|" << g.Dejrok() << "|" << g.Dejbody();
        return pom;
        
        
        return pom;
    }

    int klub::rozsah(){
        int min,max,pom=0;
        hokejista g;
        
        fflush(stdin);
        
        cout << "Zadejte spodni hranici: ";
        cin >> min;
        cout << "Zadejte vrchni hranici: ";
        cin >> max;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejbody()>min && pole[i].Dejbody()<max){
                g=pole[i];
                cout << g.Dejcislo() << "|" << g.Dejjmeno() << "|" << g.Dejprijmeni() << "|" << g.Dejrok() << "|" << g.Dejbody() << endl;
                pom=1;
            }
        }
        
        
        return pom;
    }

    void klub::razb(){
        hokejista pom;
        
        for(int j=pocet-1; j>= 0; j--){
            for(int i=0;i<j;i++){
                if(pole[i].Dejbody() > pole[i+1].Dejbody()){
                    pom=pole[i];
                    pole[i]=pole[i+1];
                    pole[i+1]=pom;
                }
            }
        }
    }

    void klub::razp(){
        hokejista pom;
        
        for(int j=pocet-1; j>= 0; j--){
            for(int i=0;i<j;i++){
                if(pole[i].Dejprijmeni() > pole[i+1].Dejprijmeni()){
                    pom=pole[i];
                    pole[i]=pole[i+1];
                    pole[i+1]=pom;
                }
            }
        }
    }

    void klub::nej(){
        int max;
        hokejista g;
        
        max=pole[0].Dejbody();
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejbody()>max){
                max=pole[i].Dejbody();
            }
        }
        cout << "Nejlepsi hokejisti jsou: " << endl;
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejbody()==max){
                g=pole[i];
                cout << g.Dejcislo() << "|" << g.Dejjmeno() << "|" << g.Dejprijmeni() << "|" << g.Dejrok() << "|" << g.Dejbody() << endl;
            }
        }
    }

    void klub::minmax(){
        int min,max;
        hokejista g;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejbody()>max){
                max=pole[i].Dejbody();
                g=pole[i];
            }
        }
        
        cout << "Nejlepsi hrac" << endl;
        cout << g.Dejcislo() << "|" << g.Dejjmeno() << "|" << g.Dejprijmeni() << "|" << g.Dejrok() << "|" << g.Dejbody() << endl;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejbody()<min){
                min=pole[i].Dejbody();
                g=pole[i];
            }
        }
        
        cout << "Nejhorsi hrac" << endl;
        cout << g.Dejcislo() << "|" << g.Dejjmeno() << "|" << g.Dejprijmeni() << "|" << g.Dejrok() << "|" << g.Dejbody() << endl;
        
    }

    int klub::soucet(){
        int soucet=0;
        
        for(int i=0;i<pocet;i++){
            soucet=soucet+pole[i].Dejbody();
        }
        
        return soucet;
    }