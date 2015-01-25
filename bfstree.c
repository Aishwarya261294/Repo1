#include <stdio.h>
#include <stdlib.h>
#define n 100

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct queue {
    int front;
    int rear;
    struct tree *a[n];
};

struct tree *newnode(int x)
{
    struct tree *newnode;
    newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;

}

void enqueue(struct queue *q, struct tree *node)
{
    if(q->front == -1) {
        q->front = 0;
        q->rear = 0;
        q->a[q->rear] = node;
    } else {
       q-> rear = q->rear + 1;
        q->a[q->rear] = node;
    }
}

struct tree *insert(struct queue *q, int x)
{
    int i;
    struct tree *root;

    if (q->front == -1) {
        root = newnode(x);
        enqueue(q, root);
        return root;
    } else {
        if (q->front == q->rear) {
            root = newnode(x);
            enqueue(q, root);
            q->a[q->front]->left = root;
        } else {
        for (i = q->front; i < q->rear; i++) {

            if (q->a[i]->left == q->a[q->rear]) {
                root = newnode(x);
                enqueue(q, root);
                q->a[i]->right = root;
                break;
            } else if (q->a[i]->right == q->a[q->rear]) {
                root = newnode(x);
                enqueue(q, root);
                q->a[i + 1]->left = root;
                break;
            }
        }
        }
    }
    return (q->a[q->front]);
}

void preorder(struct tree *root)
 {
    if(root != NULL)
   {
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);
   }
   return;
 }

int main()
{
    int i;
    int p;
    int x;
    struct tree *root = NULL;
    struct queue *q;
    q->front = -1;
    q->rear = -1;

    scanf("%d", &p);

    for (i = 0; i < p; i++) {
        scanf("%d", &x);
        root = insert(q, x);
    }

    preorder(root);

    return 0;

}
