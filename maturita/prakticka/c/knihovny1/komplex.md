---
layout: page
title: Knihovny 1
description: Knihovny 1
has_children: false
nav_exclude: true
---
    #include "komplex.h"

    komplex::komplex(){
        real=0;
        img=0;
    }
    komplex::komplex(int ireal){
        real=ireal;
        img=0;
    }
    komplex::komplex(int ireal, int iimg){
        real=ireal;
        img=iimg;
    }


    istream& operator>>(istream &in, komplex &k){
        
        cout << "Zadejte realnou cast: ";
        fflush(stdin);
        cin >> k.real;
        cout << "Zadejte imaginarni cast:";
        cin >> k.img;
        
        
        return in;
    }

    ostream& operator<<(ostream &out, komplex k){
        if(k.img>0){
            cout << k.real << "+" << k.img << "i";;
        }
        if(k.img==0){
            cout << k.real << endl;
        }
        if(k.img<0){
            cout << k.real << k.img << "i";
        }
        
        return out;
    }

    komplex komplex::operator+(komplex k){
        k.real += this -> real;
        k.img += this ->img;
        
        return k;
    }

    komplex komplex::operator-(komplex k){
        komplex g;
        g.real=(this -> real)-k.real;
        g.img=(this -> img)-k.img;
        
        return g;
    }

    komplex komplex::operator*(komplex k){
        komplex g;
        g.real=(k.real*this->real)-(k.img*this->img);
        g.img=(k.real*this->img)+(k.img*this->real);
        
        return g;
    }

    komplex komplex::operator/(komplex k){
        komplex del;

        k=k;
        return del;
    }

    int komplex::abs(){
        int z;
        
        z=sqrt((pow(this->real,2)+pow(this->img,2)));
        
        return z;
    }

    komplex komplex::sdr(){
        komplex g;
        g.real=this->real;
        g.img = -(this->img);
        
        return g;
    }

    bool komplex::zapis(komplex k){
        FILE *f;
        
        f=fopen("petko_peter.txt","a");
        
        fprintf(f,"%d + %d i\n",k.real,k.img);
        fprintf(f,"%d + %d i\n",this->real,this->img);
        
        fclose(f);
        
        return true;
    }