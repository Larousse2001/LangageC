#include<assert.h>
#include "PileOA.h"

/* DÃ©finition d'une Pile */
#define N1 100
struct pile
{
    int cle[N];
    int sommet;
};
static struct pile p;
/* Operation de creation */
struct element creer_pile()
{
    p.sommet=-1;
}

/* Operation de consultation */
unsigned vide()
{
    return(p.sommet==-1);
}

int dernier()
{
    assert(!vide());
    return(p.cle[p.sommet]);
}

/* Operation de modification */
void empiler(int info)
{
    p.sommet++;
    p.cle[p.sommet]=info;
}

void depiler()
{
    assert(!vide());
    p.sommet--;
}