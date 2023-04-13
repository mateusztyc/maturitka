---
layout: page
title: Databaze OOP
description: Databaze OOP C++
has_children: false
nav_exclude: true
---

    #include "hlavicka.h"

    zak::zak(){
        ID=0;
        jmeno="";
        prijmeni="";
        mat=0;
        cej=0;
        cja=0;
        hodnoceni="";
    }

    zak::zak(int iID){
        ID=iID;
        jmeno="";
        prijmeni="";
        mat=0;
        cej=0;
        cja=0;
        hodnoceni="";
    }

    zak::zak(int iID, string ijmeno){
        ID=iID;
        jmeno=ijmeno;
        prijmeni="";
        mat=0;
        cej=0;
        cja=0;
        hodnoceni="";
    }

    zak::zak(int iID, string ijmeno, string iprijmeni){
        ID=iID;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        mat=0;
        cej=0;
        cja=0;
        hodnoceni="";
    }

    zak::zak(int iID, string ijmeno, string iprijmeni, int imat){
        ID=iID;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        mat=imat;
        cej=0;
        cja=0;
        hodnoceni="";
    }

    zak::zak(int iID, string ijmeno, string iprijmeni, int imat, int icej){
        ID=iID;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        mat=imat;
        cej=icej;
        cja=0;
        hodnoceni="";
    }

    zak::zak(int iID, string ijmeno, string iprijmeni, int imat, int icej, int icja){
        ID=iID;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        mat=imat;
        cej=icej;
        cja=icja;
        hodnoceni="";
    }

    zak::zak(int iID, string ijmeno, string iprijmeni, int imat, int icej,int icja, string ihodnoceni){
        ID=iID;
        jmeno=ijmeno;
        prijmeni=iprijmeni;
        mat=imat;
        cej=icej;
        cja=icja;
        hodnoceni=ihodnoceni;
    }

    ostream &operator<<(ostream &vystup, zak x){
        vystup << x.ID << "|" << x.jmeno << "|" << x.prijmeni << "|" << x.mat << "|" << x.cej << "|" << x.cja << "|" << x.hodnoceni << endl;
        return vystup;
    }

    istream &operator>>(istream &vstup, zak &x){
        int temp,h=0;
        
        cout << "Zadejte ID zaka" << endl;
        vstup >> x.ID;
        fflush(stdin);
        cout << "Zadejte jmeno zaka" << endl;
        getline(vstup, x.jmeno);
        cout << "Zadejte prijmeni zaka" << endl;
        getline(vstup, x.prijmeni);
        fflush(stdin);
        cout << "Zadejte hodnoceni z matematiky" << endl;
        do{
            cin >> temp;
            if(temp<=100 && temp!=0 ){
                x.mat=temp;
                h=1;
            }
            else{
                cout<< "Chybne zadano!" << endl;
            }
        }while(h!=1);
        h=0;
        cout << "Zadejte hodnoceni z cestiny" << endl;
        do{
            cin >> temp;
            if(temp<=100 && temp!=0 ){
                x.cej=temp;
                h=1;
            }
            else{
                cout<< "Chybne zadano!" << endl;
            }
        }while(h!=1);
        h=0;
        cout << "Zadejte hodnoceni z anglictiny" << endl;
        do{
            cin >> temp;
            if(temp<=100 && temp!=0 ){
                x.cja=temp;
                h=1;
            }
            else{
                cout<< "Chybne zadano!" << endl;
            }
        }while(h!=1);
        h=0;
        fflush(stdin);
        if(x.Dejmat()<40 && x.Dejcej()<40 && x.Dejcja()<40){
            x.hodnoceni="Neprospel";
        }
        if(x.Dejmat()>=85 && x.Dejcej()>=85 && x.Dejcja()>=85){
            x.hodnoceni="Prospel s vyznamenanim";
        }
        else{
            x.hodnoceni="Prospel";
        }
        return vstup;
    }