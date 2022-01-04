#ifndef __GRAPH__H__
#define __GRAPH__H__

/* DÃ©finition d'un BoolÃ©en */
typedef enum
{
	false,
	true
} Bool;

/* DÃ©finition d'une liste de Noeuds (sommet) */
typedef struct NodeListElement
{
	int value;
	struct NodeListElement *next;
} NodeListElement, *NodeList;

/* DÃ©finition d'une liste d'ajdacence (tableau) */
typedef struct AdjencyListElement
{
	NodeListElement *begin;
} AdjencyListElement, *AdjencyList;

/* DÃ©finition d'un Graphe */
typedef struct GraphElement
{
	Bool is_oriented;
	int nb_vertices;
	AdjencyList tab_neighbours;
	FILE *graph_file;
} GraphElement, *Graph;

/* Prototypes */
Graph new_graph(int vertices, Bool is_oriented);
Bool is_empty_graph(Graph g);
NodeList add_node(int x);
void add_edge(Graph g, int src, int dest);
void print_graph(Graph g);
void display_graph(Graph g);
void erase_graph(Graph g);

#endif