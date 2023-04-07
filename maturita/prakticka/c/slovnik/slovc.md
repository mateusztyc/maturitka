---
layout: page
title: Slovnik
description: Slovník
has_children: false
nav_exclude: true
---

    #include "slovnik.h"

    int pridat(char soubor[]){
        FILE *f;
        char cz[30],aj[30];
        int lekce;
        
        printf("Zadejte lekci:\n");
        scanf("%d",&lekce);
        fflush(stdin);
        printf("Zadejte ceske slovicko:\n");
        gets(cz);
        printf("Zadejte anglicke slovicko:\n");
        gets(aj);
        
        for(int i=0;i<strlen(cz);i++){
            cz[i]=tolower(cz[i]);
        }
        
        for(int i=0;i<strlen(aj);i++){
            aj[i]=tolower(aj[i]);
        }
        
        f=fopen(soubor,"a");
        fprintf(f,"%d|%s|%s|\n",lekce,cz,aj);
        fclose(f);
        
        
    }
    int preklad(char soubor[],char prekladd[]){
        FILE *f;
        char cz[30], aj[30], radek[80], *p;
        int lekce;
        
        
        
        f=fopen(soubor,"r");
        while(fgets(radek,80,f)!=NULL){
            p=strtok(radek,"|");
            lekce=atoi(p);
            p=strtok(NULL,"|");
            strcpy(cz,p);
            p=strtok(NULL,"|");
            strcpy(aj,p);
            
            if(strcmp(prekladd,cz)==0){
                printf("%s->%s\n",cz,aj);
            }
            if(strcmp(prekladd,aj)==0){
                printf("%s->%s\n",aj,cz);
            }
            
        }
        
    }
    void testovani(char soubor[]){
        FILE *f,*u;
        char radek[80],*p,cz[30],aj[30],pr[30];
        int lek[10],lekce,i,nal=0,x=0,lek_test,good=0,pocet=0,ul;
        float uspesnost;
        
        f=fopen(soubor,"r");
        while(fgets(radek,80,f)!=NULL){
            p=strtok(radek,"|");
            lekce=atoi(p);
            
            for(i=0;i<=x;i++){
                if(lek[i]==lekce){
                    nal=1;
                }
            }
            if(nal==0){
                lek[x]=lekce;
                x++;
            }
            nal=0;
        }
        
        fclose(f);
        
        printf("Vyberte si lekci pro testovani\n");
        for(i=0;i<x;i++){
            printf("%d\n",lek[i]);
        }
        scanf("%d",&lek_test);
        
        fflush(stdin);
        
        f=fopen(soubor,"r");
        while(fgets(radek,80,f)!=NULL){
            p=strtok(radek,"|");
            lekce=atoi(p);
            p=strtok(NULL,"|");
            strcpy(cz,p);
            p=strtok(NULL,"|");
            strcpy(aj,p);
            
            if(lekce==lek_test){
                pocet++;
                printf("Zadejte preklad pro slovo  %s -> ",cz);
                gets(pr);
                
                for(int i=0;i<=strlen(pr);i++){
                    pr[i]=tolower(pr[i]);
                }
                
                if(strcmp(pr,aj)==0){
                    printf("Spravne\n");
                    good++;
                }
                else{
                    printf("Spatne");
                }
            }
            
            
        }
        
        fclose(f);
        
        
        uspesnost=100*((float)good/pocet);
        printf("\tSTATISTIKA\n\n");
        printf("Spravne: %d\nPocet: %d\nUspesnost: %.1f ",good,pocet,uspesnost);
        
        system("pause");
        
        printf("Chcete vysledky ulozit do soouboru?\n");
        printf("Pokud Ano, kliknete 1,\n");
        scanf("%d",&ul);
        
        if(ul==1){
            u=fopen("testovani.txt","a");
            fprintf(u,"Uspesnost: %d/%d -> %.1f\n",good,pocet,uspesnost);
            fclose(u);
            printf("Ulozeno\n");
            system("pause");
        } 
        
    }
    void rand_test(char soubor[],int pocet){
        FILE *f,*u;
        char cz[30],aj[30],radek[80],poradi[pocet],pre[30], *p;
        int lekce,poc=0,rnd,nal=0,po=0,a=0,good=0,ul;
        srand( (unsigned) time(NULL) );
        
        f=fopen(soubor,"r");
        while(fgets(radek,80,f)!=NULL){
            poc++;
        }
        fclose(f);
        
        for(int i=0;i<pocet;i++){
            rnd=rand()%poc;
            for(int x=0;x<pocet;x++){
                if(poradi[x]==rnd){
                    nal=1;
                }
            }
            if(nal==0){
                poradi[i]=rnd;
            }
            nal=0;
        }
        
        
        a=0;
        while(a<pocet){
            po=0;
            f=fopen(soubor,"r");
            while(fgets(radek,80,f)!=NULL){
                if(po==poradi[a]){
                    
                    a++;
                    
                    p=strtok(radek,"|");
                    lekce=atoi(p);
                    p=strtok(NULL,"|");
                    strcpy(cz,p);
                    p=strtok(NULL,"|");
                    strcpy(aj,p);
                    
                    printf("Zadejte preklad slova %s ->",cz);
                    gets(pre);
                    if(strcmp(pre,aj)==0){
                        printf("Spravne\n");
                        good++;
                    }
                    else{
                        printf("Spatne\n");
                    }
                }
                po++;
            }
            fclose(f);
            
        }
        
        
        
        float uspesnost=100*((float)good/pocet);
        printf("\tSTATISTIKA\n\n");
        printf("Spravne: %d\nPocet: %d\nUspesnost: %.1f ",good,pocet,uspesnost);
        
        system("pause");
        
        printf("Chcete vysledky ulozit do soouboru?\n");
        printf("Pokud Ano, kliknete 1,\n");
        scanf("%d",&ul);
        
        if(ul==1){
            u=fopen("testovani.txt","a");
            fprintf(u,"Uspesnost: %d/%d -> %.1f\n",good,pocet,uspesnost);
            fclose(u);
            printf("Ulozeno\n");
            system("pause");
        } 
	
	
	
}
