#include <stdio.h>

int total_vertex, total_edge, graph[15][15], visited_array[15], stack[15], top = -1;

void create_graph()
{
    int u, v;

    // initializing with zero
    for (int i = 0; i <= total_vertex; i++)
    {
        for (int j = 0; j <= total_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    // initializing edge with one
    for (int i = 0; i < total_edge; i++)
    {
        printf("\nEnter Directed Edge in U-->V manner : \n");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }
}

void print_graph()
{
    printf("\nAdjacency matrix is : \n\n");
    for (int i = 0; i <= total_vertex; i++)
    {
        for (int j = 0; j <= total_vertex; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void visited()
{
    for (int i = 0; i <= total_vertex; i++)
    {
        visited_array[i] = 0;
    }
}

void stack_push(int data)
{
    if(top < total_vertex - 1)
    {
        top++;
        stack[top] = data;
    }
}

void stack_display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

void DFS(int vertex)
{
    visited_array[vertex] = 1;
    // printf("\t%d --> ", vertex);
    for (int j = 0; j <= total_vertex; j++)
    {
        if (graph[vertex][j] == 1 && visited_array[j] == 0)
        {
            DFS(j);
        }
    }

    stack_push(vertex);
}

void Topological_Sort()
{
    printf("\nTopological sorting order is : \n");
    for (int i = 0; i <= total_vertex; i++)
    {
        if(visited_array[i] == 0)
        {
            DFS(i);
        }
    }

    stack_display();
}

int main()
{
    printf("\nEnter the total no : of vertices in the graph : \n");
    scanf("%d", &total_vertex);
    printf("\nEnter the total no : of edges in the graph : \n");
    scanf("%d", &total_edge);

    create_graph();
    print_graph();

    visited();

    Topological_Sort();

    return 0;
}