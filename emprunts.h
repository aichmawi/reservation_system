#ifndef EMPRUNTS_H_INCLUDED
#define EMPRUNTS_H_INCLUDED
#include "clients.h"
#include "velos.h"


//****************************************************************


void empruntervelo(clients *c,velos *v,int bornec,int bornev){
    int index,i,k=0,l=0,em_index,ve,nbrj;
     printf("Donner l\'index de velo emprunter: ");scanf("%d",&index);
     for(i=0;i<bornev;i++){
        if(index==(v+i)->ve_index){
           printf("Donner l\'index de l\'emprunteur: ");scanf("%d",&em_index);
           (v+i)->ve_emprunteur=em_index;
           printf("Donner le nombre de jour emprunte: ");scanf("%d",&nbrj);
            (v+i)->ve_nbrjour=nbrj;
             time_t t=time(0);
             (v+i)->ve_duree=t+(nbrj*86400);
           k=1;
}}
     if (k==0)
        printf("\n\n\t*************** Le velo n\'exist pas***************\n");
        else{
     for(i=0;i<bornec;i++){
        if(em_index==(c+i)->cl_index){
           l=1;
}}
            if(l==0)
                printf("\n\n\t*************** Le client n\'exist pas***************\n");
     }}
//******************************************************

void rendrevelo(clients *c,velos *v,int bornec,int bornev){
    int index_ve,index_cl,k=0,i,j=0,l=0;
    printf("Donner l\'index de velo emprunte: ");scanf("%d",&index_ve);
     for(i=0;i<bornev;i++){
        if(index_ve==(v+i)->ve_index){
           index_cl=(v+i)->ve_emprunteur;
           if((v+i)->ve_nbrjour==0)
            printf("\n\n\t*************** Le velo n\'est pas emprunte !!!***************\n");
           (v+i)->ve_nbrjour=0;
           (v+i)->ve_emprunteur=0;
           l=1;
}}
    if(l==0)
        printf("\n\n\t*************** Le velo n\'existe pas !!!***************\n");

   for(i=0;i<bornec;i++){
    if((c+i)->cl_index==index_cl){
        j=1;
        printf("\n\n\t*************** Le velo est rendre avec succes***************\n");
}}
      if(j==0)
        printf("\n\n\t*************** Le client n\'existe pas !!!***************\n");
}

//*******************************************************

void velosempruntes(velos *v,int bornev){
    int i,k=0,d;
    printf("\n\n\t******************Les velos empruntes******************\n\n");
      for(i=0;i<bornev;i++){
        if((v+i)->ve_nbrjour!=0){
            printf("\t\tL\'index de velo: %d\n",(v+i)->ve_index);
            printf("\t\tLe type de velo: %s\n",(v+i)->ve_type);
            printf("\t\tLe prix totale de velo: %d DH\n",((v+i)->ve_prix)*((v+i)->ve_nbrjour));
             time_t t=time(0);
             if(((v+i)->ve_duree)>t){
                d=(v+i)->ve_duree-t;
                printf("\t\tLa duree restant: ");conversionsecondes(d);
            }
             else{
                d=t-(v+i)->ve_duree;
                printf("\t\tLa duree est expire depuis: ");conversionsecondes(d);
             }
            printf("\t\tL\'index de l\'emprunteur est: %d\n",(v+i)->ve_emprunteur);
            k=1;
        }}
        if(k==0)
            printf("\n\n\n\n\t******************Il n\'exist pas de velos empruntes !!!******************\n");
        }

//*******************************************************

void emprunteursvelo(clients *c,velos *v,int bornec,int bornev){
    int indexv,indexc,i,j,k=0,l=0,d;
    printf("Donner l\'index de velo: ");scanf("%d",&indexv);
     for(i=0;i<bornev;i++){
        if(indexv==(v+i)->ve_index){
                indexc=(v+i)->ve_emprunteur;
        if(indexc!=0){
                for(j=0;j<bornec;j++){
                    if(indexc==(c+j)->cl_index ){
                         printf("\n\t\tL\'index de l\'emprunteur est: %d\n",(c+j)->cl_index);
                         printf("\t\tLe nom de l\'emprunteur est: %s\n",(c+j)->cl_nom);
                         printf("\t\tLe prenom de l\'emprunteur est: %s\n",(c+j)->cl_prenom);
                          printf("\t\tLe prix totale de velo: %d DH\n",((v+i)->ve_prix)*((v+i)->ve_nbrjour));
                           time_t t=time(0);
             if(((v+i)->ve_duree)>t){
                d=(v+i)->ve_duree-t;
                printf("\t\tLa duree restant: ");conversionsecondes(d);
            }
             else{
                d=t-(v+i)->ve_duree;
                printf("La duree est expire depuis: ");conversionsecondes(d);
             }
                         l=1;
 }}
        if(l==0)
           printf("\n\n\t*************** Le client n\'exist pas***************\n");
}
        k=1;
}}
       if (k==0)
        printf("\n\n\t*************** Le velo n\'exist pas***************\n");
       if(indexc==0)
        printf("\n\n\t*************** Le velo n\'est pas emprunte !!!***************\n");
}

//************************************************************

void conversionsecondes(int n){
     int r,a;
	if (n>0){
	r=n%86400;
	a=(n-r)/86400;
	if (a != 0){
		if (a==1)
			printf(" %d jour", a);
		else
			printf(" %d jours", a);
		}
	n=r;
	r=n%3600;
	a=(n-r)/3600;
	if (a != 0){
		if (a==1)
			printf(" %d heure", a);
		else
			printf(" %d heures", a);
		}
    n=r;
	r=n%60;
	a=(n-r)/60;
	if (a != 0){
		if (a==1)
			printf(" %d minute", a);
		else
			printf(" %d minutes", a);
		}
	a=r;
	if (a != 0){
		if (a==1)
			printf(" %d seconde\n", a);
		else
			printf(" %d secondes\n", a);
		}
	}
}


#endif // EMPRUNTS_H_INCLUDED
