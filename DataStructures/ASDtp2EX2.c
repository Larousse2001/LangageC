#include <stdlib.h>
#include <stdio.h>

void Tri_Rapide(int T[],unsigned a,unsigned b)
{
    int i,j,k,l,c,pivot,tmp,aux;
    c=(a+b)/2;
    if(b<2) return;
    pivot=T[c];
    i=j=0;
    while (i<c)
    {
        if (T[i]<=pivot)
        {
            if (j!=i)
            {
                tmp=T[i];
                T[i]=T[j];
                T[j]=tmp;
            }
            j++;
        }
        i++;
    }
    k=l=c+1;
    while (k<b)
    {
        if (T[k]<=pivot)
        {
            if (l!=k)
            {
                aux=T[k];
                T[k]=T[l];
                T[l]=aux;
            }
            l++;
        }
        k++;
    }
    Tri_Rapide(T,0,j-1);
    Tri_Rapide(T,j-1,c-j+1);
    Tri_Rapide(T,c+1,l-1);
    Tri_Rapide(T,l-1,b-l+1);
}

void main()
{
    int i;
	int T[6];
    for (i = 0; i < 6; i++)
    {
        printf("donner l'element du tableau T[%d]= \n",i);
        scanf("%d",&T[i]);
    }
    Tri_Rapide(T,0,5);
    for (i = 0; i < 6; i++)
    {
        printf("T[%d]=%d\t",i,T[i]);
    }
    
}