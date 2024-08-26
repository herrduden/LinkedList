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


typedef struct  {
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





int menu(){
    int choix;
    printf("saisir 0 -> stop \n");
    printf("saisir 1-> creer une liste  \n");
    printf("saisir 2-> ajouter un element au debut \n");
    printf("saisir 3-> ajouter un element par position \n");
    printf("saisir 4-> ajouter un element a la fin  \n");
    printf("saisir 5-> Afficher la liste DEBUT -> FIN\n");
    printf("saisir 6-> Afficher la liste FIN -> DEBUT \n");
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
    scanf("%d",&nv->year);

    nv ->prev =NULL;
    nv->next = NULL;
    return nv;



}

listeCars * ajouterDebut (listeCars * l , car * nv){

    if (l->nbCars ==0){
	l->debut = nv;
	l->fin = nv;
	nv->next = NULL;
	nv->prev = NULL;
	l->nbCars ++;
	return l;
}

    nv->next = l->debut;
    nv->prev = NULL;
    l->debut->prev = nv;
    l->debut = nv;
    l->nbCars ++;


return l ;

}


listeCars * ajouterFin (listeCars * l , car * nv){

    if (l->nbCars ==0){
	l->debut = nv;
	l->fin = nv;
	nv->next = NULL;
	nv->prev = NULL;
	l->nbCars ++;
	return l;
}

    nv->next = NULL;
    nv->prev = l->fin;
    l->fin->next = nv;
    l->fin = nv;
    l->nbCars ++;

return l ;

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




void affichageDeb (listeCars * l ){

car * temp = l->debut;

    while(temp !=  NULL ){

        printf("model: %s         color : %s        year : %d \n",temp->model,temp->color,temp->year);
        temp = temp->next;

    }


}



void affichageFin (listeCars * l ){

car * temp = l->fin;

    while(temp !=  NULL ){

        printf("model: %s         color : %s        year : %d \n",temp->model,temp->color,temp->year);
        temp = temp->prev;

    }


}






int main()
{


int choix;
listeCars * newListe;
car * nv;
int flag =0;
int position ;
do{
    choix = menu();
    switch (choix){
    case 0 : printf("you chose to stop the prgm \n");
                break;
    case 1 :
            if (flag == 0 ){
               newListe = creationListe();

              if (newListe != NULL){
                printf("Creation de la liste reussie \n");
                flag = 1;}
              else choix = 0;

                break;
            }else{

                 printf("La liste est deja creee \n");
                break;
            }

    case 2 : nv =createCar();
            newListe = ajouterDebut(newListe,nv);
                break;
    case 3 : nv =createCar();
            printf("Donnez la position dans laquelle vous voulez place l'element \n");
            scanf("%d",&position);
            newListe = ajouterParPos(newListe,nv,position);
                break;
    case 4 : nv =createCar();
             newListe = ajouterFin(newListe,nv);
                break;
    case 5 : affichageDeb(newListe);
                break;

    case 6 : affichageFin(newListe);
                break;
    default :  printf("choix non valide veuillez re essayer \n");
                break;


}

}while(choix != 0);





return 0;
}

