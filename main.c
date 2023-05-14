#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "clients.h"
#include "velos.h"
#include "emprunts.h"
const taille=200;
int main()
{
    clients cl[taille];
    velos ve[taille];
    int bornec=0,bornev=0;
    int choix1,choix2;
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,11);
fichierautableau(cl,&bornec);
fichierautableauv(ve,&bornev);
start:
    printf("\n\n\n************************** Menu Principale******************************\n\n");
    printf("\t\t1- Gestion des clients\n");
    printf("\t\t2- Gestion des velos\n");
    printf("\t\t3- Gestion des emprunts\n");
    printf("\t\t4- Enregistrer et quitter le programme\n");
    printf("Donner votre choix: ");scanf("%d",&choix1);
    do{
    system("cls");
    switch(choix1){
    case 1:{
            do{
            printf("\n\n\n\t****************** Menu des clients******************\n\n");
            printf("\t\t1- Ajouter un client\n");
            printf("\t\t2- Modifier un client\n");
            printf("\t\t3- Supprimer un client\n");
            printf("\t\t4- Afficher la liste des clients par ordre alphabetique\n");
            printf("\t\t5- Retour en arriere\n");
            printf("Donner votre choix: ");scanf("%d",&choix2);
             system("cls");
            switch(choix2){
              case 1:{ajouterclient(cl,&bornec,taille);getch();system("cls");break;}
              case 2:{modifierclient(cl,bornec);getch();system("cls");break;}
              case 3:{supprimerclient(cl,&bornec);system("cls");break;}
              case 4:{afficherclients(cl,bornec);getch();system("cls");break;}
              case 5:{goto start;}
              default:{printf("Donner un nombre entre [1-5]");choix2=10;}
            }}while(choix2==10);
            goto start;
        ;break;}
    case 2:{do{
            printf("\n\n\n\t****************** Menu des velos******************\n\n");
            printf("\t\t1- Ajouter un velo\n");
            printf("\t\t2- Modifier un velo\n");
            printf("\t\t3- Supprimer un velo\n");
            printf("\t\t4- Afficher la liste des velos par ordre alphabetique\n");
            printf("\t\t5- Retour en arriere\n");
            printf("Donner votre choix: ");scanf("%d",&choix2);
            system("cls");
            switch(choix2){
              case 1:{ajoutervelo(ve,&bornev,taille);system("cls");break;}
              case 2:{modifiervelo(ve,bornev);getch();system("cls");break;}
              case 3:{supprimervelo(ve,&bornev);system("cls");break;}
              case 4:{affichervelos(ve,bornev);getch();system("cls");break;}
              case 5:{goto start;}
              default:{printf("Donner un nombre entre [1-5]");choix2=10;}
            }}while(choix2==10);

            goto start;
            ;break;}
    case 3:{
            do{
            printf("\n\n\n\t****************** Menu des emprunts******************\n\n");
            printf("\t\t1- Emprunter un velo\n");
            printf("\t\t2- Rendre un velo\n");
            printf("\t\t3- Afficher la liste des velos empruntes\n");
            printf("\t\t4- Afficher l\'emprunteur de velos\n");
            printf("\t\t5- Retour en arriere\n");
            printf("Donner votre choix: ");scanf("%d",&choix2);
            system("cls");
            switch(choix2){
              case 1:{empruntervelo(cl,ve,bornec,bornev);getch();system("cls");break;}
              case 2:{rendrevelo(cl,ve,bornec,bornev);getch();system("cls");break;}
              case 3:{velosempruntes(ve,bornev);getch();system("cls");break;}
              case 4:{emprunteursvelo(cl,ve,bornec,bornev);getch();system("cls");break;}
              case 5:{goto start;}
              default:{printf("Donner un nombre entre [1-5]");choix2=10;}
            }}while(choix2==10);

            goto start;
            ;break;}
    case 4:{printf("\n\n\n\t******************Fin de traitement !!!******************\n");break;}
    default:{printf("Donner un nombre entre [1-4]");goto start;
    }
    }
    getch();
    }while(choix1!=4);
    tableauaufichier(cl,bornec);
    tableauaufichierv(ve,bornev);
    return 0;
}

