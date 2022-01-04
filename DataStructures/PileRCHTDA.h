/* DÃ©finition d'une Pile */

struct element
{
    int cle;
    struct element *suivant;
};

/* Prototypes des fonctions */
/* Operation de creation */
struct element *creer_pile(void);

/* Operation de consultation */
unsigned vide(struct element*); //1 si la pile est vide sinon 0
int dernier(struct element*);

/* Operation de modification */
void empiler(int,struct element**);
void depiler(struct element**);