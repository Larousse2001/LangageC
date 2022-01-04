/* représentation Chainée */
struct element
{
    int cle;
    struct element *suivant;
};
struct file
{
    struct element *tete;
    struct element *queue;
};

/*opération ou services exportés*/
struct file *creer_file () ;
unsigned file_vide ( struct file * ) ;
int premier (struct file * ) ;
void enfiler (int, struct file *) ;
void defiler (struct file *) ;