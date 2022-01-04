#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste_lineraire.h"

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct liste  *creer_liste(void)
{   	
    struct liste *ll ;
    ll=(struct liste*) malloc (size of(struct liste)) ;
    ll->premier=NULL;
    ll->dernier=NULL;
    return ll;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

unsigned liste_vide(struct liste *ll)
{
 	return((ll->premier==NULL) && (ll->dernier==NULL));
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*insertion après dernier*/
void inserer_apres_der(int info, struct liste *ll)
{
	struct noeud *q;
	assert(ll!=NULL);
	q=(struct noeud*)malloc(sizeof(struct noeud));
	assert(q!=NULL);
	q->cle=info;
	q->precedent=ll->dernier;
	q->suivant=ll->premier;
	ll->dernier=q;;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*insertion avant premier*/
void inserer_avant_pre(int info, struct liste *ll)
{
	struct noeud *q;
	assert(ll!=NULL);
	q=(struct noeud*)malloc(sizeof(struct noeud));
	assert(q!=NULL);
	q->cle=info;
	q->suivant=ll->premier;
	q->precedent=ll->dernier;
	ll->premier=q;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*insertion après élément référencé*/
void inserer_apres(int info, struct noeud *p)
{
    struct noeud *q ;
    q = (struct noeud *)malloc(size of(struct noeud)) ;
    q->cle = info;
    q->suivant = p->suivant ;
      /*mise à jour du successeur de p*/
    p->suivant = q ;
      /*mise à jour du precedeur de p*/
	q->precedent = p;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*insertion avant un élément référencé*/
void inserer_avant(int info, struct noeud *p)
{ 
    struct noeud *q ;
    q = (struct noeud *)malloc(size of(struct noeud)) ;
    q->cle = info;
    q->precedent = p->precedent ;
      /*mise à jour du precedeur de p*/
    p->precedent = q ;
      /*mise à jour du successeur de p*/
    q->suivant = p ;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*suppression du premier*/
void supprimer_pre(struct liste *ll)
{
	return (ll->premier==NULL);
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*suppression du dernier*/
void supprimer_der(struct liste *ll)
{
	return(p->dernier==NULL);
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*suppression un élément référencé*/
void supprimer(struct noeud *p)
{
	if(p->suivant == NULL  && p->precedent == NULL)
	{
		free(p);
		p = NULL;

		return creer_liste();
	}

	struct noeud *temp = p;
	struct noeud *before = p;

	while(temp->suivant != NULL)
	{
		before = temp;
		temp = temp->next;
	}

	before->next = NULL;

	free(temp);
	temp = NULL;

	return p;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*suppression un élément référencé*/
void supprimer(struct noeud *p)
{
	if(p->next == NULL)
	{
		free(p);
		p = NULL;

		return creer_liste();
	}

	struct noeud *temp = p;
	struct noeud *before = p;

	while(temp->suivant != NULL)
	{
		before = temp;
		temp = temp->next;
	}

	before->next = NULL;

	free(temp);
	temp = NULL;

	return p;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct noeud * chercher(int info, struct noeud*p)
{
  	while(p&&(p->cle!=info))
    p=p->suivant ;
    //échec : !p => p== NULL
    //succès :p->cle==info*/
 	return(p) ;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void visiter(struct noeud*p,void(*oper)(struct noeud*))
{
	while(p)
	{
	/*appliquer à l’élément porté par p le traitement est fourni par oper*/
		(*oper)(p) ;
	/*passer à l’élément suivant */
		p=p->suivant ;
    }
    /*    Exemple:
    struct noeud * point_de_depart ;
    void afficher(struct nœud * q)
    {
    	printf (’’%u d\n ‘’, q->cle) ;
    }
    visiter(point_de_depart, afficher) ;
    void incrementer (struct nœud *q)
    {
     	q->cle++ ;
    }
    visiter(point_de_depart, incrementer) ;
    */
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

int liste_longueur(struct noeud *p)
{
	int l = 0;

	if(liste_vide(p))
		return size;

	while(p != NULL)
	{
		l++;
		p = p->suivant;
	}

	return l;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void trier(struct noeud *p)
{
    int tmp;
	while(p<p->suivant)
	{
        tmp=p;
        p=p->suivant;
        p->suivant=tmp;	
	}
}