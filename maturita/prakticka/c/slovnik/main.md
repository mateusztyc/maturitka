---
layout: page
title: Slovnik
description: Slovník
has_children: false
nav_exclude: true
---
    #include "slovnik.h"

    int main(void){
        char soubor[40],prekladd[30],slovo_odstr[30];
        int pocet,vyber;
        
        printf("\t\tSLOVNIK\n\n");
        printf("Zadejte soubor s vasimi slovicky: ");
        gets(soubor);
        system("cls");
        
        
        
        while(1){
            system("cls");
            printf("\t\tSLOVNIK\n");
            printf("Pracujete se souborem <%s>\n\n",soubor);
            
            printf("HLAVNI MENU\n");
            printf("1. Pridani slova\n");
            printf("2. Preklad slova\n");
            printf("3. Testovani z vybrane lekce\n");
            printf("4. Nahodne testovani\n");
            printf("5. Odstraneni slovicka\n");
            printf("6. Zmena souboru\n");
            printf("0. KONEC\n");
            printf("->");
            
            scanf("%d",&vyber);
            fflush(stdin);
            
            switch (vyber) {
            case 1:
                system("cls");
                printf("\t\tSLOVNIK\n");
                printf("\t\tPridani slova\n\n");
                pridat(soubor);
                system("pause");
                break;
                
            case 2:
                system("cls");
                printf("\t\tSLOVNIK\n");
                printf("\t\tPreklad slova\n\n");
                printf("Zadejte slovo pro preklad ->");
                gets(prekladd);
                printf("\n");
                if(preklad(soubor,prekladd)==0){
                    printf("Slovo nenalezeno");	
                }
                system("pause");
                break;
                
            case 3:
                system("cls");
                printf("\t\tSLOVNIK\n");
                printf("\t\tTestovani z vybrane lekce\n\n");
                testovani(soubor);
                system("pause");
                break;
                
            case 4:
                system("cls");
                printf("\t\tSLOVNIK\n");
                printf("\t\tNahodne testovani\n\n");
                printf("Zadejte pocet slovicek ->");
                scanf("%d",&pocet);
                rand_test(soubor,pocet);
                system("pause");
                break;
            
            case 5:
                system("cls");
                printf("\t\tSLOVNIK\n");
                printf("\t\tOdstraneni slovicka\n\n");
                printf("Zadejte slovo pro odstraneni ->");
                gets(slovo_odstr);
                odstraneni(soubor,slovo_odstr);
                system("pause");
                break;
                
            case 6:
                system("cls");
                printf("\t\tSLOVNIK\n");
                printf("\t\tZmena souboru\n\n");
                printf("Zadejte soubor se kterym chcete pracovat ->");
                gets(soubor);
                break;
                
            case 0:
                system("cls");
                exit(1);
            }
        }
    }