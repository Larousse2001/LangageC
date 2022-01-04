#include <alloc.h>
#include <assert.h>
#include <stdio.h>
#include "Deque.h"

struct deque *creer_deque()
{
    struct deque *d;
    d = (struct deque *)malloc(sizeof(struct deque));
    d->extrD=NULL;
    d->extrG= NULL;
    return d;
}

unsigned deque_vide(struct deque *d)
{
    return(d->extrD == NULL && d->extrG == NULL);
}

int extremite(struct deque *d)
{
    int n;
    //si n=1 ==> extremité gauche sinon extremité droite
    assert(!deque_vide(f));
    printf("Choisir l'extremité affiché (1==>gauche && 0==>droite");
    scanf("%d",&n);
    assert((n==1)&&(n==0));
    if (n==1)
    {
        return(d->extrG->cle)
    }
    else
    {
        return(d->extrD->cle);
    }
}

void endequer(int info, struct deque *d)
{
    // preparation du nouvel élément
    struct element *p;
    p= (struct element *) malloc(sizeof(struct element);
    p->cle= info ;
    p->suivant = NULL;
    int n;
    //si n=1 ==> extremité gauche sinon extremité droite
    assert(!deque_vide(f));
    printf("Choisir l'extremité ou on va ajouter (1==>gauche && 0==>droite");
    scanf("%d",&n);
    assert((n==1)&&(n==0));
    if (n==1)
    {
        d->extrG->suivant=p;
        d->extrG=p;
    }
    else
    {
        d->extrD->suivant=p;
        d->extrD=p;
    }
}

void dedequer(struct deque *d)
{
    struct element *p,*q;
    p= (struct element *) malloc(sizeof(struct element);
    q= (struct element *) malloc(sizeof(struct element);
    q->suivant=d->extrD;
    assert(!deque_vide(f));
    int n;
    //si n=1 ==> extremité gauche sinon extremité droite
    assert(!deque_vide(f));
    printf("Choisir l'extremité ou on va supprimer (1==>gauche && 0==>droite");
    scanf("%d",&n);
    assert((n==1)&&(n==0));
    if (n==1)
    {
        p=d->extrG;
        d->extrG = d->extrG->suivant
    }
    else
    {
        p=d->extrD;
        d->extrD = q;
    }
    free(p);
    if (d->extrD == NULL)
        d->extrG = NULL; // cas où la deque contenait 1 seul élément
}