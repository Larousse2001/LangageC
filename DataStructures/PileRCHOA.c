#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "PileRCHOA.h"

/* DÃ©finition d'une Pile */

struct element
{
    int cle;
    struct element *suivant;
};
struct element *sommet;
int nb;
/* Operation de creation */
struct element creer_pile(void)
{
    sommet=NULL;
    nb=0;
}

/* Operation de consultation */
unsigned vide(void)
{
    //1 si la pile est vide sinon 0
    return(sommet==NULL);
}

int dernier(void)
{
    assert(!vide());
    return(sommet->cle);
}

int nb_element(void)
{
    return nb;
    // struct element p;
    // p=sommet;
    // int length = 0;

	// while(p!=NULL)
	// {
	// 	length++;
	// 	p = p->suivant;
	// }

	// return length;
}
/* Operation de modification */
void empiler(int info)
{
    struct element *p;
    p=(struct element*)malloc(sizeof(struct element*));
    p->cle=info;
    p->suivant=sommet;
    sommet=p;
    nb++;
}

void depiler(void)
{
    struct element *p;
    assert(!vide());
    p=sommet;
    sommet=sommet->suivant;
    free(p);
    nb--;
}

void effacer(void)
{
    while(!vide())
		depiler();
}

void change_sommet(int info)
{
    assert(!vide());
    sommet->cle=info;
}