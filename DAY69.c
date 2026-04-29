#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100   // max vertices

// Adjacency list node
struct Node {
    int dest, weight;
    struct Node* next;
};

// Graph
struct Graph {
    int vertices;
    struct Node* adj[V];
};

// Min Heap Node
struct HeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode heap[V];
};

// Create new node
struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// Swap heap nodes
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->heap[left].dist < heap->heap[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->heap[right].dist < heap->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->heap[i], &heap->heap[smallest]);
        heapify(heap, smallest);
    }
}

// Extract min
struct HeapNode extractMin(struct MinHeap* heap) {
    struct HeapNode root = heap->heap[0];
    heap->heap[0] = heap->heap[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

// Decrease key
void decreaseKey(struct MinHeap* heap, int v, int dist) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->heap[i].vertex == v) {
            heap->heap[i].dist = dist;

            while (i && heap->heap[(i - 1)/2].dist > heap->heap[i].dist) {
                swap(&heap->heap[i], &heap->heap[(i - 1)/2]);
                i = (i - 1)/2;
            }
            break;
        }
    }
}

// Dijkstra
void dijkstra(struct Graph* graph, int src) {
    int dist[V];

    struct MinHeap heap;
    heap.size = graph->vertices;

    // Initialize
    for (int i = 0; i < graph->vertices; i++) {
        dist[i] = INT_MAX;
        heap.heap[i].vertex = i;
        heap.heap[i].dist = INT_MAX;
    }

    dist[src] = 0;
    heap.heap[src].dist = 0;

    // Build heap
    for (int i = heap.size/2 - 1; i >= 0; i--)
        heapify(&heap, i);

    while (heap.size > 0) {
        struct HeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->dest;

            if (dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < graph->vertices; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Driver
int main() {
    int vertices = 5;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 4, 3, 2);

    dijkstra(graph, 0);

    return 0;
}
