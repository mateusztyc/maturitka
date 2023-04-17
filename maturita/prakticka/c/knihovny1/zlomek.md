---
layout: page
title: Knihovny 1
description: Knihovny 1
has_children: false
nav_exclude: true
---
    #include "zlomek.h"

    Zlomek::Zlomek(){
        cit=0;
        jm=0;
    }

    istream& operator>>(istream &in, Zlomek &x){
        int pom,q=0;
        
        cout << "Zadejte citatel: ";
        fflush(stdin);
        cin>>x.cit;
        
        do{
            cout << "Zadejte jmenovatel: ";
            cin >> pom;
            
            if(pom!=0){
                x.jm=pom;
                q=1;
            }
            else {
                cout << "Jmenovatel nemuze byt 0!" << endl;
                cout << "Try again!!" << endl;
            }
        }while(q==0);
        
        
        
        return in;
        
    }

    ostream& operator<<(ostream &out, Zlomek x){
        if(x.cit%x.jm==0){
            cout << x.cit/x.jm;
        }
        else{
            cout << x.cit << "/" << x.jm;
        }
        
        return out;
    }

    Zlomek Zlomek::operator+(Zlomek x){
        Zlomek zp;
        zp.jm = x.jm*this->jm;
        zp.cit = (x.cit*this->jm) + (x.jm*this->cit);
        
        return kraceni(zp);
    }

    Zlomek Zlomek::operator-(Zlomek x){
        Zlomek zp;
        zp.jm = x.jm*this->jm;
        zp.cit = (x.cit*this->jm) - (x.jm*this->cit);
        
        return kraceni(zp);
    }

    Zlomek Zlomek::operator*(Zlomek x){
        x.jm *= this -> jm;
        x.cit *= this -> cit;
        return kraceni(x);
    }

    Zlomek Zlomek::operator/(Zlomek x){
        int tmp;
        tmp=x.jm;
        x.jm=x.cit;
        x.cit=jm;
        
        x.jm *= this -> jm;
        x.cit *= this -> cit;
        
        return kraceni(x);
    }

    Zlomek Zlomek::kraceni(Zlomek x){
        int g=gcd(x.cit,x.jm);
        
        x.cit=x.cit/g;
        x.jm=x.jm/g;
        
        return x;
    }

    int Zlomek::porovnani(Zlomek x){
        float g,h;
        
        g=(float)this->cit/this->jm;
        h=(float)x.cit/x.jm;
        
        if(g>h){
            return 1;
        }
        if(h>g){
            return 2;
        }
        else{
            return 0;
        }	 
    }