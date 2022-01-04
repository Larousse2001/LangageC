#include<stdio.h>
#include<assert.h>
#include<alloc.h>
#include "PileRCHTDA.h"

/* Operation de creation */
struct element creer_pile(void)
{
    return NULL;
}

/* Operation de consultation */
unsigned vide(struct element *p)
{
    //1 si la pile est vide sinon 0
    return(p==null);
}

int dernier(struct element *p)
{
    assert(!vide(p));
    return(p->cle);     // return((*sommet).cle)
}

/* Operation de modification */
void empiler(int info,struct element* *p)
{
    struct element *q;
    q=(struct element*)malloc(sizeof(struct element*));
    q->cle=info;
    q->suivant=*p;
    *p=q;
}

void depiler(struct element* *p)
{
    struct element *q;
    assert(!vide(*p));
    q=*p;
    *p=q->suivant;
    free(q);
}