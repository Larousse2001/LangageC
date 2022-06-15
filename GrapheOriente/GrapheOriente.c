/****************************************************************************/
/*                    AUTEUR: Mohamed Ali HADJ TAIEB                        */
/*                    Date: Janvier 2020                                    */
/*                    Email: mohamedali.hadjtaieb@gmail.com                 */
/****************************************************************************/ 

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include "GrapheOriente.h"

//opération de création
struct lists_adj createOrientedGraph(int n)
{
	struct lists_adj l;
	int i;
	l.list=(struct element**)malloc(n*sizeof(struct element*));
	l.nbrNodes=n;
	for(i=0;i<n;i++)
		l.list[i]=NULL;
	return l;
}

void affectLabels(struct lists_adj *l, char** labels)
{
	int i;
	l->label=(char**)malloc(l->nbrNodes*sizeof(char*));
	//printf("<>>>>>>>>>>%x\n",l->label);
	for(i=0;i<l->nbrNodes;i++)
	{
		//printf("%d ==>%s\n",i,labels[i]);
		l->label[i]=(char*)malloc(sizeof(char)*(strlen(labels[i])+1));
		strcpy(l->label[i],labels[i]);
		//printf("===================>%s +++++++++++++++++%x\n",l->label[i],l->label[i]);
	}
}
void printLabels(struct lists_adj l)
{
	int i;
	for(i=0;i<l.nbrNodes;i++)
		printf("%s\n",l.label[i]);
		
}
struct lists_adj copyGraph(struct lists_adj l)
{
 struct lists_adj copy;
 struct element *q,*p,*r;
 int i;
 copy.list=(struct element**)malloc(l.nbrNodes*sizeof(struct element*));
 copy.label=(char**)malloc(l.nbrNodes*sizeof(char*));
 copy.nbrNodes=l.nbrNodes;
 for(i=0;i<l.nbrNodes;i++)
	{
		copy.label[i]=(char*)malloc(sizeof(char)*(strlen(l.label[i])+1));
		strcpy(copy.label[i],l.label[i]);
		//printf("liste %d ==> \t",i);
		q=NULL; r=NULL;
		p=l.list[i];
		if(p==NULL)
			copy.list[i]=NULL;		
		else
		{
			q=(struct element*)malloc(sizeof(struct element));
			q->key=p->key;
			copy.list[i]=q;
			p=p->next;
			while(p!=NULL)
			{
				r=(struct element*)malloc(sizeof(struct element));
				r->key=p->key;
				q->next=r;
				q=r;
				//printf("%d\t",p->key);
				p=p->next;
			}
			q->next=NULL;
		}
		//printf("\n");
	}
 return copy;
}

void deleteEdge(struct lists_adj l,int ni,int nj)
{
	struct element *p,*q,*r;
	p=l.list[ni];
	while(p && p->key<nj)
	{
		r=p;
		p=p->next;
	}
	if(p && p->key==nj) //p!=NULL
	{
		if(p->next)
		{
			q=p->next;
			*p=*q;
			free(q);
		}
		else
		{
			if(l.list[ni]==p)
				l.list[ni]=NULL;
			else
			{
				r->next=NULL;
				free(p);
			}
		}
	}
}

int getIndiceNode(struct lists_adj l, char* labelNode)
{
	int i=0;
	for(i=0;i<l.nbrNodes;i++)
		if(strcmp(labelNode,l.label[i])==0)
			return i;
	return -1;
}
void deleteNodeByLabel(struct lists_adj *l, char* labelNode)
{
	int i,key;
	struct element*p,*q;
	int indice=getIndiceNode(*l,labelNode);
	assert(indice!=-1);
	p=l->list[indice];
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	l->list[indice]=NULL;
	//printf("OOOOOOOOO\n\n\n");
	//printGraph(*l);
	//printf("ici0\n");
	for(i=indice+1;i<l->nbrNodes;i++)
	{
		l->list[i-1]=l->list[i];
		l->label[i-1]=l->label[i];
	}
	l->nbrNodes--;
	//printf("PPPPPPPP\n\n\n");
	//printGraph(*l);
	//printf("ici1\n");
	for(i=0;i<l->nbrNodes;i++)
	{
		//printf("\n\n\ni=%d\n",i);
		p=l->list[i];
		while(p)
		{
			key=p->key;
			//printf("Key=%d\n",key);
			if(key == indice)
			{
				//printf("i=%d et indice=%d\n",i,indice);
				deleteEdge(*l,i,indice);
				//printGraph(*l);
			}
			else if(key>indice)
			{
				p->key--;
			}
			p=p->next;
		}
	}
	//printf("ici2\n");
	/*for(i=indice+1;i<l->nbrNodes;i++)
	{
		l->label[i-1]=l->label[i];
	}*/
	//printf("ici3\n");
	if(l->nbrNodes==0)
		l->list=NULL;
}

void getInNodesByLabel(struct lists_adj l,char* nodeLabel, int *inNodes, int* nbrNodes)
{
	int i,j;
	struct element *p;
	int node=getIndiceNode(l,nodeLabel);
	assert(node!=-1);
	j=0;
	for(i=0;i<l.nbrNodes;i++)
	{
		if(i!=node)
		{
			p=l.list[i];
			while(p!=NULL)
			{
				if(p->key==node)
				{
					inNodes[j]=i;
					j++;
				}

				p=p->next;
			}
		}
	}
	*nbrNodes=j;
}

void getOutNodesByLabel(struct lists_adj l,char* nodeLabel,int *outNodes, int* nbrNodes)
{
	int i;
	struct element *p;
	int n=getIndiceNode(l,nodeLabel);
	assert(n!=-1);
	p=l.list[n];
	i=0;
	while(p!=NULL)
	{
		//printf("%s\t",l.label[p->key]);
		outNodes[i]=p->key;
		p=p->next;
		i++;
	}
	*nbrNodes=i;
}

int isEdge(struct lists_adj l,int ni,int nj)
{
	struct element *p;
	p=l.list[ni];
	while(p && p->key<nj)
	{
		p=p->next;
	}
	if(p && p->key==nj) //p!=NULL
		return 1;
	return 0;
}
//opération de modification
void addEdge(struct lists_adj l, int node1, int node2)
{
 
 struct element *p,*f;
  struct element *q;
  q=(struct element*)malloc(sizeof(struct element));
  q->key=node2;
  p=l.list[node1];
  
  while(p!=NULL && p->key<node2)// insérer ds l'ordre croissant
  {
	  f=p;
	  p=p->next;
  }
  if(p!=NULL)
  {
	  *q=*p;
	  p->key=node2;
	  p->next=q;
	  
  }
  else if(l.list[node1]!=NULL) /* ajout au queue d'une liste*/
  {
	f->next=q;
	q->next=NULL;
  }
  else /*ajout du premier élément ds une liste*/
  {
	  l.list[node1]=q;
	  q->next=NULL;
  }
}
void addEdgeByLabel(struct lists_adj l, char* labelnode1, char* labelnode2)
{
 
 struct element *p,*f;
  struct element *q;
  int node1=getIndiceNode(l,labelnode1);
  int node2=getIndiceNode(l,labelnode2);
  assert(node1!=-1 && node2!=-1);
  q=(struct element*)malloc(sizeof(struct element));
  q->key=node2;
  p=l.list[node1];
  
  while(p!=NULL && p->key<node2)// insérer ds l'ordre croissant
  {
	  f=p;
	  p=p->next;
  }
  if(p!=NULL)
  {
	  *q=*p;
	  p->key=node2;
	  p->next=q;
	  
  }
  else if(l.list[node1]!=NULL) /* ajout au queue d'une liste*/
  {
	f->next=q;
	q->next=NULL;
  }
  else /*ajout du premier élément ds une liste*/
  {
	  l.list[node1]=q;
	  q->next=NULL;
  }
}
/*opération de consultation*/
void printGraph(struct lists_adj l)
{
	int i;
	struct element *p;
	for(i=0;i<l.nbrNodes;i++)
	{
		//printf("xxxxxxxxxxxxx\n");
		printf("liste %s ==> \t",l.label[i]);
		//printf("yyyyyyyyyyyyyyyyy\n");
		p=l.list[i];
		while(p!=NULL)
		{
			printf("%s\t",l.label[p->key]);
			p=p->next;
		}
		printf("\n");
	}
}
/*opération de consultation*/
int outDegree(struct lists_adj l,int n)
{
		int degree;
		struct element *p;
		degree=0;
		p=l.list[n];
		while(p!=NULL)
		{		
			p=p->next;
			degree++;
		}
		return degree;
}
/*opération de consultation*/
int inDegree(struct lists_adj l,int n)
{
	int degree,i;
	struct element *p;

	degree=0;
	for(i=0;i<l.nbrNodes;i++)
	{
		
		p=l.list[i];
		while(p!=NULL)
		{
			if(p->key==n)
				degree++;
			p=p->next;
		}
	}


	return degree;
}

/*opération de consultation*/
void getRoots(struct lists_adj l,int * R, int* n )
{
	int i,j, *Roots;
	struct element *p;
	Roots=(int *) malloc(l.nbrNodes*sizeof(int));
	for(i=0;i<l.nbrNodes;i++)
		Roots[i]=0;

	for(i=0;i<l.nbrNodes;i++)
	{
		
		p=l.list[i];
		while(p!=NULL)
		{
			Roots[p->key]=1;
			p=p->next;
		}
	}
	j=0;
	for(i=0;i<l.nbrNodes;i++)
	{
		if(Roots[i]==0)
		{
			printf("iiiiiiiiiiiiiiiiiiiiiii=%d\n",i);
			R[j]=i;
			j++;
		}
	}
	*n=j;
}
void getRootsByLabels(struct lists_adj l,char** R, int* n )
{
	int i,j, *Roots;
	struct element *p;
	Roots=(int *) malloc(l.nbrNodes*sizeof(int));
	for(i=0;i<l.nbrNodes;i++)
		Roots[i]=0;

	for(i=0;i<l.nbrNodes;i++)
	{
		
		p=l.list[i];
		while(p!=NULL)
		{
			Roots[p->key]=1;
			p=p->next;
		}
	}
	j=0;
	for(i=0;i<l.nbrNodes;i++)
	{
		if(Roots[i]==0)
		{
			//printf("iiiiiiiiiiiiiiiiiiiiiii=%d\n",i);
			
			R[j]=(char*)malloc(sizeof(char)*(strlen(l.label[i])+1));
			strcpy(R[j],l.label[i]);
			j++;
		}
	}
	*n=j;
}