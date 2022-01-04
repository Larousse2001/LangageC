#include<assert.h>
#include "FileROTDA.h"

void creer_file(struct file*f)
{	
    f->tete=0 ;
    f->queue=0 ;
}
//Remarque : n’importe quel indice compris entre 0 et n-1 pourrai  être considéré

unsigned file vide(struct file f)
{
    return(f.tete == f.queue); 
}

int premier(struct file f)
{	
    unsigned i;
  	assert(!file vide(f));
  	i=f.tete+1 ;
    if(i>n-1)
      	i=0;
   	return(f.cle[i]);
}

void enfiler(int info,struct file*f)
{
  	f->queue++;
    if(f->queue>n-1)
   	f->queue=0;
    assert(f->tete!=f->queue) ;
    /* f->tete==f->queue correspond  ici à une file pleine */
   	f->cle[f->queue]=info ;
}
 
void defiler(struct file *f)
{
   	assert(!file vide(*f));
    f->tete++ ;
    if(f->tete>n-1)
    f->tete=0 ;
}