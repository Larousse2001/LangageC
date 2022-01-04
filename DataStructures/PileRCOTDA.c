#include<assert.h>
#include "PileOA.h"

/* Operation de creation */
struct element creer_pile(struct pile *p)
{
    p->sommet=-1;
}

/* Operation de consultation */
unsigned vide(struct pile p)
{
    return(p.sommet==-1);
}

int dernier(struct pile p)
{
    assert(!vide(p));
    return(p.cle[p.sommet]);
}

/* Operation de modification */
void empiler(int info,struct pile *p)
{
    p->sommet++;
    p->cle[p->sommet]=info;
}

void depiler(struct pile *p)
{
    assert(!vide(p));
    p->sommet--;
}