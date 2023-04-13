---
layout: page
title: Databaze OOP
description: Databaze OOP C++
has_children: false
nav_exclude: true
---

    #include "hlavicka.h"

    int main(void){
        int vyber,vyber2,vyber3;
        hokejista a;
        klub klasicky_klub;
        
        while(1){
            cout << "1. Pridani hrace" << endl;
            cout << "2. Vypsani hracu" << endl;
            cout << "3. Zaloha do souboru" << endl;
            cout << "4. Nacteni ze souboru" << endl;
            cout << "5. Odstraneni hrace" << endl;
            cout << "6. Vyhledavani hrace" << endl;
            cout << "7. Vypis dle rozsahu" << endl;
            cout << "8. Razeni"  << endl;
            cout << "9. Nejlepsi hokejisti" << endl;
            cout << "10. Nejlepsi a nejhorsi hrac" << endl;
            cout << "11. Pocet bodu pro cely klub" << endl;
            cout << "0. KONEC" << endl;
            
            cin >> vyber;
            
            switch (vyber) {
            case 1:
                system("cls");
                cin >> a;
                klasicky_klub.pridat(a);
                system("cls");
                break;
            case 2:
                system("cls");
                cout << klasicky_klub << endl;
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                klasicky_klub.uloz();
                break;
            case 4:
                system("cls");
                klasicky_klub.nacti();
                system("cls");
                break;
            case 5:
                system("cls");
                fflush(stdin);
                if(klasicky_klub.odstranit()==0){
                    cout << "Nenalezeno" << endl;
                }
                system("pause");
                system("cls");
            case 6:
                system("cls");
                cout << "Chcete vyhledavat podle:" << endl;
                cout << "[1] Cisla" << endl;
                cout << "[2] Prijmeni" << endl;
                cin >> vyber2;
                switch (vyber2) {
                case 1:
                    if(klasicky_klub.hledcis()==0){
                        cout << "Nenalezeno";
                    }
                    system("pause");
                    break;
                case 2:
                    if(klasicky_klub.hledjm()==0){
                        cout << "Nenalezeno";
                    }
                    system("pause");
                    break;
                }
                break;
            case 7:
                system("cls");
                if(klasicky_klub.rozsah()==0){
                    cout << "Nenalezeno"; 
                }
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                cout << "Chcete radit podle" << endl;
                cout << "[1] Body" << endl;
                cout << "[2] Prijmeni" << endl;
                
                cin >> vyber3;
                
                switch (vyber3) {
                case 1:
                    klasicky_klub.razb();
                    cout << "Serazeno";
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    klasicky_klub.razp();
                    cout << "Serazeno";
                    system("pause");
                    system("cls");
                    break;
                }
                break;
            case 9:
                system("cls");
                klasicky_klub.nej();
                system("pause");
                system("cls");
                break;
            case 10:
                system("cls");
                klasicky_klub.minmax();
                system("pause");
                system("cls");
                break;
            case 11:
                system("cls");
                cout << "Soucet bodu celeho klubu je: " << klasicky_klub.soucet() << endl;
                system("pause");
                system("cls");
                break;
            case 0:
                system("cls");
                exit(1);
                break;
            }
        }
        
        
    }