#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EX4_Matrice_Creuse.h"

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void initialiser(struct liste *l)
{
    l->first=NULL;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void ajouter(struct liste *l,struct ETD *E)
{
    struct ETD *p;
    p=l->first;
    if(p==NULL)
    	{
    		p=E;
    		l->first=p;
		}
	else
	{
		
		while (p->next != NULL)
    	{
        	p=p->next;
    	}		
    	p->next=E;
	}
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct Matrix *creer_matrice(void)
{
    struct Matrix *m ;
    m=(struct Matrix*) malloc (size of(struct Matrix)) ;
    m->cols=NULL;
    m->cols=NULL;
    return m; 
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void  ajouter_element(int c,int r,struct liste l)
{
    struct Matrix m;
    m.cols=c;
    m.rows=r;
    for(int i=0;  i<m.rows ; i++)
    { 
        for (int j = 0; j < m.cols; j++)
        {
            printf("donner l'entier m[i][j]",i,j);
            scanf("%f",m[i][j]);
        }
        consulter_element(m);
        m->next=NULL;
        ajouter(l,m);
    }
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

unsigned consulter_element(struct Matrix m)
{
    if (m.data != 0)
    {
        return m.data;
    }
    return NULL;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct Matrix existe(int,struct Matrix m)
{
    int exist=0;
    if ( consulter_element(m)!=NULL)
    {
        exist=1;
    }
    return exist;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void modifier_element(int struct Matrix m)
{
    float tmp;
    printf("modifier l'element \n");
    scanf("%f",&tmp);
    m.data=tmp;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct Matrix afficher_matrice(void)
{
	for (int i = 0; i < m->rows; i++)
	{
		for (int j = 0; j < m->cols; j++)
		{
			printf("%f", m->data[i][j]);
		}
	}
}