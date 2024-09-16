#include <stdio.h>
#include <stdlib.h>

int n, i, j, visited[10], queue[10], front=-1, rear=-1;
int adj[10][10];

void bfs(int v)
{
    for(i=1; i<=n; i++)
        if(adj[v][i] && !visited[1])
            queue[++rear]=i;
    if(front <= rear)
    {
        visited[queue[front]] =1;
        bfs(queue[front++]);
    }
}

int main()
{
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix \n");
    for(i=1 ; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter the starting vertex... ");
    scanf("%d",&v);

    for(i=1; i<=n; i++)
    {
        queue[i]=0;
        visited[i]=0;
    }
    bfs(v);

    printf("The nodes which are reachable are : \n");
    for(i=1; i<=n; i++)
        if(visited[i])
            printf("%d\t", i);
        else
            printf("\nNode %d is not reachable ", i);
    return 0;
}
