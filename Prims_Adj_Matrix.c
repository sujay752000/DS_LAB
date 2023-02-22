#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int total_vertex, total_edge, graph[15][15], key[15], mst[15], parent[15];

void create_graph()
{
    int u, v, weight;
    // initializing with zero
    for (int i = 0; i <= total_vertex; i++)
    {
        for (int j = 0; j <= total_vertex; j++)
        {
            graph[i][j] = 0;
        }
    }

    // initializing edge with one
    for (int i = 1; i <= total_edge; i++)
    {
        printf("\nEnter the edge weigth in U--V with weight eg U V Weight\n");
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
}

void display_graph()
{
    printf("\n\nAdjacency matrix is : \n\n");
    for (int i = 0; i <= total_vertex; i++)
    {
        for (int j = 0; j <= total_vertex; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void prims()
{
    int minimum_cost = 0;
    // setting default values for key[], mst[], parent[];
    for (int i = 0; i < total_vertex; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // starting vertex
    key[0] = 0;
    parent[0] = -1;

    // output will be spanning tree(i,e edges = N - 1)
    for (int i = 0; i <= total_vertex - 1; i++)
    {
        int min = INT_MAX, min_vertex;

        // Taking minimum and finding vertex
        for (int i = 0; i < total_vertex; i++)
        {
            if (key[i] < min && mst[i] == false)
            {
                min = key[i];
                min_vertex = i;
            }
        }
        mst[min_vertex] = true;

        // Finding adjacent vertex of min_vertex
        for (int i = 0; i < total_vertex; i++)
        {
            int adj_vertex, adj_weight;

            if(graph[min_vertex][i] != 0)
            {
                adj_vertex = i; 
                adj_weight = graph[min_vertex][i];

                if((mst[adj_vertex] == false) && (key[adj_vertex] > adj_weight))
                {
                    key[adj_vertex] = adj_weight;
                    parent[adj_vertex] = min_vertex;
                } 
            }
        } 
    }

    printf("\nkey is \n");
    for (int i = 0; i < total_vertex; i++)
    {
        printf("%d ", key[i]);
    }

    printf("\nMst is \n");
    for (int i = 0; i < total_vertex; i++)
    {
        printf("%d ", mst[i]);
    }
    

    printf("\n\nMinimum Cost Spanning tree is : \n\n");

    for (int i = 0; i < total_vertex; i++)
    {
        printf("%d - parent-> %d \n",i, parent[i]);
        minimum_cost = minimum_cost + (graph[i][parent[i]]);
    }

    printf("\n\nMinimum cost is : %d\n\n", minimum_cost);
    
}

int main()
{
    printf("\nEnter total no : of vertex in graph : ");
    scanf("%d", &total_vertex);
    printf("\nEnter total no : of edges in graph : ");
    scanf("%d", &total_edge);

    create_graph();
    display_graph();
    prims();

    return 0;
}
