// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2025. CarmJos
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

#include <stdio.h>
#include <stdlib.h>

typedef char elemtype;
typedef struct node {
    elemtype data;
    struct node *lchild, *rchild;
} bintree;

// 先序遍历方式建立一棵二叉树
bintree *create() {
    char input = getchar();
    if (input == '#') {
        return NULL;
    } else {
        bintree *node = (bintree *) malloc(sizeof(bintree));
        node->data = input;
        node->lchild = create();
        node->rchild = create();
        return node;
    }
}

// 计算树的高度
int height(bintree *root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->lchild);
    int rightHeight = height(root->rchild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// 统计左右子树高度相同的结点个数
int equaldepth(bintree *root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->lchild);
    int rightHeight = height(root->rchild);
    return (leftHeight == rightHeight) + equaldepth(root->lchild) + equaldepth(root->rchild);
}

int main() {
    bintree *root = create();
    printf("same height: %d\n", equaldepth(root));
    return 0;
}
