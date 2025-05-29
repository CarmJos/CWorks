#include <stdio.h>
#include <stdbool.h>

#define V 5  // 定义顶点数

// 定义一个队列结构
typedef struct {
    int items[V];
    int front;
    int rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// 判断队列是否为空
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// 入队操作
void enqueue(Queue* q, const int value) {
    if (q->rear == V - 1)
        return; // 队列已满
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// 出队操作
int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        return -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// 广度优先搜索
void BFS(int graph[V][V], const int startVertex) {
    Queue q;
    initQueue(&q);

    bool visited[V] = {false};

    visited[startVertex] = true;
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    // 定义一个图的邻接矩阵
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    printf("广度优先搜索 (从节点 0 开始): \n");
    BFS(graph, 0);

    return 0;
}
