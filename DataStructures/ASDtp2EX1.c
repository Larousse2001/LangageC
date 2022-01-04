#include <stdio.h>
#include <stdlib.h>
 
void fusion (int *a, int n, int m) 
{
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) 
    {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) 
    {
        a[i] = x[i];
    }
    free(x);
}
 
void Tri_fusion (int liste[], int taille) 
{
    if (taille < 2) return;
    int milieu = taille / 2;
    Tri_fusion(liste, milieu);
    Tri_fusion(liste, taille - milieu);
    fusion(liste, taille, milieu);
}

void main()
{
    int i;
	int T[6];
    for(i=0;i<6;i++)
	{
		printf("donner l'elementdu tableau T[%d]\n",i);
   	    scanf("%d",&T[i]);
	}
    Tri_fusion(T,5);
    for(i=0;i<6;i++)
	{
		printf("T[%d]=%d \n",i,T[i]);
	}
}