#include <stdio.h>
#include <stdlib.h>
#include "Ex5_Graphe.h"

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

Graph new_graph(int vertices, Bool is_oriented)
{
	int i;
	GraphElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : Probleme creation Graphe.\n");
		exit(EXIT_FAILURE);
	}

	element->is_oriented = is_oriented;
	element->nb_vertices = vertices;

	element->tab_neighbours = malloc(vertices * sizeof(AdjencyListElement));

	if(element->tab_neighbours == NULL)
	{
		fprintf(stderr, "Erreur : Probleme creation Graphe.\n");
		exit(EXIT_FAILURE);
	}

	for(i = 1 ; i < element->nb_vertices + 1 ; i++)
		element->tab_neighbours[i-1].begin = NULL;

	if(element->is_oriented)
		element->graph_file = fopen("digraph.out", "w");
	else
		element->graph_file = fopen("graph.out", "w");

	if(element->graph_file == NULL)
	{
		fprintf(stderr, "Erreur : Probleme creation du fichier.\n");
		exit(EXIT_FAILURE);
	}

	if(element->is_oriented)
		fprintf(element->graph_file, "digraph my_graph\n{\n");
	else
		fprintf(element->graph_file, "graph my_graph\n{\n");

	return element;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

Bool is_empty_graph(Graph g)
{
	if(g == NULL)
		return true;

	return false;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

NodeList add_node(int x)
{
	NodeList n = malloc(sizeof(NodeListElement));

	if(n == NULL)
	{
		fprintf(stderr, "Erreur : Probleme creation Node.\n");
		exit(EXIT_FAILURE);
	}

	n->value = x;
	n->next = NULL;

	return n;
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void add_edge(Graph g, int src, int dest)
{
	NodeList n = add_node(dest);
	n->next = g->tab_neighbours[src-1].begin;
	g->tab_neighbours[src-1].begin = n;

	if(!g->is_oriented)
	{
		n = add_node(src);
		n->next = g->tab_neighbours[dest-1].begin;
		g->tab_neighbours[dest-1].begin = n;
	}

	//Ajout d'un lien dans le fichier Graphviz
	if(g->is_oriented)
		fprintf(g->graph_file, "\t%d -> %d;\n", src, dest);
	else
		fprintf(g->graph_file, "\t%d -- %d;\n", src, dest);
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void print_graph(Graph g)
{
	int i;

	for(i = 1 ; i < g->nb_vertices + 1 ; i++)
	{
		NodeList n = g->tab_neighbours[i-1].begin;
		printf("(%d) : ", i);

		while(n != NULL)
		{
			printf("%d, ", n->value);
			n = n->next;
		}

		printf("NULL\n");
	}
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void display_graph(Graph g)
{
	//Windows seulement !
	if(g->is_oriented)
		system("%CD%/graphviz/bin/dotty.exe digraph.out");
	else
		system("%CD%/graphviz/bin/dotty.exe graph.out");
}

/*++++++++++++++++++++++++++++++++++-----------+++++++++++++++++++++++++++++++++++++++*/

void erase_graph(Graph g)
{
	if(is_empty_graph(g))
	{
		printf("Rien a effacer, le Graphe n'existe pas.\n");
		return;
	}

	//Si il existe des sommets adjacents
	if(g->tab_neighbours)
	{
		int i;

		for(i = 1 ; i < g->nb_vertices + 1 ; i++)
		{
			NodeList n = g->tab_neighbours[i-1].begin;
			
			while(n != NULL)
			{
				NodeList tmp = n;
				n = n->next;
				free(tmp);
			}
		}

		//LibÃ©ration de la liste d'adjacence
		free(g->tab_neighbours);
	}

	//Fin et fermeture du fichier Graphviz
	fprintf(g->graph_file, "}\n");
	fclose(g->graph_file);

	//LibÃ©ration du Graphe de la mÃ©moire
	free(g);
}