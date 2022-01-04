#include <alloc.h>
#include <assert.h>
#include "FileRCHTDA.h"

struct file *creer_file()
{
    struct file *f;
    f = (struct file *)malloc(sizeof(struct file));
    f->tete = NULL;
    f->queue = NULL;
    return f;
}

unsigned file_vide(struct file *f)
{
    return(f->tete == NULL && f->queue == NULL);
}

int premier(struct file *)
{
    assert(!file_vide(f));
    return(f->tete->cle);
}

void enfiler(int info, struct file *f)
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
        f->tete = p;
    }
    Else
    {
        // cas ou la file n’est pas vide
        f->queue->suivant = p;
    }
    f->queue = p;
}

void defiler(struct file *)
{
    struct element *p;
    assert(!file_vide(f));
    p = f->tete;
    f->tete = f->tete->suivant;
    free(p);
    if (f->tete == NULL)
        f->queue = NULL; // cas où la file contenait 1 seul élément avant le défilement
}