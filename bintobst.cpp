// Converting a binary tree to BST. (same approach can be used for correcting a bst wherein 2 nodes have been swapped.)

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
    int val;
    struct node *left;
    struct node *right;
};

struct node *newNode(int x) {
    struct node *newnode = NULL;

    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->val = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void inorder(struct node *root, int arr[], int *i) {
    if (root) {
        inorder(root->left, arr, i);
        arr[(*i)++] = root->val;
        inorder(root->right, arr, i);
    } else {
        return;
    }
}

void inorderTraverse(struct node *root, int arr[], int *i) {
    if (root) {
        inorderTraverse(root->left, arr, i);
      //  cout << "arr " << arr[*i] << endl;
        root->val = arr[(*i)++];
        inorderTraverse(root->right, arr, i);
    } else {
        return;
    }
}

void traverse(struct node *root, int *n) {
    if (root) {
        traverse(root->left, n);
        cout << root->val << " ";
        (*n)++;
        traverse(root->right, n);
    } else {
        return;
    }
}

int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);


    int n = 0;
    traverse(root, &n);

    cout << endl;

    int a[n];

    int i = 0;
    int j;
    inorder(root, a, &i);

    for (i = 0; i < n - 1; i++) {
        int min = a[i];
        for (j = i + 1; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                a[j] = a[i];
                a[i] = min;
            }
        }
    }

  /*  for (i = 0; i < n; i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
    */

    i = 0;
    inorderTraverse(root, a, &i);

   /* cout << root->val << endl;
    cout << root->right->val << endl;
    cout << root->left->val << endl;
*/
    traverse(root, &n);

    return 0;
}





