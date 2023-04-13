---
layout: page
title: Databaze OOP
description: Databaze OOP C++
has_children: false
nav_exclude: true
---

    #include "hlavicka.h"

    trida::trida(){
        pocet=0;
    }

    ostream &operator<<(ostream &vystup, trida x){
        for(int i=0;i<x.Dejpocet();i++){
            vystup << x.pole[i] << endl;
        }
        return vystup;
    }

    int trida::pridat(zak novy){
        int pridano=0;
        
        this->pole[this->pocet]=novy;
        this->pocet++;
        pridano++;
        
        return true;
    }

    bool trida::uloz(){
        ofstream soubor;
        soubor.open("petko.txt");
        
        if(soubor.fail()){
            cout << "Chyba pri otevreni souboru";
            return false;
        }
        
        for(int i=0;i<pocet;i++){
            soubor<<pole[i].DejID()<<"$";
            soubor<<pole[i].Dejjmeno()<<"$";
            soubor<<pole[i].Dejprijmeni()<<"$";
            soubor<<pole[i].Dejmat()<<"$";
            soubor<<pole[i].Dejcej()<<"$";
            soubor<<pole[i].Dejcja()<<"$";
            soubor<<pole[i].Dejhodnoceni()<<"$"<<endl;
        }
        
        soubor.close();
        
        return true;
    }

    bool trida::ze_souboru(){
        int i=0, sid,smat,scej,scja;
        ifstream soubor;
        string radek,sjm,spj,sh;
        soubor.open("petko.txt");
        
        if(soubor.fail()){
            cout << "Chyba";
            return false;
        }
        
        while(getline(soubor,radek,'$')){
            i++;
            switch (i) {
            case 1:
                sid=atoi(radek.c_str());
                break;
            case 2:
                sjm=radek;
                break;
            case 3:
                spj=radek;
                break;
            case 4:
                smat=atoi(radek.c_str());
                break;
            case 5:
                scej=atoi(radek.c_str());
                break;
            case 6:
                scja=atoi(radek.c_str());
                break;
            case 7:
                sh=radek;
                zak novy(sid,sjm,spj,smat,scej,scja,sh);
                pridat(novy);
                i=0;
                break;
            }
        }
        
        soubor.close();
        return true;
        
    }

    int trida::hledaniid(){
        zak x;
        int hledid=0,pom=0;
        
        fflush(stdin);
        cout << "Zadejte hledane ID:";
        cin >> hledid;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].DejID()==hledid){
                x=pole[i];
                pom++;
            }
        }
        
        cout << x.DejID() << "|" << x.Dejjmeno() << "|" << x.Dejprijmeni() << "|" << x.Dejmat() << "|" << x.Dejcej() << "|" << x.Dejcja() << "|" << x.Dejhodnoceni() << endl;
        
        return pom;
    }

    int trida::hledanijm(){
        zak x;
        int pom=0;
        
        string hledpj;
        
        fflush(stdin);
        cout << "Zadejte hledane jmeno:";
        cin >> hledpj;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].Dejprijmeni().compare(hledpj)==0){
                x=pole[i];
                pom=1;
            }
        }
        
        cout << x.DejID() << "|" << x.Dejjmeno() << "|" << x.Dejprijmeni() << "|" << x.Dejmat() << "|" << x.Dejcej() << "|" << x.Dejcja() << "|" << x.Dejhodnoceni() << endl;
        return pom;
    }

    int trida::odstraneni(int hledid){
        zak x;
        int pom=0;
        
        
        for(int i=0;i<pocet;i++){
            if(pole[i].DejID()==hledid){
                for(int j=i;j<pocet;j++){
                    pole[j]=pole[j+1];
                    pom=1;
                }
            }
        }
        
        pocet=pocet-1;
        return pom;
    }

    void trida::editace(){
        int hledid,emat,ecej,ecja;
        string ejm,epj,eh;
        
        cout << "Zadejte ID k editaci:";
        cin >> hledid;
        
        for(int i=0;i<pocet;i++){
            if(pole[i].DejID()==hledid){
                cout << pole[i].DejID() << "|" << pole[i].Dejjmeno() << "|" << pole[i].Dejprijmeni() << "|" << pole[i].Dejmat() << "|" << pole[i].Dejcej() << "|" << pole[i].Dejcja() << "|" << pole[i].Dejhodnoceni() << endl; 
                cout << "Zadejte nove jmeno:";
                cin >> ejm;
                cout << "Zadejte nove prijmeni:";
                cin >> epj;
                cout << "Zadejte body z matematiky:";
                cin >> emat;
                cout << "Zadejte body z cestiny:";
                cin >> ecej;
                cout << "Zadejte body z anglictiny:";
                cin >> ecja;
                eh=pole[i].Dejhodnoceni();
                odstraneni(pole[i].DejID());
                zak novy(hledid,ejm,epj,emat,ecej,ecja,pole[i].Dejhodnoceni());
                pridat(novy);
            }
        }
    }

    void trida::razeni(){
        zak x;
        
        
        for(int j=pocet-1;j>=0;j--){
            for(int i=0;i<j;i++){
                if(pole[i].Dejprijmeni()>pole[i+1].Dejprijmeni()){
                    x=pole[i];
                    pole[i]=pole[i+1];
                    pole[i+1]=x;
                }
            }
        }
        
    }

    void trida::nejvysl(){
        zak x;
        int pommat, pomcej, pomcja,maxmat,maxcej,maxcja;
        
        pommat=pole[0].Dejmat();
        pomcej=pole[0].Dejcej();
        pomcja=pole[0].Dejcja();
        
        
        for(int i=0;i<=pocet;i++){
            if(pole[i].Dejmat()>pommat){
                pommat=pole[i].Dejmat();
                maxmat=i;
            }
            if(pole[i].Dejcej()>pomcej){
                pomcej=pole[i].Dejcej();
                maxcej=i;
            }
            if(pole[i].Dejcja()>pomcja){
                pomcja=pole[i].Dejcja();
                maxcja=i;
            }
        }
        
        cout << "Nejvice bodu z matematiky dosahl:" << pole[maxmat].Dejjmeno() << pole[maxmat].Dejprijmeni() << endl;
        cout << "Nejvice bodu z cestiny dosahl:" << pole[maxcej].Dejjmeno() << pole[maxcej].Dejprijmeni() << endl;
        cout << "Nejvice bodu z anglictiny dosahl:" << pole[maxcja].Dejjmeno() << pole[maxcja].Dejprijmeni() << endl;
        
        
    }

    void trida::prmr(){
        float pmat=0,pcej=0,pcja=0,pr=0;
        float pommat=0,pomcej=0,pomcja=0;
        
        for(int i=0;i<pocet;i++){
            pommat=pommat+pole[i].Dejmat();
            pomcej=pomcej+pole[i].Dejcej();
            pomcja=pomcja+pole[i].Dejcja();
        }
        
        pmat=pommat/pocet;
        pcej=pomcej/pocet;
        pcja=pomcja/pocet;
        pr=(pmat+pcej+pcja)/3;
        
        cout << "Prumer bodu z matematiky:" << pmat << endl;
        cout << "Prumer bodu z cestiny:" << pcej << endl;
        cout << "Prumer bodu z anglictiny:" << pcja << endl;
        cout << "Celkovy prumer:" << pr << endl;
    }