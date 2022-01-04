/* DÃ©finition d'une Pile */
#define N1 100
struct pile
{
    int cle[N];
    int sommet;
};

/* Prototypes des fonctions */
/* Operation de creation */
struct element *creer_pile(struct pile*);

/* Operation de consultation */
unsigned vide(struct pile);
int dernier(struct pile);

/* Operation de modification */
void empiler(int,struct pile*);
void depiler(struct pile*);