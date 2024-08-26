#include <stdio.h>
#include <stdlib.h>


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



int main()
{
     // creation d'une liste de personne vide
    personne * tete = NULL;

    //creation et ajout du premier element
    personne * nv ;
int choix;


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
    default :  printf("choix non valide veuillez re essayer \n");
                break;


}

}while(choix != 0);

sauvegarde(tete,"data.txt");

personne * tete2 = createfromfile("data.txt");
affichageliste(tete2);



}
