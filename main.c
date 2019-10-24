#include <stdio.h>
#include <stdlib.h>
#define N 3

struct equipo
{
    char nombre[30];
    int pts,pj,pg,pe,pp,gf,gc,dif;
};
void ordenar(struct equipo[N]);
void mostrar(struct equipo[N]);
int main()
{
    struct equipo tab[N];
    int i;
    for(i=0;i<N;i++)
    {
      printf("Ingrese los datos del equipo %d\nNombre:",i+1);
      fflush(stdin);
      gets(tab[i].nombre);
      printf("\nPG:");
      scanf("%d",&tab[i].pg);
      printf("\nPE:");
      scanf("%d",&tab[i].pe);
      printf("\nPP:");
      scanf("%d",&tab[i].pp);
      printf("\nGF:");
      scanf("%d",&tab[i].gf);
      printf("\nGC:");
      scanf("%d",&tab[i].gc);
      tab[i].pts=(tab[i].pg)*3+(tab[i].pe);
      tab[i].pj=tab[i].pg+tab[i].pe+tab[i].pp;
      tab[i].dif=tab[i].gf-tab[i].gc;
    }
    ordenar(tab);
    system("cls");
    mostrar(tab);
    return 0;
}

void ordenar (struct equipo tabla[N])
{
    struct equipo aux;
    int i,j;
    for(i=0;i<N-1;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(tabla[j].pts>tabla[i].pts)
            {
                aux=tabla[i];
                tabla[i]=tabla[j];
                tabla[j]=aux;
            } else if(tabla[j].pts==tabla[i].pts&&tabla[j].dif>tabla[i].dif)
            {
                aux=tabla[i];
                tabla[i]=tabla[j];
                tabla[j]=aux;
            } else if(tabla[j].pts==tabla[i].pts&&tabla[j].dif==tabla[i].dif&&tabla[j].gf>tabla[i].gf)
            {
                aux=tabla[i];
                tabla[i]=tabla[j];
                tabla[j]=aux;
            }
        }
    }
}

void mostrar(struct equipo T[N])
{
    int i;
    printf("%-30s %5s %5s %5s %5s %5s %5s %5s %5s \n","Equipo","PTS","PJ","PG","PE","PP","GF","GC","DIF");
    for(i=0;i<N;i++)
    {
        printf("%-30s %5d %5d %5d %5d %5d %5d %5d %5d \n",&T[i].nombre[0],T[i].pts,T[i].pj,T[i].pg,T[i].pe,T[i].pp,T[i].gf,T[i].gc,T[i].dif);
    }
}
