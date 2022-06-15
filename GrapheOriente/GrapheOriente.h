/****************************************************************************/
/*                    AUTEUR: Mohamed Ali HADJ TAIEB                        */
/*                    Date: Janvier 2020                                    */
/*                    Email: mohamedali.hadjtaieb@gmail.com                 */
/****************************************************************************/ 


struct element
{
	int key;
	struct element* next;
};

struct lists_adj
{
	struct element **list;
	char** label;
	int nbrNodes;
};


struct lists_adj createOrientedGraph(int nbrNodes);
void addEdge(struct lists_adj l, int ni, int nj);
void addEdgeByLabel(struct lists_adj l, char* labelnode1, char* labelnode2);
void printGraph(struct lists_adj l);
void getRoots(struct lists_adj l,int * R, int* nbrR );
void getRootsByLabels(struct lists_adj l,char** R, int* n );
int outDegree(struct lists_adj l,int n);
int inDegree(struct lists_adj l,int n);
struct lists_adj copyGraph(struct lists_adj l);
int isEdge(struct lists_adj l,int ni,int nj);
void deleteEdge(struct lists_adj l,int ni,int nj);
void affectLabels(struct lists_adj *l, char** labels);
void printLabels(struct lists_adj l);
void deleteNodeByLabel(struct lists_adj *l, char* labelNode);
void getInNodesByLabel(struct lists_adj l,char* nodeLabel, int *inNodes, int* nbrNodes);
void getOutNodesByLabel(struct lists_adj l,char* nodeLabel,int *outNodes, int* nbrNodes);