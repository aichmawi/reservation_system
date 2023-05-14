#ifndef CLIENTS_H_INCLUDED
#define CLIENTS_H_INCLUDED

typedef struct clients{
   int cl_index;
   char cl_nom[20];
   char cl_prenom[20];
}clients;
FILE *cl;
//*****************************************

void tableauaufichier(clients *c,int borne){
    int i;
    cl=fopen("clients.txt","w");
     if(cl==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }
    for(i=0;i<borne;i++){
        fprintf(cl,"%d\n%s\n%s\n",(c+i)->cl_index,(c+i)->cl_nom,(c+i)->cl_prenom);
    }
    fclose(cl);
}
//*****************************************

void fichierautableau(clients *c,int *pborne){
    int i=0,j;
    cl=fopen("clients.txt","a+");
     if(cl==NULL){
        printf("\n\n\t*************** Imposible d\'ouvrire le fichier***************\n");
        exit(1);
    }
    while(fscanf(cl,"%d\n%s\n%s\n",&(c+i)->cl_index,(c+i)->cl_nom,(c+i)->cl_prenom)!=EOF){
        i++;
        (*pborne)++;
    }
    fclose(cl);
}

//*****************************************

void ajouterclient(clients *c,int *pborne,int taille){
    int index,i,j,l;
    int k=(*pborne);
    int nbr;
    printf("Donner le nombre de clients a ajouter: ");scanf("%d",&nbr);
     if((*pborne)+nbr-1==taille)
        printf("\n\n\t*************** Impossible d'ajouter un client***************\n");
     else{
            for(int i=k;i<k+nbr;i++){
        printf("------------------------------\n\n");
        do{
        printf("Donner l\'index de client %d: ",i+1);
        scanf("%d",&index);
         j=0;
         for(l=0;l<k+nbr;l++){
         if(index==(c+l)->cl_index){
            printf("\n\n\t*************** Le clinet est deja existe !!!***************\n");
            j++;
         }}}while(j!=0);
         (c+i)->cl_index=index;
        printf("Donner le nom de client %d: ",i+1);
        scanf("%s",(c+i)->cl_nom);
        printf("Donner le prenom de client %d: ",i+1);
        scanf("%s",(c+i)->cl_prenom);
        (*pborne)++;}
     }
}

//********************************************************

void modifierclient(clients *c,int borne){
    int index,i,j=0;
      printf("Donner l\'index de client a modifier: ");
      scanf("%d",&index);
      for(i=0;i<borne;i++){
        if((c+i)->cl_index==index){
           printf("Donner le nouveau nom: ");scanf("%s",(c+i)->cl_nom);
           printf("Donner le nouveau prenom: ");scanf("%s",(c+i)->cl_prenom);
           j=1;
        }
      }
      if(j==0)
        printf("\n\n\t*************** le client n\'existe pas !!!***************\n");
}

//**********************************************************

void supprimerclient(clients *c,int *pborne){
     int i=0,j,k,index;
     printf("Donner l\'index de client a supprimer: ");
     scanf("%d",&index);
   for(j=0;j<(*pborne);j++){
    if((c+j)->cl_index==index)
        i=j;
   }
     if(i==(*pborne))
        printf("\n\n\t*************** le client n\'existe pas !!!***************\n");
     else{
        for(j=i;j<(*pborne);j++){
            (c+j)->cl_index=(c+j+1)->cl_index;
                for(k=0;k<20;k++){
            (c+j)->cl_nom[k]=(c+j+1)->cl_nom[k];
            (c+j)->cl_prenom[k]=(c+j+1)->cl_prenom[k];
        }
        }
        (*pborne)--;
     }
}

//**************************************************

void afficherclients(clients *c,int borne){
    int i,k=65,l=97,j=0;
    do{
     for (i=0;i<borne;i++){
        if((c+i)->cl_nom[0]==k || (c+i)->cl_nom[0]==l ){
            printf("\n\n\t******************Client %d******************\n",j+1);
            printf("\t\tIndex : %d\n",(c+i)->cl_index);
            printf("\t\tNom : %s\n",(c+i)->cl_nom);
            printf("\t\tprenom : %s\n",(c+i)->cl_prenom);
            j++;
        }
     }
     l++;k++;
}while(l<123 && k<91);
    if(j==0)
        printf("\n\n\t*************** Il n\'existe pas de clients !!!***************\n");
}

#endif // CLIENTS_H_INCLUDED
