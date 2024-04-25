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

void main() {
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

}
