/* représentation contigüe */
#define n 100
struct file
{	int cle[n] ;
	unsigned tete;
	unsigned queue;
};

/*opération ou services exportés*/
void creer_file(struct file*) ;
	/* struct file* creer_file(void) ;*/
unsigned file_vide(struct file) ; 
	/* unsigned file_vide(struct file *) ; */
int premier(struct file); 
	/* int premier(struct file *);*/
void enfiler(int, struct file*);
void defiler(struct file*);