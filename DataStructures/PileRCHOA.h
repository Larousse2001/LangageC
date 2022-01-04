/* Prototypes des fonctions */
/* Operation de creation */
struct element *creer_pile(void);

/* Operation de consultation */
unsigned vide(void); //1 si la pile est vide sinon 0
int dernier(void);
int nb_element(void);

/* Operation de modification */
void empiler(int);
void depiler(void);
void effacer(void);
void change_sommet(int);