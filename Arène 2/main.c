#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void perso(int** map)
{
    int a,b;
}

void affichage(int taille,int** map) //affiche l'arène
{
    int i,j;
    printf(" ");
    for (i=1;i<taille+2;i++)
    {
        Color(13,0);
        printf("~~");
    }
    printf("\n");
    for (j=taille-1;j>=0;j--)
    {
        if (j == 0)
        {
            Color(10,0);
            printf("->");
        }else
        {
            Color(13,0);
            printf(" |");
        }
        for (i = 0; i < taille; i++)
        {
            if (map[i][j] == 0)
            {
                Color(0,2);
                printf("  ");
            }else if(map[i][j]==1)
            {
                Color(0,1);
                printf("  ");
            }else
            {
                Color(0,4);
                printf("  ");
            }
        }
        if (j == taille-1)
        {
            Color(10,0);
            printf("->");
        }else
        {
            Color(13,0);
            printf("| ");
        }
        printf("\n");
    }
    printf(" ");
    for (i=1;i<taille+2;i++)
    {
        Color(13,0);
        printf("~~");
    }
    printf("\n");
    Color(15,0);
}

void creation(int taille,int** map) //crée l'arène
{
    int i, j;
    for (i=0;i<taille;i++)
    {
        for (j=0;j<taille;j++)
        {
            if (rand() / (RAND_MAX+1.0) < 0.2) //Un mur a une probabilité de 0.3 d'apparaître sur une case
            {
                map[i][j] = 1;//il y aura un mur
            }else if (rand() / (RAND_MAX+1.0) < 0.02)
            {
                map[i][j] = 2;//il y a un piège
            }else
            {
                map[i][j]=0;//il n'y a pas de murs
            }
        }
    }
}

int main()
{
    int taille=39;//taille du labyrinthe (il est carré)
    int entree_x = 0;
    int entree_y = 0;
    int sortie_x = taille-1;
    int sortie_y = taille-1;
    int** map=NULL;
    int i;
    system("cls");
    map=malloc(taille*sizeof(int*));
    for(i=0;i<taille;i++)
    {
        map[i]=malloc(taille*sizeof(int));
    }
    srand(time(NULL));
    creation(taille,map);
    map[entree_x][entree_y] = 0;
    map[sortie_x][sortie_y] = 0;
    affichage(taille,map);
    for(i=0;i<taille;i++)
    {
        free(map[i]);
    }
    free(map);
    return 0;
}
