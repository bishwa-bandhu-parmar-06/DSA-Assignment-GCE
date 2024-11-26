#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Graph {
    int numVertices;
    int adjMatrix[MAX][MAX];
};

void initializeGraph(struct Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1; // for undirected graph
}

void bfs(struct Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfsUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited);
        }
    }
}

void dfs(struct Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    dfsUtil(graph, startVertex, visited);
    printf("\n");
}

int main() {
    struct Graph graph;
    initializeGraph(&graph, 4);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);

    printf("BFS Traversal starting from vertex 0:\n");
    bfs(&graph, 0);

    printf("DFS Traversal starting from vertex 0:\n");
    dfs(&graph, 0);

    return 0;
}
