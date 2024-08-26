
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct pers{

        char nom [20];
        int age ;
        char prenom [20];
        struct pers * next;

        // 20 + 20 +4 + 8 =52

}personne;



personne * ajouterdebut(personne * head,personne * nv){
    nv->next = head;
    head=nv;

    return head;

}


void affichageliste (personne * head ){


    personne * it = head;
    printf("AFFICHAGE DE LA LISTE : \n");
    int cpt=1;
   while(it != NULL){

    printf("la personne numero : %d ================ \n",cpt);
    printf("prenom est : %s \n ",it->prenom);
    printf("nom est : %s \n ",it->nom);
    printf("age est : %d \n ",it->age);

    cpt++;
    it= it->next;

   }

}




int menu(){
    int choix;
    printf("saisir 0 -> stop \n");
    printf("saisir 1-> ajouter \n");
    printf("saisir 2-> afficher \n");
    printf("saisir 3-> ajouter au debut \n");
    printf("saisir 4-> ajouter un element par la postion que vous lui donnez \n");
    printf("saisir 5-> supprimer un element par son nom \n");
    printf("saisir 6-> compter le nombre d'element dans la liste  \n");
    printf("saisir 7-> supprimer un element par sa position \n");

    scanf("%d",&choix);

    return choix;

}


// PAS BESOIN DE PARAMETRE POUR LA FONCTION CREATIONPERSONNE CAR ELLE CREATE EN PARTANT DE RIEN

personne * creationPersonne(){


    personne * p1 ;

    p1 = (personne *)malloc(sizeof(personne));

    printf("Donnez le nom \n");
     fflush(stdin);
    scanf("%s",p1->nom);


    printf("Donnez le prenom \n");
     fflush(stdin);
    scanf("%s",p1->prenom);

    printf("Donnez l'age \n");
    fflush(stdin);
    scanf("%d",&p1->age);


    return p1;

}


//AJOUT EN FIN
personne * ajouter(personne * head,personne * nv){
        nv->next =NULL;
        if(head==NULL){
            head = nv;
        }
        else{
                personne * it ;
                it = head;

                while (it->next != NULL){

                    it = it->next;

                }
                it->next = nv;

        }

        return head;
}


void sauvegarde(personne * head , char nomfichier[]){

    personne * temp = head;
    FILE * f = fopen(nomfichier,"w");

    while (temp != NULL){

        fprintf(f,"%s %s %d \n",temp->prenom , temp->nom , temp->age);
        temp = temp->next;
    }
    fclose(f);

}

personne *  createfromfile(char * nomfichier){

    personne * tete = NULL;
    personne * nv ;
    FILE * f = fopen(nomfichier,"r");
    while(!feof(f)){
         nv = (personne*)malloc(sizeof(personne));
         fscanf(f,"%s %s %d \n",nv->prenom , nv->nom , &nv->age);
         tete = ajouter(tete,nv);

    }

    close(f);

    return tete;

}

personne * supprimer(personne * tete,char * nom ){

// si l'on doit changer le premier element de la liste on passe sur la condition if



    if(strcmp(tete->nom,nom) == 0){
                    tete = tete->next;
                    return tete;
                }


    personne * temp = tete;
    personne * prev = temp;
    while(strcmp(temp->nom,nom) != 0 && temp != NULL){
            prev=temp;
            temp = temp->next;
        }


        if (temp == NULL){

            printf("User not found \n");
        }else{

            prev->next = temp->next;
        }

        return tete;

}




personne * ajouterParPos (personne * tete ,personne * nv ,int position){

    if(position ==1){

       tete=ajouterdebut(tete,nv);
       return tete;

    }

    if(position > compteur(tete)){

        tete = ajouter(tete,nv);
        return tete;

    }

    personne * temp = tete;
    int positionTemp =1;
    int n = compteur(tete);

    while (positionTemp != n-1 ){

        temp = temp->next ;
        positionTemp++;

    }

    nv->next = temp->next;
    temp->next =nv;

    return tete;



   /*
        UNE VARIANTE DU WHILE
   for (int i =1 ; i < n-1; i++){

        temp = temp->next ;
    }

        */



}


int compteur(personne * tete){

    int cpt = 0;
    personne * temp = tete;
    while (temp !=NULL){
        temp = temp->next;
        cpt++;
    }


    return cpt;


}


personne * supprimerPos(personne * tete,int pos ){

// si l'on doit changer le premier element de la liste on passe sur la condition if



    if(pos== 1){
                    tete = tete->next;
                    return tete;
                }


    personne * temp = tete;
    personne * prev = temp;

    int tempPos =1;
    while(tempPos != pos && temp != NULL){
            prev=temp;
            temp = temp->next;
            tempPos++;
        }


        if (temp == NULL){

            printf("User not found \n");
        }else{

            prev->next = temp->next;
        }

        return tete;

}






int main()
{
     // creation d'une liste de personne vide
    personne * tete = NULL;

    //creation et ajout du premier element
    personne * nv ;
int choix;

//declaration pour delete
char nomd [20];
// delcaration postion
int pos;
do{
    choix = menu();
    switch (choix){
    case 0 : printf("you chose to stop the prgm \n");
                break;
    case 1 : nv = creationPersonne();
             tete=ajouter(tete,nv);
                break;
    case 2: affichageliste(tete);
                break;
    case 3 :nv = creationPersonne();
            tete=ajouterdebut(tete,nv);
                break;

    case 4 : nv = creationPersonne();
             printf("saisir une postion pour ajouter \n");
             fflush(stdin);
             scanf("%d",&pos);
             tete=ajouterParPos(tete,nv,pos);
                break;

    case 5:
             printf("saisir un nom pour delete \n");
             fflush(stdin);
             scanf("%s",nomd);
             tete=supprimer(tete,nomd);
                break;

    case 6 :
             printf("Nous avons %d elements dans cette liste \n ",compteur(tete));
                break;


    case 7 : printf("saisir une position pour delete \n");
             fflush(stdin);
             scanf("%d",&pos);
             tete=supprimerPos(tete,pos);
                break;

    default :  printf("choix non valide veuillez re essayer \n");
                break;


}

}while(choix != 0);

sauvegarde(tete,"data.txt");

personne * tete2 = createfromfile("data.txt");
affichageliste(tete2);



}
