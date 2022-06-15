/****************************************************************************/
/*                    AUTEUR: Mohamed Ali HADJ TAIEB                        */
/*                    Date: Janvier 2020                                    */
/*                    Email: mohamedali.hadjtaieb@gmail.com                 */
/****************************************************************************/ 


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "GrapheOriente.h"
void main()
{
	int noeuds;
	int i,l,nR;
	struct lists_adj G1, G3;
	char **labels,ch[20],*R[8];
	noeuds=8;
	G1=createOrientedGraph(noeuds);
	labels=(char**)malloc (noeuds*sizeof(char*));
	for(i=0;i<noeuds;i++)
	{
		printf("label[%d]=",i);
		scanf("%s",ch);
		labels[i]=(char*)malloc(sizeof(char)*(strlen(ch)+1));
		strcpy(labels[i],ch);

	}
	
	affectLabels(&G1,labels);
	printf("Affichage Labels\n\n");
	printLabels(G1);
	printf("creation avec succes\n");

	addEdge(G1,0,1);
	addEdge(G1,0,2);
	addEdge(G1,2,4);
	addEdge(G1,3,4);
	addEdge(G1,3,7);
	addEdge(G1,4,0);
	addEdge(G1,5,3);
	addEdge(G1,6,4);
	addEdge(G1,7,0);
	printf("arc ajoute\n");
	printf("\n\nAffichage\n");
	printGraph(G1);
	printf("\n\n\nCopie*****\n\n");
	G3=copyGraph(G1);
	printGraph(G3);

	/////Tri Topologique
	printf("Tri Topologique \n\n");
	l=-1;
	getRootsByLabels(G3,R, &nR );
	while(G3.nbrNodes!=0 && nR!=0)
	{
		l++;
			printf("Layer %d\n",l);
			for(i=0;i<nR;i++)
			{	
				printf("%s\n",R[i]);
				deleteNodeByLabel(&G3,R[i]);
			}
			getRootsByLabels(G3,R, &nR );
	}
	if(G3.nbrNodes!=0)
			printf("Erreur: Graphe oriente cyclique\n");

    //Suppression de l'arc pour avoir un graphe oriente acyclique
	G3=copyGraph(G1);
	deleteEdge(G3,4,0);
	//deleteNodeByLabel(&G3,"4");
	//printf("Arc supprime\n");
	/////Tri Topologique
	printf("Tri Topologique \n\n");
	l=-1;
	getRootsByLabels(G3,R, &nR );
	while(G3.nbrNodes!=0 && nR!=0)
	{
		l++;
			printf("Layer %d\n",l);
			for(i=0;i<nR;i++)
			{	
				printf("%s\n",R[i]);
				deleteNodeByLabel(&G3,R[i]);
			}
			getRootsByLabels(G3,R, &nR );
	}
	if(G3.nbrNodes!=0)
			printf("Erreur: Graphe oriente cyclique\n");
}