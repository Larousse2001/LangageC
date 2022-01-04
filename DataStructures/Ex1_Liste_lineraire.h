#ifndef __LIST__H__
#define __LIST__H__

/*représentation physique*/
struct noeud
{
    int cle ;
	struct noeud* suivant ;
	struct noeud* precedent ;
}
struct liste 
{	
    struct noeud *premier ;
	struct noeud  *dernier ;
}

/*Prototypes*/
struct liste  *creer_liste(void);
unsigned liste_vide(struct liste *ll);
/*insertion après dernier*/
void inserer_apres_der(int info, struct liste *ll);
/*insertion avant premier*/
void inserer_avant_pre(int info, struct liste *ll);
/*insertion après élément référencé*/
void inserer_apres(int info, struct noeud *p);
/*insertion avant un élément référencé*/
void inserer_avant(int info, struct noeud *p);
/*suppression un élément référencé*/
void supprimer(struct noeud *p);
/*suppression du premier*/
void supprimer_pre(struct liste *ll);
/*suppression du dernier*/
void supprimer_der(struct liste *ll);
struct noeud * chercher(int info, struct noeud*p);
void visiter(struct noeud*p,void(*oper)(struct noeud*));
int liste_longueur(struct noeud *p);
void trier(struct noeud *p);

#endif