#include<assert.h>
#include "FileROTDA.h"


/* représentation contigüe */
#define n 100
struct file
{	int cle[n] ;
	unsigned tete;
	unsigned queue;
};
static struct file f;

void creer_file()
{	
    f.tete=0 ;
    f.queue=0 ;
}
//Remarque : n’importe quel indice compris entre 0 et n-1 pourrai  être considéré

unsigned file vide()
{
    return(f.tete == f.queue); 
}

int premier()
{	
    unsigned i;
  	assert(!file vide());
  	i=f.tete+1 ;
    if(i>n-1)
      	i=0;
   	return(f.cle[i]);
}

void enfiler(int info)
{
  	f.queue++;
    if(f.queue > n-1)
   	f.queue=0;
    assert(f.tete!=f.queue) ;
    /* f.tete==f.queue correspond  ici à une file pleine */
   	f.cle[f.queue]=info ;
}
 
void defiler()
{
   	assert(!file vide());
    f.tete++ ;
    if(f.tete>n-1)
    f.tete=0 ;
}