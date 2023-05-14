#ifndef VELOS_H_INCLUDED
#define VELOS_H_INCLUDED

typedef struct velos{
   int ve_index;
   char ve_type[20];
   int ve_prix;
   int ve_duree;
   int ve_nbrjour;
   int ve_emprunteur;
}velos;
FILE *ve;
//*****************************************

void tableauaufichierv(velos *v,int borne){
    int i;
    ve=fopen("velos.txt","w");
     if(ve==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }
    for(i=0;i<borne;i++){
        fprintf(ve,"%d\n%s\n%d\n%d\n%d\n%d\n",(v+i)->ve_index,(v+i)->ve_type,(v+i)->ve_prix,(v+i)->ve_duree,(v+i)->ve_nbrjour,(v+i)->ve_emprunteur);
    }
    fclose(ve);
}
//*****************************************

void fichierautableauv(velos *v,int *pborne){
    int i=0,j;
    ve=fopen("velos.txt","a+");
     if(ve==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }
    while(fscanf(ve,"%d\n%s\n%d\n%d\n%d\n%d\n",&(v+i)->ve_index,(v+i)->ve_type,&(v+i)->ve_prix,&(v+i)->ve_duree,&(v+i)->ve_nbrjour,&(v+i)->ve_emprunteur)!=EOF){
        i++;
        (*pborne)++;
    }
    fclose(ve);
}

//*****************************************


void ajoutervelo(velos *v,int *pborne,int taille){
    int index,i,j,l;
    int k=(*pborne);
    int nbr;
    printf("Donner le nombre de velo a ajouter: ");scanf("%d",&nbr);
     if((*pborne)+nbr-1==taille)
        printf("\n\n\t*************** Impossible d'ajouter un velo***************\n");
     else{
            for(int i=k;i<k+nbr;i++){
        printf("------------------------------\n\n");
        do{
        printf("Donner l\'index de velo %d: ",i+1);
        scanf("%d",&index);
         j=0;
         for(l=0;l<k+nbr;l++){
         if(index==(v+l)->ve_index){
            printf("\n\n\t*************** Le velo est deja existe !!!***************\n");
            j++;
         }}}while(j!=0);
         (v+i)->ve_index=index;
        printf("Donner le type de velo %d: ",i+1);
        scanf("%s",(v+i)->ve_type);
        printf("Donner le prix de velo par jour: ",i+1);
        scanf("%d",&(v+i)->ve_prix);
        (*pborne)++;}
     }
}

//********************************************************

void modifiervelo(velos *v,int borne){
    int index,i,j=0;
      printf("Donner l\'index de velo a modifier: ");
      scanf("%d",&index);
      for(i=0;i<borne;i++){
        if((v+i)->ve_index==index){
           printf("Donner le noveau type: ");scanf("%s",(v+i)->ve_type);
           printf("Donner le noveau prix: ");scanf("%d",&(v+i)->ve_prix);
           j=1;
        }
      }
      if(j==0)
        printf("\n\n\t*************** Le velo n\'existe pas !!!***************\n");
}

//**********************************************************

void supprimervelo(velos *v,int *pborne){
     int i=-1,j,k,index;
     printf("Donner l\'index de velo a supprimer: ");
     scanf("%d",&index);
   for(j=0;j<(*pborne);j++){
    if((v+j)->ve_index==index)
        i=j;
   }
     if(i==-1)
     {
        printf("\n\n\t*************** Le velo n\'existe pas !!!***************\n");
        getch();
     }
     else{
        for(j=i;j<(*pborne);j++){
            (v+j)->ve_index=(v+j+1)->ve_index;
                for(k=0;k<20;k++){
            (v+j)->ve_type[k]=(v+j+1)->ve_type[k];
                }
            (v+j)->ve_prix=(v+j+1)->ve_prix;
            (v+j)->ve_duree=(v+j+1)->ve_duree;
            (v+j)->ve_nbrjour=(v+j+1)->ve_nbrjour;
            (v+j)->ve_emprunteur=(v+j+1)->ve_emprunteur;
        }
        (*pborne)--;
     }
}

//************************************************

void affichervelos(velos *v,int borne){
    int i,k=65,l=97,j=0;
    do{
     for (i=0;i<borne;i++){
        if((v+i)->ve_type[0]==k || (v+i)->ve_type[0]==l ){
            printf("\n\n\t******************Velos %d******************\n",j+1);
            printf("\t\tIndex : %d\n",(v+i)->ve_index);
            printf("\t\tType : %s\n",(v+i)->ve_type);
            printf("\t\tPrix par jour : %d DH\n",(v+i)->ve_prix);
            j++;
        }
     }
     l++;k++;
}while(l<123 && k<91);
     if(j==0)
        printf("\n\n\t*************** Il n\'existe pas de velos !!!***************\n");
}


#endif // VELOS_H_INCLUDED
