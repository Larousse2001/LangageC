#ifndef __LIST__H__
#define __LIST__H__

/*représentation physique*/
struct noeud
{
    int cle ;
	struct noeud *suivant ;
}
struct liste 
{	
    struct noeud *premier ;
}

/*Prototypes*/
struct liste  *creer_liste(void);
unsigned liste_vide(struct liste *ll);
/*insertion un élément référencé*/
void inserer(int info, struct noeud *p);
/*suppression un élément référencé*/
void supprimer(struct noeud *p);
struct noeud * chercher(int info, struct noeud*p);
void visiter(struct noeud*p,void(*oper)(struct noeud*));

#endif