#include <stdio.h>
#include <stdbool.h>

#define V 5  // 定义顶点数

// 递归实现DFS
void DFS(int graph[V][V], int v, bool visited[]) {
    // 标记当前节点为已访问
    visited[v] = true;
    printf("%d ", v);

    // 对当前节点的所有邻接节点进行递归DFS
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
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

    bool visited[V] = {false};  // 初始化所有节点为未访问

    printf("深度优先搜索 (从节点 0 开始): \n");
    DFS(graph, 0, visited);

    return 0;
}
