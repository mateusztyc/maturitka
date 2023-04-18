#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int ID;
	char jmeno[30];
	char prijmeni[30];
	int mat;
	int cej;
	int fyz;
	int body;
	
	struct data *nasl, *pred;
}Tdata;

Tdata *prvni = NULL;

void pridani();
void vypis();
void vyhl();
void razeni();
void zapis();
void cteni();
void odstraneni();
void edit();
void nej();
void nedal();

int main(void){
	int vyber;
	
	while(1){
		system("cls");
		printf("[1]Pridani\n");
		printf("[2]Vypis\n");
		printf("[3]Nacteni ze souboru\n");
		printf("[4]Ulozeni do souboru\n");
		printf("[5]Razeni\n");
		printf("[6]Odstraneni zaznamu\n");
		printf("[7]Editace zaznamu\n");
		printf("[8]Nejlepsi student\n");
		printf("[9]Kolegove co to nedali\n");
		printf("[0]Konec\n");
		
		fflush(stdin);
		scanf("%d",&vyber);
		
		switch (vyber) {
		case 0:
			system("cls");
			exit(1);
			break;
		case 1:
			system("cls");
			pridani();
			break;
		case 2:
			system("cls");
			vypis();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cteni();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			zapis();
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			razeni();
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			odstraneni();
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			edit();
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			nej();
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			nedal();
			system("pause");
			system("cls");
			break;

		}
	}
}

void pridani(){
	Tdata *novy;
	Tdata *t;
	int tid;
	char tjm[30];
	char tpj[30];
	int tm;
	int tc;
	int tf;
	int tb;
	int pom=0,nal=0;
	
	novy=(Tdata*) malloc(sizeof(Tdata));
	if(novy==NULL){
		printf("Nedostatek mista v pameti\n");
		system("pause");
		exit(1);
	}
	
	novy->pred=NULL;
	novy->nasl=NULL;
	
	printf("Zadejte ID: ");
	do{
		nal=0;
		scanf("%d",&tid);
		for(t=prvni;t!=NULL;t=t->nasl){
			if(tid==t->ID){
				nal=1;
			}
		}
		if(nal!=0){
			printf("ID musi by jedinecne, zadejte znovu: ");
		}
		else{
			novy->ID=tid;
			pom=1;
		}
	}while(pom==0);
	pom=0;
	
	fflush(stdin);
	
	printf("Zadejte jmeno: ");
	gets(tjm);
	strcpy(novy->jmeno,tjm);
	
	printf("Zadejte prijmeni: ");
	gets(tpj);
	strcpy(novy->prijmeni,tpj);
	
	fflush(stdin);
	
	printf("Zadejte body z matematiky: ");
	do{
		
		scanf("%d",&tm);
		if(tm<=20 && tm>=0){
			novy->mat=tm;
			pom=1;
		}
		else{
			printf("Spatny rozsah, zadejte znovu: ");
		}
		
	}while(pom==0);
	
	pom=0;
	
	printf("Zadejte body z cestiny: ");
	do{
		
		scanf("%d",&tc);
		if(tc<=20 && tc>=0){
			novy->cej=tc;
			pom=1;
		}
		else{
			printf("Spatny rozsah, zadejte znovu: ");
		}
		
	}while(pom==0);
	
	pom=0;
	
	printf("Zadejte body z fyziky: ");
	do{
		
		scanf("%d",&tf);
		if(tf<=20 && tf>=0){
			novy->fyz=tf;
			pom=1;
		}
		else{
			printf("Spatny rozsah, zadejte znovu: ");
		}
		
	}while(pom==0);
	
	pom=0;
	
	tb=tm+tc+tf;
	novy->body=tb;
	
	if(prvni != NULL){
		prvni->pred=novy;
		novy->nasl=prvni;
		prvni=novy;
	}
	else{
		prvni=novy;
	}
}

void vypis(){
	Tdata *v;
	for(v=prvni;v!=NULL;v=v->nasl){
		printf("---------------------------------\n");
		printf("ID: %d\n",v->ID);
		printf("Jmeno: %s\n",v->jmeno);
		printf("Prijmeni: %s\n",v->prijmeni);
		printf("Body z matematiky: %d/20\n",v->mat);
		printf("Body z cestiny: %d/20\n",v->cej);
		printf("Body z fyziky: %d/20\n",v->fyz);
		printf("Celkovy pocet bodu: %d/60\n",v->body);
		printf("---------------------------------\n");
	}
}

void vyhl(){
	Tdata *v;
	char vyhll[30];
	
	fflush(stdin);
	
	printf("Zadejte prijmeni zaka ktereho chcete vyhledat: ");
	gets(vyhll);
	
	for(v=prvni;v!=NULL;v=v->nasl){
		if(strstr(v->prijmeni,vyhll)!=NULL){
			printf("---------------------------------\n");
			printf("ID: %d\n",v->ID);
			printf("Jmeno: %s\n",v->jmeno);
			printf("Prijmeni: %s\n",v->prijmeni);
			printf("Body z matematiky: %d/20\n",v->mat);
			printf("Body z cestiny: %d/20\n",v->cej);
			printf("Body z fyziky: %d/20\n",v->fyz);
			printf("Celkovy pocet bodu: %d/60\n",v->body);
			printf("---------------------------------\n");
		}
	}
}

void razeni(){
	Tdata *r;
	int vyb,pom,zamena=0;
	char tjm[30], tpj[30];
	
	printf("Chcete radit podle:\n");
	printf("[1]Prijmeni\n");
	printf("[2]Vysledku z mat\n");
	printf("[3]Vysledku z cej\n");
	printf("[4]Vysledku z fyz\n");
	printf("[5]Celkoveho poctu bodu\n\n");
	
	fflush(stdin);
	scanf("%d",&vyb);
	
	switch (vyb) {
	case 1:
		do{
			zamena=0;
			
			for(r=prvni;r->nasl!=NULL;r=r->nasl){
				if(strcmp(r->prijmeni,r->nasl->prijmeni)<0){
					
					pom=r->ID;
					r->ID=r->nasl->ID;
					r->nasl->ID=pom;
					
					strcpy(tjm,r->jmeno);
					strcpy(r->jmeno,r->nasl->jmeno);
					strcpy(r->nasl->jmeno,tjm);
					
					strcpy(tpj,r->prijmeni);
					strcpy(r->prijmeni,r->nasl->prijmeni);
					strcpy(r->nasl->prijmeni,tpj);
					
					pom=r->mat;
					r->mat=r->nasl->mat;
					r->nasl->ID=pom;
					
					pom=r->cej;
					r->cej=r->nasl->cej;
					r->nasl->cej=pom;
					
					pom=r->fyz;
					r->fyz=r->nasl->fyz;
					r->nasl->fyz=pom;
					
					pom=r->body;
					r->body=r->nasl->body;
					r->nasl->body=pom;
				}
			}
		}while(zamena==1);
		
		printf("Uspesne serazeno\n");
		system("pause");
		break;
	case 2:
		do{
			zamena=0;
			
			for(r=prvni;r->nasl!=NULL;r=r->nasl){
				if(r->mat > r->nasl->mat){
					
					pom=r->ID;
					r->ID=r->nasl->ID;
					r->nasl->ID=pom;
					
					strcpy(tjm,r->jmeno);
					strcpy(r->jmeno,r->nasl->jmeno);
					strcpy(r->nasl->jmeno,tjm);
					
					strcpy(tpj,r->prijmeni);
					strcpy(r->prijmeni,r->nasl->prijmeni);
					strcpy(r->nasl->prijmeni,tpj);
					
					pom=r->mat;
					r->mat=r->nasl->mat;
					r->nasl->ID=pom;
					
					pom=r->cej;
					r->cej=r->nasl->cej;
					r->nasl->cej=pom;
					
					pom=r->fyz;
					r->fyz=r->nasl->fyz;
					r->nasl->fyz=pom;
					
					pom=r->body;
					r->body=r->nasl->body;
					r->nasl->body=pom;
				}
			}
		}while(zamena==1);
		
		printf("Uspesne serazeno\n");
		system("pause");
		break;
	case 3:
		do{
			zamena=0;
			
			for(r=prvni;r->nasl!=NULL;r=r->nasl){
				if(r->cej > r->nasl->cej){
					
					pom=r->ID;
					r->ID=r->nasl->ID;
					r->nasl->ID=pom;
					
					strcpy(tjm,r->jmeno);
					strcpy(r->jmeno,r->nasl->jmeno);
					strcpy(r->nasl->jmeno,tjm);
					
					strcpy(tpj,r->prijmeni);
					strcpy(r->prijmeni,r->nasl->prijmeni);
					strcpy(r->nasl->prijmeni,tpj);
					
					pom=r->mat;
					r->mat=r->nasl->mat;
					r->nasl->ID=pom;
					
					pom=r->cej;
					r->cej=r->nasl->cej;
					r->nasl->cej=pom;
					
					pom=r->fyz;
					r->fyz=r->nasl->fyz;
					r->nasl->fyz=pom;
					
					pom=r->body;
					r->body=r->nasl->body;
					r->nasl->body=pom;
				}
			}
		}while(zamena==1);
		
		printf("Uspesne serazeno\n");
		system("pause");
		break;
	case 4:
		do{
			zamena=0;
			
			for(r=prvni;r->nasl!=NULL;r=r->nasl){
				if(r->fyz > r->nasl->fyz){
					
					pom=r->ID;
					r->ID=r->nasl->ID;
					r->nasl->ID=pom;
					
					strcpy(tjm,r->jmeno);
					strcpy(r->jmeno,r->nasl->jmeno);
					strcpy(r->nasl->jmeno,tjm);
					
					strcpy(tpj,r->prijmeni);
					strcpy(r->prijmeni,r->nasl->prijmeni);
					strcpy(r->nasl->prijmeni,tpj);
					
					pom=r->mat;
					r->mat=r->nasl->mat;
					r->nasl->ID=pom;
					
					pom=r->cej;
					r->cej=r->nasl->cej;
					r->nasl->cej=pom;
					
					pom=r->fyz;
					r->fyz=r->nasl->fyz;
					r->nasl->fyz=pom;
					
					pom=r->body;
					r->body=r->nasl->body;
					r->nasl->body=pom;
				}
			}
		}while(zamena==1);
		
		printf("Uspesne serazeno\n");
		system("pause");
		break;
	case 5:
		do{
			zamena=0;
			
			for(r=prvni;r->nasl!=NULL;r=r->nasl){
				if(r->body > r->nasl->body){
					
					pom=r->ID;
					r->ID=r->nasl->ID;
					r->nasl->ID=pom;
					
					strcpy(tjm,r->jmeno);
					strcpy(r->jmeno,r->nasl->jmeno);
					strcpy(r->nasl->jmeno,tjm);
					
					strcpy(tpj,r->prijmeni);
					strcpy(r->prijmeni,r->nasl->prijmeni);
					strcpy(r->nasl->prijmeni,tpj);
					
					pom=r->mat;
					r->mat=r->nasl->mat;
					r->nasl->ID=pom;
					
					pom=r->cej;
					r->cej=r->nasl->cej;
					r->nasl->cej=pom;
					
					pom=r->fyz;
					r->fyz=r->nasl->fyz;
					r->nasl->fyz=pom;
					
					pom=r->body;
					r->body=r->nasl->body;
					r->nasl->body=pom;
				}
			}
		}while(zamena==1);
		
		printf("Uspesne serazeno\n");
		system("pause");
		break;
	}

}

void zapis(){
	Tdata *r;
	FILE *f;
	
	f=fopen("miladka.txt","ab");
	
	for(r=prvni;r != NULL; r=r->nasl){
		fwrite(r,sizeof(Tdata),1,f);
	}
	fclose(f);
	
	printf("Ulozeno");
	system("pause");
}

void cteni(){
	Tdata *novy, r;
	FILE *f;
	prvni=NULL;
	
	f=fopen("miladka.dat","rb");
	
	while(fread(&r, sizeof(Tdata),1,f)==1){
		novy=(Tdata*) malloc(sizeof(Tdata));
		if(novy==NULL){
			printf("Nedostatek mista v pameti");
		}
		
		*novy=r;
		novy->pred=NULL;
		novy->nasl=NULL;
		
		if(prvni != NULL){
			prvni->pred=novy;
			novy->nasl=prvni;
			prvni=novy;
		}
		else{
			prvni=novy;
		}
	}
	fclose(f);
	
	printf("Data nactena\n");
	system("pause");
}

void odstraneni(){
	Tdata *r;
	int z=0, oid;
	
	printf("Zadejte ID k odstraneni studenta: ");
	fflush(stdin);
	scanf("%d", &oid);
	
	for(r=prvni;r != NULL; r=r->nasl){
		if(oid==r->ID){
			if(r->pred == NULL && r->nasl == NULL){
				free(prvni);
				prvni=NULL;
			}
			if(r->pred == NULL){
				free(prvni);
				prvni=NULL;
				prvni=r->nasl;
				r->nasl->pred=NULL;
			}
			if(r->nasl == NULL){
				r->pred->nasl = NULL;
				free(r);
			}
			else{
				r->pred->nasl=r->nasl;
				r->nasl->pred=r->pred;
				free(r);
			}
			z++;
		}
	}
	
	if(z==0){
		printf("Student s ID %d neni v seznamu\n",oid);
		system("pause");
	}
	else{
		printf("Student s ID %d byl odstranen\n",oid);
		system("pause");
	}
	
}

void edit(){
	Tdata *r;
	int z=0,hl;

	
	printf("Zadejte ID studenta pro editaci: ");
	fflush(stdin);
	scanf("%d",&hl);
	
	system("cls");
	
	for(r=prvni;r != NULL; r=r->nasl){
		if(r->ID==hl){
			printf("Zadejte nove jmeno: ");
			fflush(stdin);
			gets(r->jmeno);
			
			printf("Zadejte nove prijmeni: ");
			fflush(stdin);
			gets(r->prijmeni);
			
			printf("Zadejte body z matematiky: ");
			fflush(stdin);
			scanf("%d",&r->mat);
			
			printf("Zadejte body z cestiny: ");
			fflush(stdin);
			scanf("%d",&r->cej);
			
			printf("Zadejte body z fyziky: ");
			fflush(stdin);
			scanf("%d",&r->fyz);
			
			r->body=r->mat+r->cej+r->fyz;
			
			z++;
		}
	}
	
	if(z==0){
		printf("Student nenalezen\n");
		system("pause");
	}
	else{
		printf("Upraveno\n");
		system("pause");
	}
	
}

void nej(){
	Tdata *r;
	int pom=0,pom2;
	
	for(r=prvni;r != NULL;r=r->nasl){
		if(r->body > pom){
			pom=r->body;
			pom2=r->ID;
		}
	}
	
	printf("Zak s nejlepsim vysledkem je: \n");
	for(r=prvni; r != NULL; r=r->nasl){
		if(r->ID==pom2){
			printf("---------------------------------\n");
			printf("ID: %d\n",r->ID);
			printf("Jmeno: %s\n",r->jmeno);
			printf("Prijmeni: %s\n",r->prijmeni);
			printf("Body z matematiky: %d/20\n",r->mat);
			printf("Body z cestiny: %d/20\n",r->cej);
			printf("Body z fyziky: %d/20\n",r->fyz);
			printf("Celkovy pocet bodu: %d/60\n",r->body);
			printf("---------------------------------\n");
		}
	}
}

void nedal(){
	Tdata *r;
	
	printf("Tito studenti to nedali:\n");
	for(r=prvni;r!=NULL;r=r->nasl){
		if(r->mat <=5 || r->cej <=5 || r->fyz <= 5){
			printf("---------------------------------\n");
			printf("ID: %d\n",r->ID);
			printf("Jmeno: %s\n",r->jmeno);
			printf("Prijmeni: %s\n",r->prijmeni);
			printf("Body z matematiky: %d/20\n",r->mat);
			printf("Body z cestiny: %d/20\n",r->cej);
			printf("Body z fyziky: %d/20\n",r->fyz);
			printf("Celkovy pocet bodu: %d/60\n",r->body);
			printf("---------------------------------\n");
		}
	}
}
