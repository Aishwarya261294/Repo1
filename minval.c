#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct tree *lchild;
	struct tree *rchild;
};

struct node *insert(struct node *root, int x)
{
	if(root == NULL) {
		root = (struct node *)malloc(sizeof (struct node));
		root-> data = x;
		root-> lchild = NULL;
		root-> rchild = NULL;

		return (root);
	} else {
		if (root-> data > x) {
			root-> lchild = insert(root-> lchild, x);
		} else if (root-> data < x) {
			root-> rchild = insert(root-> rchild, x);
		}
	}

	return (root);
}
int minval(struct node *root)
{
    struct node *curr = root;

    while(curr->lchild != NULL) {
        curr = curr->lchild;
    }
    return(curr->data);
}
void print_post(struct node *tree)
{
    if(tree != NULL){
        print_post(tree->lchild);
        printf("%d", tree->data);
        print_post(tree->rchild);
    }
    return;
}

int main()
{
    int n;
    int i;
    int x;
    int y;
    struct node *tree = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
                scanf("%d", &x);
                tree = insert(tree, x);
            }
    print_post(tree);
    y = minval(tree);
    printf("%d", y);
}
