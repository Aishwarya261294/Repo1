#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
    struct node *parent;
};
struct node *succ(struct node *node, struct node *n);

void insertnode(struct node **tree, int x)
{
    struct node *temp = NULL;

    if((*tree) == NULL) {
        temp = (struct node *) malloc (sizeof(struct node));
        temp->rchild = temp->lchild = NULL;
        temp->data = x;
        (*tree) = temp;
    }

    if(x <(*tree)->data) {
        insertnode(&(*tree)->lchild, x);
    } else {
        insertnode(&(*tree)->rchild, x);
    }
    return;
}

struct node *searchnode(struct node **tree, int x)
{
    if((*tree) == NULL) {
        return NULL;
    }
    if((*tree)->data == x) {
        return (*tree);
    } else {
        if(x < (*tree)->data){
            searchnode(&(*tree)->lchild, x);
        } else {
            searchnode(&(*tree)->rchild, x);
        }
    }
}

struct node * minval(struct node* node) {
  struct node* current = node;

  while (current->lchild != NULL) {
    current = current->lchild;
  }
  return current;
}

struct node *succ(struct node *node, struct node *n)
{
    if(n->rchild != NULL)
        return minval(n->rchild);

    struct node *p;
    p = n->parent;

    while(p != NULL && n == p->rchild) {
        n = p;
        p = p->parent;
    }
    return p;
}

int main()
{
	int i;
	int n;
	int a;
	int x;
	struct node *root;
	struct node *temp = NULL;
	struct node *temp2 = NULL;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		insertnode(&root, a);
	}
	scanf("%d", &x);

    temp = searchnode(&root, x);

    temp2 = succ(root, temp);

    if(temp2 !=  NULL)
    printf("\n Inorder Successor of %d is %d ", temp->data, temp2->data);
  else
    printf("\n Inorder Successor doesn't exit");

  return 0;
}
