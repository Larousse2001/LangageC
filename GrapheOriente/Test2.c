/****************************************************************************/
/*                    AUTEUR: Mohamed Ali HADJ TAIEB                        */
/*                    Date: Janvier 2020                                    */
/*                    Email: mohamedali.hadjtaieb@gmail.com                 */
/****************************************************************************/ 


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "GrapheOriente.h"
/*void main()
{
	int noeuds;
	int i,l,inNodes[8],outNodes[8],nbr;
	struct lists_adj G1, G3;
	char **labels,ch[20],labelNode[20];
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
	printf("Label node: ");
	scanf("%s",labelNode);
	getInNodesByLabel(G1,labelNode,inNodes,&nbr);
	for(i=0;i<nbr;i++)
	{
		printf("%s\n",G1.label[inNodes[i]]);
	}
	printf("Label node: ");
	scanf("%s",labelNode);
	getOutNodesByLabel(G1,labelNode,outNodes,&nbr);
	for(i=0;i<nbr;i++)
	{
		printf("%s\n",G1.label[outNodes[i]]);
	}
}*/