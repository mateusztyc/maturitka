---
layout: page
title: Databaze OOP
description: Databaze OOP C++
has_children: false
nav_exclude: true
---

    #include "hlavicka.h"

    int main(void){
        zak a;
        int vyber,vyber2,hledid;
        trida klasicka_trida;
        
        while(1){
            cout << "1. Pridani zaka" << endl;
            cout << "2. Vypis zaku" << endl;
            cout << "3. Ulozeni do souboru" << endl;
            cout << "4. Cteni ze souboru" << endl;
            cout << "5. Vyhledavani zaka" << endl;
            cout << "6. Odstraneni zaka" << endl;
            cout << "7. Editace zaznamu zaka" << endl;
            cout << "8. Razeni podle prijmeni" << endl;
            cout << "9. Maximum bodu" << endl;
            cout << "10. Prumer" << endl;
            cout << "0. Konec" << endl;
            
            cin >> vyber;
            
            switch (vyber) {
            case 1:
                system("cls");
                cin >> a;
                klasicka_trida.pridat(a);
                system("cls");
                break;
            case 2:
                system("cls");
                cout << klasicka_trida << endl;
                system("pause");
                system("cls");
                break;
            case 3:
                klasicka_trida.uloz();
                system("cls");
                break;
            case 4:
                klasicka_trida.ze_souboru();
                system("cls");
                break;
            case 5:
                fflush(stdin);
                cout << "Chcete vyhledavat podle:" << endl;
                cout << "1.ID" << endl << "2. Prijmeni" << endl;
                
                cin >> vyber2;
                
                switch (vyber2) {
                case 1:
                    system("cls");
                    if(klasicka_trida.hledaniid()==0){
                        cout << "Nenalezeno" << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    if(klasicka_trida.hledanijm()==0){
                        cout << "Nenalezeno" << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
                }
                break;
                
            case 6:
                system("cls");
                fflush(stdin);
                cout << "Zadejte ID pro odstraneni:";
                cin >> hledid;
                if(klasicka_trida.odstraneni(hledid)==0){
                    cout << "Neodstraneno" << endl;
                }
                cout << "Odstraneno" << endl;
                system("pause");
                system("cls");
                break;
            
            case 7:
                system("cls");
                fflush(stdin);
                klasicka_trida.editace();
                system("pause");
                system("cls");
                break;
                
            case 8:
                system("cls");
                klasicka_trida.razeni();
                system("cls");
                break;
            
            case 9:
                system("cls");
                klasicka_trida.nejvysl();
                system("pause");
                system("cls");
                break;
                
            case 10:
                system("cls");
                klasicka_trida.prmr();
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