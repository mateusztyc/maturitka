#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void nacteni();
int preklad(char slovo[]);
int zkouseni(int lek);

int main(){
	char slovo[20];
	int lek;

	nacteni();
	system("pause");
	printf("Zadejte slovo pro preklad\n");
	gets(slovo);
	if(preklad(slovo)==0){
		printf("slovo nenalezeno");
	}
	printf("Zadejte lekci pro zkouseni\n");
	scanf("%d",&lek);
	printf("Ze zkouseni z %d.lekce jste mel %d procent\n",lek,zkouseni(lek));
	
	return 0;
}

void nacteni(){
	FILE *f;
	char radek[80];
	
	f=fopen("slovnik.txt","r");
	while(fgets(radek,80,f)!=NULL){
		puts(radek);
	}
	fclose(f);
}

int preklad(char slovo[]){
	FILE *f;
	char cz[20], aj[20], radek[80], *p;
	int lekce,nal=0;
	
	f=fopen("slovnik.txt", "r");
	while(fgets(radek,80,f)!=NULL){
		p=strtok(radek, ";");
		strcpy(cz,p);
		p=strtok(NULL, ";");
		strcpy(aj,p);
		p=strtok(NULL,";");
		lekce=atoi(p);
		
		if(strcmp(slovo,cz)==0 || strcmp(slovo,aj)==0){
			printf("%s/%s\n",cz,aj);
			system("pause");
			nal=1;
		}
	}
	fclose(f);
	
	return nal;
}
int zkouseni(int lek){
	FILE *f;
	char cz[20], aj[20], radek[80], por[20],*p;
	int lekce,spr=0,poc=0;
	float vysl;
	f=fopen("slovnik.txt", "r");
	
	while(fgets(radek,80,f)!=NULL){
		p=strtok(radek, ";");
		strcpy(cz,p);
		p=strtok(NULL, ";");
		strcpy(aj,p);
		p=strtok(NULL,";");
		lekce=atoi(p);
		
		fflush(stdin);
		
		if(lekce==lek){
			poc++;
			printf("Zadejte preklad pro %s\n",cz);
			gets(por);
			if(strcmp(por,aj)==0){
				printf("Spravne\n");
				spr++;
				system("pause");
				
			}
			else
			{
				printf("spatne");
			}
		}
		
	}
	vysl=((float)spr/poc)*100;
	return vysl;
}
