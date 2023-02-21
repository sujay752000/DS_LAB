#include <stdio.h>

int total_vertex, total_edge, graph[15][15], visited_array[15], queue[15], front = -1, rear = -1;

void create_graph()
{
    int u, v;

    // initializing with 0
    for (int i = 0; i <= total_vertex; i++)
    {
        for (int j = 0; j <= total_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    // initializing edge with 1
    for (int i = 0; i < total_edge; i++)
    {
        printf("\nEnter edges in U-->V manner : \n");
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void print_graph()
{
    printf("\nAdajacency Matrix is : \n");

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

void enqueue(int data)
{
    if(front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data; 
    }
}

int dequeue()
{
    int dequeued_value;

    if(front == rear)
    {
        dequeued_value = queue[front];
        front = rear = -1;
        return dequeued_value;
    }
    else
    {
        dequeued_value = queue[front];
        front++;
        return dequeued_value;
    }
}

void BFS(int source)
{
    int vertex;

    printf("%d --> ", source);
    visited_array[source] = 1;
    enqueue(source);

    while(front != -1)
    {
        vertex = dequeue();
        for(int j = 0; j <= total_vertex; j++)
        {
            if(graph[vertex][j] == 1 && visited_array[j] == 0)
            {
                printf("%d --> ", j);
                visited_array[j] = 1;
                enqueue(j);
            }
        }
    }

}

int main()
{
    int source;
    printf("\nEnter the total no : of vertices in the graph \n");
    scanf("%d", &total_vertex);
    printf("\nEnter the total no : of edges in the graph \n");
    scanf("%d", &total_edge);

    create_graph();
    print_graph();
    visited();

    printf("\nEnter the source vertex for BFS traversal : ");
    scanf("%d", &source);

    printf("\nBFS traversal is : ");
    BFS(source);
    return 0;
}