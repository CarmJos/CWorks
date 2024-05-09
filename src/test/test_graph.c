#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 8  // 最大顶点数8

// 定义边结构
typedef struct edge {
    int src, dest, weight;       // 定义边的起点，终点，权重
} Edge;

// 定义图结构
typedef struct graph {
    int numVertices, numEdges; // 图中顶点的数量
    Edge *edges; // 边的数组
} Graph;

// 定义链表节点
typedef struct node {
    int vertex;
    struct node *next;
} Node;

// 创建一个具有指定顶点数的图
Graph *createGraph(int numVertices) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));                    // 分配图结构的内存空间
    graph->numVertices = numVertices;                                                     // 设置图中顶点的数量
    graph->edges = (Edge *) malloc(numVertices * numVertices * sizeof(Edge)); // 分配边数组的内存空间
    return graph;
}

// 创建一个新的链表节点
Node *createNode(int v) {
    Node *newNode = (Node *) malloc(sizeof(Node));                     // 分配链表节点的内存空间
    newNode->vertex = v;                                                                  // 设置链表节点的顶点值
    newNode->next = NULL;
    return newNode;
}

// 向图中添加一条边
void addEdge(Graph *graph, int src, int dest, int weight) {
    // 将边的起点终点和权重存储在对应位置
    graph->edges[src * graph->numVertices + dest].src = src;
    graph->edges[src * graph->numVertices + dest].dest = dest;
    graph->edges[src * graph->numVertices + dest].weight = weight;
}

// 打印最小生成树
void printMST(Edge *result, int numEdges) {
    int totalWeight = 0;    // 初始化权重=0
    printf("最小生成树:\n");
    // 打印每条边的起点终点和权重
    for (int i = 0; i < numEdges; i++) {
        printf("%c - %c : %d\n", result[i].src + 'A', result[i].dest + 'A', result[i].weight);
        totalWeight += result[i].weight; // 更新新的权重
    }
    printf("总权重: %d\n", totalWeight);
}

// 查找父节点，每选择一条边若形成一个cycle则舍弃该边
int find(int parent[], int i) {
    if (i >= 0 && i < MAX_VERTICES) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);  // 递归查找根节点,判断边是否在同一颗树中
    }
    return -1; // 返回-1表示未找到
}

// 合并集合
void Union(int parent[], int x, int y) {
    parent[x] = y;  // 将x的父节点设置为y，即将x所在集合合并到y所在集合
}

// 比较函数，用于qsort排序
int compare(const void *a, const void *b) {
    Edge *edge1 = (Edge *) a;
    Edge *edge2 = (Edge *) b;  // 将a，b转换为edge型指针
    return edge1->weight - edge2->weight;  // 按权重值排序，形成weight表
}

//读文件
void readFile(Graph *graph, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("无法打开文件\n");
        return;
    }
    fscanf(file, "%d %d", &graph->numVertices, &graph->numEdges);
    for (int i = 0; i < graph->numEdges; ++i) {
        int src, dest, weight;
        fscanf(file, "%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }
    fclose(file);
}

// Kruskal算法实现
void kruskalMST(Graph *graph) {
    int numVertices = graph->numVertices;  // 获取图中顶点的数量
    Edge result[numVertices];       // 存储最小生成树的边
    int e = 0; // 初始化边的索引为0
    int i = 0;

    qsort(graph->edges, numVertices * numVertices, sizeof(graph->edges[0]), compare); // 调用compare函数对边按权重进行排序

    int parent[numVertices];    // 存储每个顶点的父节点
    for (int v = 0; v < numVertices; v++)
        parent[v] = -1;         // 初始化每个顶点的父节点为-1，表示各自独立成集合,即顶点间未连接

    while (e < numVertices - 1 && i < numVertices * numVertices) {
        Edge next_edge = graph->edges[i++];   // 获取下一条边

        int x = find(parent, next_edge.src);         // 查找起点的父节点
        int y = find(parent, next_edge.dest);        // 查找终点的父节点

        if (x != y) {                                // 如果起点和终点不在一个集合中,即没有形成一个圈
            result[e++] = next_edge;                 // 就将边添加进入最小生成树中
            Union(parent, x, y);                     // 合并起点和终点所在集合在一颗树中
        }
    }

    printMST(result, e);
}

// Prim 算法
void PrimMST(Graph *graph) {
    bool visited[MAX_VERTICES] = {false};
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];

    // 初始化 parent 数组和 key 数组
    for (int i = 0; i < graph->numVertices; ++i) {
        parent[i] = -1;
        key[i] = INT_MAX;
    }

    // 选择第一个顶点作为起始顶点
    key[0] = 0;
    parent[0] = -1;

    // 找到最小生成树的边
    for (int count = 0; count < graph->numVertices - 1; ++count) {
        // 选取 key 值最小的顶点
        int minKey = INT_MAX, minIndex = -1;
        for (int v = 0; v < graph->numVertices; ++v) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // 将选取的顶点标记为已访问
        visited[minIndex] = true;

        // 更新与选取的顶点相邻的顶点的 key 值和 parent 数组
        for (int i = 0; i < graph->numEdges; ++i) {
            Edge *edge = &graph->edges[i];
            if (edge->src == minIndex && !visited[edge->dest] && edge->weight < key[edge->dest]) {
                parent[edge->dest] = minIndex;
                key[edge->dest] = edge->weight;
            } else if (edge->dest == minIndex && !visited[edge->src] && edge->weight < key[edge->src]) {
                parent[edge->src] = minIndex;
                key[edge->src] = edge->weight;
            }
        }
    }

    // 输出最小生成树的边和权值
    printf("最小生成树\n");
    for (int i = 1; i < graph->numVertices; ++i) {
        printf("%c - %c \t %d\n", 'A' + parent[i], 'A' + i, key[i]);
    }
}


int main() {
    Graph *graph = createGraph(MAX_VERTICES);
    readFile(graph, "graph.txt");

    printf("使用Kruskal算法:\n");
    kruskalMST(graph);

    printf("使用Prim算法:\n");
    PrimMST(graph);

    printf("\n");

    return 0;
}