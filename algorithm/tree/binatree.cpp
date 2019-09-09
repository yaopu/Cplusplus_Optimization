#include <cmath>
#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
  int value;
  Node *left;
  Node *right;
};

int *arr;
int count = 0;
int total_leaves;
Node *build_tree(int *arr, int, int);
void preorder(Node *p); ///前序遍历
void inorder(Node *p);  //中序遍历
void posoder(Node *p);  //后序遍历
int main() {
  int depth = 4;
  int n = pow(2, depth) - 1;
  total_leaves = n;
  arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }

  Node *root = build_tree(arr, 0, n);
  // preorder(root);
 // inorder(root);
  posoder(root);
  return 0;
}

Node *build_tree(int *arr, int i, int m) {

  Node *p;
  if (i >= m) {
    return NULL;
  }
  p = (Node *)malloc(sizeof(Node)); //分配存储空间
  p->value = arr[i];                /// root
  p->left = build_tree(arr, 2 * i + 1, m);
  p->right = build_tree(arr, 2 * i + 2, m);

  return p;
}

void preorder(Node *p) { ///前序遍历
  if (p != NULL) {
    cout << p->value;
    if (p->left) {
      cout << " ---->";
      preorder(p->left);
    }
    if (p->right) {
      cout << "----->";
      preorder(p->right);
    }
  }
}

void inorder(Node *p) //中序遍历
{
  if (p) {
    inorder(p->left);
    cout << p->value;
    cout << " ----->";
    inorder(p->right);
  }
}

void posoder(Node *p) {
  if (p) {

    posoder(p->left);
    cout << p->value;
    cout << "  ----->";
    inorder(p);
  }
}