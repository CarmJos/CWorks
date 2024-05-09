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

// 计算指定度数(即其拥有的子节点个数)的节点个数
// degree = -1 代表所有节点
// degree = 0 代表叶子节点
// degree = 1 代表拥有一个子节点的节点
// degree = 2 代表拥有两个子节点的节点
int bt_count_node(BinaryTree *root, int degree) {
    if (root == NULL) return 0;
    if (degree == -1) {
        return 1 + bt_count_node(root->left, degree) + bt_count_node(root->right, degree);
    }
    if (degree == 0 && root->left == NULL && root->right == NULL) return 1;
    if (degree == 1 && (root->left == NULL || root->right == NULL)) return 1;
    if (degree == 2 && root->left != NULL && root->right != NULL) return 1;

    return bt_count_node(root->left, degree) + bt_count_node(root->right, degree);
}

int bt_count_leaf(BinaryTree *root) {
    return bt_count_node(root, 0);
}

//       A
//     /    \
//    B      C
//   / \   /
//  D   E F
int main() {

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


    printf("Pre-order: ");
    bt_pre_order(tree); // A B D E C F

    printf("\nIn-order: ");
    bt_in_order(tree); // D B E A F C

    printf("\nPost-order: ");
    bt_post_order(tree); // D E B F C A

    printf("\nLeaf count: %d\n", bt_count_leaf(tree)); // 3
    printf("Node count: %d\n", bt_count_node(tree, -1)); // 6
    printf("Degree One count: %d\n", bt_count_node(tree, 1)); // 2
    printf("Degree Two count: %d\n", bt_count_node(tree, 2)); // 1


    return 0;
}
