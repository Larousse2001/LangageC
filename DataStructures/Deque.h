/* représentation Chainée */
struct element
{
    int cle;
    struct element *suivant;
};
struct deque
{
    struct element *extrG;
    struct element *extrD;
};

/*opération ou services exportés*/
struct deque *creer_deque () ;
unsigned deque_vide ( struct deque * ) ;
int extremite (struct deque * ) ;
void endequer (int, struct deque *) ;
void dedequer (struct deque *) ;