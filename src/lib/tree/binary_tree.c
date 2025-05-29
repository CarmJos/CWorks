// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2024. CarmJos
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <malloc.h>
#include <stdio.h>
#include "../queue/linked_queue.c"

typedef char ElementType;

typedef struct binary_tree_node {
    ElementType data;
    struct binary_tree_node *left, *right;
} BinaryTree;

BinaryTree *bt_create(ElementType data) {
    BinaryTree *node = (BinaryTree *) malloc(sizeof(BinaryTree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void bt_pre_order(BinaryTree *root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    bt_pre_order(root->left);
    bt_pre_order(root->right);
}

void bt_in_order(BinaryTree *root) {
    if (root == NULL) return;
    bt_in_order(root->left);
    printf("%c ", root->data);
    bt_in_order(root->right);
}

void bt_post_order(BinaryTree *root) {
    if (root == NULL) return;
    bt_post_order(root->left);
    bt_post_order(root->right);
    printf("%c ", root->data);
}

void bt_level_order(BinaryTree *root) {
    LinkedQueue *queue = lq_create();
    lq_enqueue(queue, root);
    while (queue->front->next != NULL) {
        BinaryTree *node = lq_dequeue(queue);
        printf("%c ", node->data);
        if (node->left != NULL) lq_enqueue(queue, node->left);
        if (node->right != NULL) lq_enqueue(queue, node->right);
    }
}

int bt_count_child(BinaryTree *tree) {
    return (tree->left != NULL) + (tree->right != NULL);
}

// 计算指定度数(即其拥有的子节点个数)的节点个数
// degree = -1 代表所有节点  degree = 0 代表叶子节点
// degree = 1 代表拥有一个子节点的节点
// degree = 2 代表拥有两个子节点的节点
int bt_count_node(BinaryTree *tree, int degree) {
    if (tree == NULL || degree < -1 || degree > 2) return 0;
    return (degree == -1 || bt_count_child(tree) == degree)
           + bt_count_node(tree->left, degree)
           + bt_count_node(tree->right, degree);
}

int bt_count_leaf(BinaryTree *tree) {
    return bt_count_node(tree, 0);
}


int main() {

    // ------------------------------------------------
    //       A
    //     /    \
    //    B      C    测试用例结构
    //   / \   /
    //  D   E F
    // ------------------------------------------------

    BinaryTree *tree = bt_create('A');

    BinaryTree *nodeB = bt_create('B');
    BinaryTree *nodeC = bt_create('C');
    BinaryTree *nodeD = bt_create('D');
    BinaryTree *nodeE = bt_create('E');
    BinaryTree *nodeF = bt_create('F');

    tree->left = nodeB;
    tree->right = nodeC;
    nodeB->left = nodeD;
    nodeB->right = nodeE;
    nodeC->left = nodeF;

    // ------------------------------------------------

    printf("Pre-order: ");
    bt_pre_order(tree); // A B D E C F

    printf("\nIn-order: ");
    bt_in_order(tree); // D B E A F C

    printf("\nPost-order: ");
    bt_post_order(tree); // D E B F C A

    printf("\nLevel-order: ");
    bt_level_order(tree); // A B C D E F

    printf("\nNode count: %d\n", bt_count_node(tree, -1)); // 6
    printf("Leaf count: %d\n", bt_count_leaf(tree)); // 3
    printf("Degree One count: %d\n", bt_count_node(tree, 1)); // 1
    printf("Degree Two count: %d\n", bt_count_node(tree, 2)); // 2

    BinaryTree *tree2 = bt_create('A');
    BinaryTree *nodeB2 = bt_create('B');
    BinaryTree *nodeC2 = bt_create('C');
    BinaryTree *nodeG2 = bt_create('G');
    BinaryTree *nodeE2 = bt_create('E');
    BinaryTree *nodeF2 = bt_create('F');
    BinaryTree *nodeD2 = bt_create('D');
    BinaryTree *nodeH2 = bt_create('H');
    BinaryTree *nodeI2 = bt_create('I');
    //        A
    //       / \
    //      B   C
    //     /   /  \
    //    D    E   F
    //     \      /
    //      G     H
    //             \
    //              I

    tree2->left = nodeB2;
    tree2->right = nodeC2;
    nodeB2->left = nodeD2;
    nodeD2->right = nodeG2;
    nodeC2->left = nodeE2;
    nodeC2->right = nodeF2;
    nodeF2->left = nodeH2;
    nodeH2->right = nodeI2;

    printf("\nPre-order: ");
    bt_pre_order(tree2);

    printf("\nIn-order: ");
    bt_in_order(tree2);

    printf("\nPost-order: ");
    bt_post_order(tree2);


    printf("\nNode count: %d\n", bt_count_node(tree2, -1)); // 9
    printf("Leaf count: %d\n", bt_count_leaf(tree2)); // 4
    printf("Degree One count: %d\n", bt_count_node(tree2, 1)); // 3
    printf("Degree Two count: %d\n", bt_count_node(tree2, 2)); // 2

    return 0;
}
