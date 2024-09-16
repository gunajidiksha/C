#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Queue structure
struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

// Function prototypes for queue operations
void initializeQueue(struct Queue* q);
int isQueueEmpty(struct Queue* q);
int isQueueFull(struct Queue* q);
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);

// Graph representation using adjacency matrix
#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to perform Breadth-First Search
void bfs(int start, int vertices) {
    struct Queue queue;
    initializeQueue(&queue);

    visited[start] = 1;
    printf("Visited: %d\n", start);
    enqueue(&queue, start);

    while (!isQueueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);

        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("Visited: %d\n", i);
                enqueue(&queue, i);
            }
        }
    }
}

// Queue operation implementations
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(struct Queue* q) {
    return q->front == -1;
}

int isQueueFull(struct Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(struct Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isQueueEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int value = q->items[q->front];

    if (q->front == q->rear) {
        // Last element in the queue
        initializeQueue(q);
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }

    return value;
}

// Main function
int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited array
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input the edges of the graph
    printf("Enter the edges (format: vertex1 vertex2):\n");
    for (int i = 0; i < edges; i++) {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }

    // Perform BFS starting from vertex 0
    printf("Breadth-First Search starting from vertex 0:\n");
    bfs(0, vertices);

    return 0;
}
