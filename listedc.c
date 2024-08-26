#include <stdio.h>
#include <stdlib.h>
#include <string.h>




typedef struct car{

    int year ;
    char model[30];
    char color [30];
    struct car * next ;
    struct car * prev;


}car;


typedef struct listeCars {
    car * debut;
    car * fin;
    int nbCars;


}listeCars;

listeCars * creationListe(){

    listeCars * l= (listeCars *)malloc(sizeof(listeCars)) ;

    if(l != NULL){
        l->debut = NULL;
        l->fin= NULL;
        l->nbCars =0;

    }

    return l;
}


void affichageliste (listeCars * l ){


    car * it = l->debut;
    printf("AFFICHAGE DE LA LISTE : \n");
    int cpt=1;
   while(it != NULL){

    printf("la personne numero : %d ================ \n",cpt);
    printf("model: %s         color : %s        year : %d \n ",it->model,it->color,it->year);


    cpt++;
    it= it->next;

   }


int menu(){
    int choix;
    printf("saisir 0 -> stop \n");
    printf("saisir 1-> creer une liste  \n");
    printf("saisir 2-> ajouter un element au debut \n");
    printf("saisir 2-> ajouter un element a la fin \n");
    printf("saisir 2-> ajouter un element par position \n");
    scanf("%d",&choix);

    return choix;

}


car * createCar (){
    car * nv;

    nv = (car *)malloc(sizeof(car));

    printf("Donnez un model \n");
    fflush(stdin);
    scanf("%s", nv->model);

    printf("Donnez une couleur \n");
    fflush(stdin);
    scanf("%s", nv->color);

    printf("Donnez une annee \n");
    fflush(stdin);
    scanf("%d",nv->year);

    nv ->prev =NULL;
    nv->next = NULL;
    return nv;



}




car * ajouterParPos (listeCars * l , car * nv, int position){

if (position == 1){
    l = ajouterDebut(l,nv);
    return l;
}
if (position > l->nbCars){
    l = ajouterFin(l,nv);
    return l;
}

car * temp = l->debut ;
car * ptemp = temp;

for (int i=1 ; i<= position -1 ; i++){
    ptemp =temp;
    temp=temp->next;
}

nv->next =temp;
nv->prev=ptemp;
ptemp->next=nv;
temp->prev=nv;

return l;

}

listeCars * ajouterDebut (listeCars * l , car * nv){

    nv->next = l->debut;
    nv->prev = NULL;
    l->debut->prev = nv;
    l->debut = nv;
    l->nbCars ++;


return l ;

}


listeCars * ajouterFin (listeCars * l , car * nv){

    nv->next = NULL;
    nv->prev = l->fin;
    l->fin->next = nv;
    l->fin = nv;
    l->nbCars ++;

return l ;

}


int main()
{


int choix;
listeCars * newListe;
do{
    choix = menu();
    switch (choix){
    case 0 : printf("you chose to stop the prgm \n");
                break;
    case 1 : newListe = creationListe();
              if (newListe != NULL)
                printf("Creation de la liste reussie");
              else choix = 0;
                break;
    case 2 :
    default :  printf("choix non valide veuillez re essayer \n");
                break;


}

}while(choix != 0);





return 0;
}

