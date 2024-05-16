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

typedef int ElementType;

// 二叉查找树的实现

typedef struct binary_search_tree_node {
    ElementType data;
    struct binary_search_tree_node *right;
    struct binary_search_tree_node *left;
} BinarySearchTree;

BinarySearchTree *bst_create(ElementType data) {
    BinarySearchTree *node = (BinarySearchTree *) malloc(sizeof(BinarySearchTree));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

BinarySearchTree *bst_min_node(BinarySearchTree *root) {
    BinarySearchTree *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}


BinarySearchTree *bst_insert(BinarySearchTree *root, ElementType data) {
    if (root == NULL) {
        return bst_create(data);
    }
    if (data < root->data) {
        root->left = bst_insert(root->left, data);
    } else if (data > root->data) {
        root->right = bst_insert(root->right, data);
    }
    return root;
}

BinarySearchTree *bst_search(BinarySearchTree *root, ElementType data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return bst_search(root->left, data);
    } else {
        return bst_search(root->right, data);
    }
}

BinarySearchTree *bst_delete(BinarySearchTree *root, ElementType data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = bst_delete(root->left, data);
    } else if (data > root->data) {
        root->right = bst_delete(root->right, data);
    } else {
        if (root->left == NULL) {
            BinarySearchTree *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BinarySearchTree *temp = root->left;
            free(root);
            return temp;
        }
        BinarySearchTree *temp = bst_min_node(root->right);
        root->data = temp->data;
        root->right = bst_delete(root->right, temp->data);
    }
    return root;
}

void bst_pre_order(BinarySearchTree *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    bst_pre_order(root->left);
    bst_pre_order(root->right);
}

void bst_in_order(BinarySearchTree *root) {
    if (root == NULL) return;
    bst_in_order(root->left);
    printf("%d ", root->data);
    bst_in_order(root->right);
}

void bst_post_order(BinarySearchTree *root) {
    if (root == NULL) return;
    bst_post_order(root->left);
    bst_post_order(root->right);
    printf("%d ", root->data);
}



int main(){

    //实现二叉查找树的基本算法：
    //1.依次将3，1，4，6，9，2，5，7插入到二叉查找树，使用中序遍历输出该树的元素信息
    //2.删除元素值为3的结点后，使用中序遍历再次输出该树的元素信息

    BinarySearchTree *root = NULL;
    root = bst_insert(root, 3);
    root = bst_insert(root, 1);
    root = bst_insert(root, 4);
    root = bst_insert(root, 6);
    root = bst_insert(root, 9);
    root = bst_insert(root, 2);
    root = bst_insert(root, 5);
    root = bst_insert(root, 7);

    printf("In order: ");
    bst_in_order(root);

    printf("\n");

    root = bst_delete(root, 3);
    printf("In order: ");
    bst_in_order(root);


}
