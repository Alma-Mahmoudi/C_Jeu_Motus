#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "bib.h"

char check(char a, char word[10] )  //fonction teste l'existence du lettre dans le mot
{

    int i, freq = 0, test = 0;
    for (i = 1; i < strlen(word); i++)
    {
        if (word[i] == a)
        {
            test = 1;
            freq++;
        }
    }
    if (!test)
    {
        printf("\e[1;30m"); //s'il n'existe pas il affiche -
        printf("\t - ");
    }

    else
    {
        printf("\e[1;35m");
        printf("\t %c",a); //s'il existe la lettre va afficher avecun couleur different
    }

}

int nb,nbt; //nb =nb de joueurs , nbt: nb de tentaives totale
int i,j,l,k,z,c,n,m,w,ch1,ch2;
FILE *fp;   // fichier
je*tab;   //tableau des joueurs
char m1[50][10],line[200],w1[10],w2[10],m2[50][10],nom[10];


int main()
{
    system("color F0");  //pour arrière plan blanc brillant et l'ecriture en bleu
    printf("\e[1;94m");
    printf("     *----------------------------------------------------------------* \n");
    printf("     *                                                                * \n");
    printf("     *                                                                * \n");
    printf("     *            SHIILI Siwar                                        * \n");
    printf("     *            MAHMOUDI ALMA                                       * \n");
    printf("     *                                                                * \n");
    printf("     *            INFOTRONIQUE 1-B-GP2                                * \n");
    printf("     *            ENICARTHAGE 2020/2021                               * \n");
    printf("     *                                                                * \n");
    printf("     *                                                                * \n");
    printf("     *                                                                * \n");
    printf("     * ---------------------------------------------------------------* \n");
    printf("\e[1;30m");
    printf("\n please wait");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    system("cls");
    printf("\e[1;94m");
    printf("===================================================================================== \n");
    printf("*                                                                                    *\n");
    printf("*                                   JEU MOTUS :                                      * \n");
    printf("*                                    MENU:                                           *\n");
    printf("*                                                                                    *\n");
    printf("===================================================================================== \n");
    e1:
    printf("\n\n\n Choose: \n\n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("  [1] Espace du mot                                                                   \n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("  [2] Espace du jeu                                                                   \n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("  [3] QUITTER                                                                         \n");
    printf("--------------------------------------------------------------------------------------\n");
    printf("\n\n -->  ");
    scanf("%d",&ch1);
    switch(ch1)
    {
    case 1:
        printf("\n GO TO Espace du mot: \n");
        goto EspaceMot;
        break;
    case 2:
        printf("\n GO TO Espace du jeu:");
        goto EspaceJeu;
        break;
    case 3:
        printf("\n See you soon! \n\n\n");
        goto e4;
    default:
        printf("\n !try again! \n");
        goto e1;
    }

    EspaceMot:
        sleep(2);
        system("cls");
        printf("\e[1;32m");  //couleur
        printf("\n------------------------------------------------------------------\n");
        printf("\n **********************   Allez jouez   ************************ \n ");
        printf("\n------------------------------------------------------------------\n");
        do
        {
            printf("\e[1;30m");
            printf("\n entrer le mot a deviner(entre 5 et 10 lettres): ");
            scanf("%s",&w1);
            fp = fopen("Lesmooots.txt","r");
            while ( fgets ( line, 200, fp ) != NULL )
            {
                if(strstr(line,w1))
                {
                    printf("\e[1;31m");
                    printf("\n le mot ete traite avant,essayer une autre! \n");
                }
            }
        }
        while( (strlen(w1)<5) || (strlen(w1)>10) || strstr(line,w1) );

        fp=fopen("Lesmooots.txt", "a");
        fprintf(fp,"-----------------------\n");
        fflush(fp);
        fprintf(fp, "mot : \t %s\n", w1);
        fflush(fp);
        printf("\e[1;34m");
        printf("\n le mot enregistre dans le fichier.");

        for(j=0;j<10;j++)
            m1[0][j]=w1[j];
        do
        {   printf("\e[1;30m");
            printf("\n\n saisie nombre des joueurs : ");
            scanf("%d",&nb);
        }
        while(nb<2);
        printf("\e[1;94m");
        nbt=nb*2;
        printf("\n nombre de tentatives total est :  %d  \n",nbt);
        printf("\n                                                \n");
        printf("\n Donc chaque joueur a 2 tentatives,,, GOOD LUCK ");
        printf("\n------------------------------------------------\n");
        for(i=0;i<nbt;i++)
        {
          for(j=0;j<(strlen(w1));j++)
             m2[i][0]=w1[0];
             printf("%c",m2[i][0]);
          putchar('\n');}
        printf("\n------------------------------------------------\n");
        sleep(2);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);

        tab = (je*) malloc( nb * sizeof(je) ); // creer un tableau(dynamique) des joueurs
        if(!tab) exit(-1);

        sleep(2);
        system("cls");
        goto e1;   //revient au menu 1


    EspaceJeu:
        sleep(2);
        system("cls");
        for(n=0; n<nb;n++)
        {
            printf("\n nom de joueur %d : ", n+1);
            scanf(" %s",&tab[n].nom);
        }
        sleep(2);
        system("cls");
        nbt=2*nb;
        l=nbt;
        c=strlen(w1);
        printf("\e[1;32m");
        printf("\n--------------------------------------------------------------------\n");
        printf("\n                                                                    \n");
        printf("\n*************************  Guess the word: ************************* \n");
        printf("\n                                                                     \n");
        printf("\n-------------------------------------------------------------------- \n");


        for(k=0; k<2; k++)     //2=t/nb
        {
        tab[z].sc=0;      //initialisation de score
        for(z=0; z<nb; z++)
        {
        printf("\e[1;30m");
        printf("\n\n Joeur %s \n",tab[z].nom);
        for(i=0; i<1; i++)
        {
            m2[i][0]=w1[0];
            e2:
            printf("\e[1;32m");
            printf("\n %c",m2[i][0]);
            printf("\e[1;30m");
            scanf(" %s",&w2);
            for(int j=0; j<c; j++)
                m2[i][j+1]=w2[j];
            if ((strlen(m2[i])) != strlen(w1) )
            {
                printf("\e[4m");
                printf("\e[1;31m");
                printf("\n WARNING: mot max %d lettres. \n",c);
                printf("\e[24m");
                goto e2;
            }

            else
            {

                if (strcmp(w1, m2) == 0) //strcmp pour comparer les deux mots s'ils sont identiques il renvoie 0
                    {
                        tab[z].sc = c;
                        system("cls");
                        printf("\e[4m");
                        printf("\e[1;32m");
                        printf("\n\n [-- WINNER --] joueur %s  -->  %d ",tab[z].nom, tab[z].sc); //le mot s'affiche et le joueur gagne la partie
                        printf("\e[24m");
                        goto e3;    //sauter dans la fin de prog
                    }


                printf("\e[1;32m");
                printf(" %c ", m2[i][0]);

                for(m=1, w=1; m<c, w<c; m++, w++)
                {
                    if (m2[i][m]==w1[w]) //sinon caomparer lettre par lettre
                    {
                        printf("\e[1;32m");
                        printf("\t %c",m2[i][m]); //s'il sont identiques la lettre va colorer en vert

                    }
                    else
                        check(m2[i][m], w1); //sinon tester par la fonction check seulement la lettre mal placée
                                            //afficher avec un couleur different sinon supprimer
                }
    }
    }
    }
    }
    printf("\e[4m");
    printf("\e[1;31m");
    printf("\n\n\n [ fin tentatives !! ] \n"); sleep(2);   //fin de tentatives
    printf("\e[24m");

    system("cls");
    e3 :
    sleep(1);

    printf("\e[4m");
    printf("\e[1;31m");
    printf("\n\n [-- GAME OVER --] \n");
    printf("\e[24m");
    printf("\e[1;34m");
    printf("\n le mots *** %s *** \n",w1);
    printf("\n------------------------------------------\n");
    for(j=0; j<nb; j++)
    {
        printf(" SCORE joueur %s",tab[j].nom);  printf("\t -->  [ %d ] ",tab[j].sc);//afficher les joueures et leurs scores a travers la structure
        printf("\n------------------------------------------\n");
    }

    e5: printf("\n\n [Q]: veulez vous poursuivre le jeu ? \n");
    printf("------------------------------------------------\n");
    printf("  [1] OUI                                       \n");
    printf("------------------------------------------------\n");
    printf("  [2] NON                                       \n");
    printf("------------------------------------------------\n");
    printf("\n\n -->  ");
    scanf("%d",&ch2);
    switch(ch2)
    {
    case 1:
        system("cls");
        printf("\n [-- RESTART --] \n"); //revien a la 1ere menu
        sleep(2);
        goto e1;
        break;
    case 2:
        printf("\e[1;30m");
        printf("\n See you soon! \n\n\n"); //sauter a la fin de prog
        sleep(2);
        goto e4;
    default:
        system("cls");
        printf("\n !try again! \n");
        goto e5;
    }

    e4:
        system("cls");

        printf("\n\n [-- THE END --] \n");

return 0;
}
