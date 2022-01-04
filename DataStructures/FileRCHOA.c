#include <alloc.h>
#include <assert.h>
#include "FileRCHTDA.h"


/* représentation Chainée */
struct element
{
    int cle;
    struct element *suivant;
};
static struct element *tete;
static struct element *queue;


struct file creer_file()
{
    tete = NULL;
    queue = NULL;
}

unsigned file_vide()
{
    return(tete == NULL && queue == NULL);
}

int premier()
{
    assert(!file_vide());
    return (tete->cle);
}

void enfiler(int info)
{
    // preparation du nouvel élément
    struct element *p;
    p= (struct element *) malloc(sizeof(struct element);
    p->cle= info ;
    p->suivant = NULL;
    // chainage : deux cas  à envisager
    if (file_vide(f)
    {
        // cas file vide
        tete = p;
    }
    Else
    {
        // cas ou la file n’est pas vide
        queue->suivant = p;
    }
    queue = p;
}

void defiler()
{
    struct element *p;
    assert(!file_vide(f));
    p = tete;
    tete = tete->suivant;
    free(p);
    if (tete == NULL)
        queue = NULL; // cas où la file contenait 1 seul élément avant le défilement
}