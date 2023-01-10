
#include <stdio.h>
#include <stdlib.h>

int noofvertex = 5;
int top = -1;
int stack[5];

struct node
{
    int vertex;
    struct node *next;
};

struct adjlist
{
    struct node *head;
};

struct Graph
{
    int no_vertex;
    int *visited;
    struct adjlist *adj;
};

struct node *createnode(int v)
{
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->vertex = v;
    Node->next = NULL;
    return Node;
}

struct Graph *creategraph(int v)
{
    int i;
    struct Graph *g = malloc(sizeof(struct Graph));
    g->no_vertex = v;
    g->visited = malloc(v * sizeof(int));
    g->adj = (struct adjlist *)malloc(v * sizeof(struct adjlist *));

    for (i = 0; i < (g->no_vertex); i++)
    {
        g->visited[i] = 0;
        g->adj[i].head = NULL;
    }
    return g;
}

void addtranspose(struct Graph *g, int s, int d)
{
    struct node *newnode = createnode(s);
    newnode->next = g->adj[d].head;
    g->adj[d].head = newnode;
}

void add_edge(struct Graph *g, struct Graph *gt, int s, int d)
{
    struct node *newnode = createnode(d);
    newnode->next = g->adj[s].head;
    g->adj[s].head = newnode;
    addtranspose(gt, s, d);
}

void readgraph(struct Graph *g, struct Graph *gt)
{
    int i, ad, j, data;
    for (i = 0; i < (g->no_vertex); i++)
    {
        struct node *temp = NULL, *temp2 = NULL;
        printf("\n Enter the number of adjacent vertex %d", i);
        scanf("%d", &ad);

        for (j = 0; j < ad; j++)
        {
            printf("Enter the value of %d adjacent to %d ", j, i);
            scanf("%d", &data);
            add_edge(g, gt, i, data);
        }
    }
}

void printGraph(struct Graph *graph1)
{
    for (int v = 0; v < graph1->no_vertex; ++v)
    {
        struct node *temp = graph1->adj[v].head;
        while (temp)
        {
            printf("(%d -> %d)\t", v, temp->vertex);
            temp = temp->next;
        }
    }
}

void dfs(struct Graph *g, int start)
{
    g->visited[start] = 1;
    struct node *ptr = g->adj[start].head;
    while (ptr != NULL)
    {
        if (g->visited[ptr->vertex] == 0)
        {
            dfs(g, ptr->vertex);
        }
        ptr = ptr->next;
    }
    top++;
    stack[top] = start;
}

void firstdfs(struct Graph *g)
{
    for (int i = 0; i < g->no_vertex; i++)
    {
        if (g->visited[i] == 0)
        {
            dfs(g, i);
        }
    }
}

void dfs2(struct Graph *g, int start)
{
    g->visited[start] = 1;
    printf("%d->", start);
    struct node *ptr = g->adj[start].head;
    while (ptr != NULL)
    {
        if (g->visited[ptr->vertex] == 0)
        {
            dfs2(g, ptr->vertex);
        }
        ptr = ptr->next;
    }
}

void strongly(struct Graph *g)
{
    while (top != -1)
    {
        int s = stack[top];
        top--;
        if (g->visited[s] == 0)
        {
            printf("\n Component\t");
            dfs2(g, s);
        }
    }
}

void main()
{
    printf("\n Enter the number of vertices ");
    scanf("%d", &noofvertex);

    struct Graph *graph = creategraph(noofvertex);
    struct Graph *gr = creategraph(noofvertex);

    readgraph(graph, gr);

    printGraph(graph);

    printf("Transpose Graph\n");

    printGraph(gr);

    firstdfs(graph);

    printf("Strongly Connected Graph\n");

    strongly(gr);
}
