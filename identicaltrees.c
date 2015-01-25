#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(struct node *node, int data)
{
    node = (struct node*) malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return(node);
}

int identicaltrees(struct node* a, struct node* b)
{
    if (a==NULL && b==NULL)
        return 1;

    if (a!=NULL && b!=NULL) {
        return(a->data == b->data && identicaltrees(a->left, b->left) && identicaltrees(a->right, b->right));
    }
    return 0;
}

int main()
{
    int i;
    int n;
    int m;
    int x;
    int y;
    struct node *tree1;
    struct node *tree2;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        tree1 = newnode(tree1,x);
    }
    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        scanf("%d", &y);
        tree2 = newnode(tree2,y);
    }

    if(identicaltrees(tree1, tree2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
    return 0;
}
