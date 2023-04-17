---
layout: page
title: Knihovny 1
description: Knihovny 1
has_children: false
nav_exclude: true
---
    #ifndef KOMPLEX_H
    #define KOMPLEX_H

    #include <iostream>
    #include <numeric>
    #include <cmath>
    #include <fstream>
    using namespace std;

    class komplex{
    private:
        int real,img;
        
    public:
        komplex();
        komplex(int ireal);
        komplex(int ireal, int ikomplex);
        
        friend istream& operator>>(istream& in, komplex &k);
        friend ostream& operator<<(ostream& out, komplex k);
        int Dejreal(){return real;}
        int Dejimg(){return img;}
        int abs();
        komplex sdr();
        bool zapis(komplex k);
        
        komplex operator+(komplex k);
        komplex operator-(komplex k);
        komplex operator*(komplex k);
        komplex operator/(komplex k);
    };

    #endif