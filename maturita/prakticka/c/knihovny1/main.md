---
layout: page
title: Knihovny 1
description: Knihovny 1
has_children: false
nav_exclude: true
---
    #include "zlomek.h"
    #include "komplex.h"

    int main(void){
        Zlomek a,b;
        int vyber, vyber1, vyber2, vyber3;
        
        
        system("cls");
        cout << "Chcete pracovat se zlomky nebo komplexnimi cisly?" << endl;
        cout << "[1]Zlomek" << endl;
        cout << "[2]Komplexni cislo" << endl;
        
        cin >> vyber;
        
            
            
            switch(vyber){
            case 1:
            while(1){
                
            
                system("cls");
                cout << "[0]Konec" << endl;
                cout << "[1]Nacteni" << endl;
                cout << "[2]Vypis" << endl;
                cout << "[3]Zakladni aritmeticke operace" << endl;
                cout << "[4]Porovnani zlomku" << endl;
                
                cin >> vyber1;
                fflush(stdin);
                
                switch (vyber1) {
                case 1:
                    system("cls");
                    cout << "Zadejte prvni zlomek" << endl;
                    cin >> a;
                    cout << "Zadejte druhy zlomek" << endl;
                    cin >> b;
                    break;
                case 2:
                    system("cls");
                    cout << "Chcete zlomky zobrazit jako:" << endl;
                    cout << "[1]Zlomek" << endl << "[2]Desetinne cislo" << endl;
                    cin >> vyber2;
                    switch (vyber2) {
                    case 1:
                        cout << "1. Zlomek -> " << a.kraceni(a) << endl;
                        cout << "2. Zlomek -> " << b.kraceni(b) << endl;
                        break;
                    case 2:
                        float q;
                        q=(float)a.Dejcit()/a.Dejjm();
                        cout << "1. Zlomek -> " << q << endl;
                        q=(float)b.Dejcit()/b.Dejjm();
                        cout << "2. Zlomek -> "<< q << endl;
                        break;
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    cout << "[1] +" << endl;
                    cout << "[2] -" << endl;
                    cout << "[3] *" << endl;
                    cout << "[4] /" << endl;
                    
                    
                    cin >> vyber3;
                    
                    switch (vyber3) {
                    case 1:
                        cout << a << "+" << b << "=" << a+b << endl;
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        cout << a << "-" << b << "=" << a-b << endl;
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        cout << a << "*" << b << "=" << a*b << endl;
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        cout << a << "/" << b << "=" << a/b << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                    break;
                case 4:
                        system("cls");
                        if(a.porovnani(b)==1){
                            cout << "Prvni zlomek je vetsi" << endl;
                        }
                        if(a.porovnani(b)==2){
                            cout << "Druhy zlomek je vetsi" << endl;
                        }
                        if(a.porovnani(b)==0){
                            cout << "Zlomky jsou rovny" << endl;
                        }
                        system("pause");
                        system("cls");
                    break;
                case 0:
                    exit(1);
                    break;
                }
                
            }
            break;
            
                            //KOMPLEXNI//
                            
            case 2:
                komplex k,l;
                while(1){
                    system("cls");
                    cout << "[0]Konec" << endl;
                    cout << "[1]Nacteni" << endl;
                    cout << "[2]Vypis" << endl;
                    cout << "[3]Zakladni aritmeticke operace" << endl;
                    cout << "[4]Absolutni hodnota" << endl;
                    cout << "[5]Cislo komplexne sdruzene" << endl;
                    cout << "[6]Zapis do soubroy" << endl;
                    
                    cin >> vyber1;
                    
                    switch (vyber1) {
                    case 1:
                        system("cls");
                        cin >> k;
                        cin >> l;
                        break;
                    case 2:
                        system("cls");
                        cout << k << endl;
                        cout << l << endl;
                        system("pause");
                        break;
                    case 3:
                        system("cls");
                        cout << "[1]+" << endl;
                        cout << "[2]-" << endl;
                        cout << "[3]*" << endl;
                        cout << "[4]/" << endl;
                        
                        cin >> vyber2;
                        
                        fflush(stdin);
                        
                        switch(vyber2){
                        case 1:
                            cout << k << " + " << l << " = " << k+l << endl;
                            system("pause");
                            break;
                        case 2:
                            cout << k << " - " << l << " = " << k-l << endl;
                            system("pause");
                            break;
                        case 3:
                            cout << k << " * " << l << " = " << k*l << endl;
                            system("pause");
                            break;
                        case 4:
                            cout << k << " / " << l << " = " << k/l << endl;
                            system("pause");
                            break;
                        }
                        break;
                    case 4:
                        system("cls");
                        cout << "Absolutni hodnota cisla " << k << "je: " << k.abs() << endl;
                        cout << "Absolutni hodnota cisla " << l << "je: " << l.abs() << endl;
                        system("pause");
                        break;
                    case 5:
                        system("cls");
                        cout << "Cislo komplexne sdruzene k cislu " << k << "je:" << k.sdr() << endl;
                        cout << "Cislo komplexne sdruzene k cislu " << l << "je:" << l.sdr() << endl;
                        system("pause");
                        break;
                    case 6:
                        system("cls");
                        if(k.zapis(l)){
                            cout << "Zapsano";
                        }
                        system("pause");
                        break;
                    case 0:
                        system("cls");
                        exit(1);
                        break;
                    }
                }
                break;
        }
        
    } 