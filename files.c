#include <stdio.h>
#include <stdlib.h>


typedef struct human {

    char fname[100];
    int hage;
}human;






int main()
{
   /* FILE * f = fopen("test.txt","w");
    if (f == NULL){
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    printf("Le contenu de f est : %p",f);

    char phrase[] = "Salut ceci est un test";


    fprintf(f,"la phrase est : %s",phrase);

    */


    char nom [100];
    int age;
    human personne [4];
    FILE * f2 = fopen("test.txt","r");
     if (f2 == NULL){
        printf("Erreur d'ouverture du fichier");
        return 1;
    }


    human tab[4];
    int i = 0;


    while(!feof(f2)){
        fscanf(f2,"%s %d",tab[i].fname,&tab[i].hage);
        i++;
    }

    for (i=0; i<4 ; i++){
        printf("nom : %s et age : %d \n",tab[i].fname,tab[i].hage);

    }





    return 0;
}
