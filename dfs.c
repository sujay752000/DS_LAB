#include <stdio.h>
#include <stdlib.h>

int noofvertex=5;

struct node
{
	int vertex;
	struct node *next;
};

struct Graph
{
	int no_vertex;
	int *visited;
	struct node **adj;
};

struct Graph *creategraph(int v)
{
	int i;
	struct Graph *g = malloc(sizeof(struct Graph));
	g->no_vertex = v;
	g->visited = malloc(v * sizeof(int));
	g->adj = malloc(v * sizeof(struct node *));

	for (i = 0; i < (g->no_vertex); i++)
	{
		g->visited[i] = 0;
		g->adj[i] = NULL;
	}
	return g;
}

struct node *createnode(int v)
{

	struct node *Node = (struct node *)malloc(sizeof(struct node));
	Node->vertex = v;
	Node->next = NULL;
	return Node;
}

void readgraph(struct Graph *g)
{
	int i, ad, j, data;
	for (i = 0; i < (g->no_vertex); i++)
	{
		struct node *temp = NULL;
		printf("\n Enter the number of adjacent vertex %d", i);
		scanf("%d", &ad);

		for (j = 0; j < ad; j++)
		{

			printf("Enter the value of %d adjacent to %d ", j, i);
			scanf("%d", &data);
			struct node *newnode = createnode(data);

			if (g->adj[i] == NULL)
			{
				g->adj[i] = newnode;
			}
			else
			{
				temp->next = newnode;
			}
			temp = newnode;
		}
	}
}

void printGraph(struct Graph *g)
{

	struct node *temp = NULL;

	for (int i = 0; i < (g->no_vertex); i++)
	{
		printf("\nAdjacent of %d are", i);

		temp = g->adj[i];

		while (temp!=NULL)
		{
			printf("\t%d\t",temp->vertex);
			temp=temp->next;
		}
	}
}

void dfs(struct Graph *g,int start)
{
    g->visited[start]=1;
    printf("%d->",start);
    struct node*ptr=g->adj[start];
    while(ptr!=NULL)
    {
        if(g->visited[ptr->vertex]==0)
        {
            dfs(g,ptr->vertex);
        }
        ptr=ptr->next;
    }

}

void main()
{
	printf("\n Enter the number of vertices ");
	scanf("%d",&noofvertex);
	struct Graph *g = creategraph(noofvertex);
	readgraph(g);
	printGraph(g);
	dfs(g, 0);
}
