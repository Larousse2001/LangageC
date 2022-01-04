#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste_circulaire.h"

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

struct liste  *creer_liste(void)
{   	
    struct liste *ll ;
    ll=(struct liste*) malloc (size of(struct liste)) ;
    ll->premier=NULL;
    return ll;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

unsigned liste_vide(struct liste *ll)
{
 	return((ll->premier==NULL);
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

/*insertion un élément référencé*/
void inserer(int info, struct noeud *p)
{
    struct noeud *q ;
    q = (struct noeud *)malloc(size of(struct noeud)) ;
    q->cle = info;
    q->suivant = p->suivant ;
      /*mise à jour du successeur de p*/
    p->suivant = q ;
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