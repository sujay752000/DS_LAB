#include <stdio.h>

int graph[15][15], visted_array[15], total_vertex, total_edge;

void create_graph()
{
    int u, v;

    // initializing with zero's
    for (int i = 0; i <= total_vertex; i++)
    {
        for (int j = 0; j <= total_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    // initializing edges with one's
    for (int i = 1; i <= total_edge; i++)
    {
        printf("\nEnter your edges in\tU --to-> V\tmanner : \n");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void print_graph()
{
    // printing graph

    printf("\nYour adjacency Matrix is : \n");
    for (int i = 0; i <= total_vertex; i++)
    {
        for (int j = 0; j <= total_vertex; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void visted()
{
    // setting all nodes in visted array as zero

    for (int i = 0; i <= total_vertex; i++)
    {
        visted_array[i] = 0;
    }
}

void DFS(int vertex)
{
    printf("\t%d-->", vertex);
    visted_array[vertex] = 1;
    for (int j = 0; j <= total_vertex; j++)
    {
        if (graph[vertex][j] == 1 && visted_array[j] == 0)
        {
            DFS(j);
        }
    }
}

int main()
{
    printf("\nEnter total no : of vertices in graph\n");
    scanf("%d", &total_vertex);
    printf("\nEnter total no : of edges in graph\n");
    scanf("%d", &total_edge);

    create_graph();
    print_graph();

    printf("\n\tDFS of entered graph is : \t\n");
    int source;
    printf("\tEnter the source vertex to find the DFS of graph : ");
    scanf("%d", &source);
    DFS(source);

    return 0;
}