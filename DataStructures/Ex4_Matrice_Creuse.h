#ifndef __LIST__H__
#define __LIST__H__

/*représentation physique*/
struct Matrix
{
	int rows;	   // number of rows
	int cols;	   // number of columns
	double **data; // a pointer to an array of n_rows pointers to rows
};

struct liste
{
    struct ETD *first;
};

/*Prototypes*/
void initialiser(struct liste *l);
void ajouter(struct liste *l,struct Matrix *m);
struct Matrix *creer_matrice(void);
void  ajouter_element(int,struct Matrix);
unsigned consulter_element(struct Matrix);
struct Matrix existe(int,struct Matrix);
void modifier_element(int struct Matrix);
struct Matrix afficher_matrice(void);
#endif