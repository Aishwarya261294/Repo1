#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *create(struct node *root, int *ptr, int i, int size)
{
	root = (struct node *)malloc(sizeof(struct node));

	root->data = ptr[i];
	root->left = root->right = NULL;

	if((2*i + 1) < size) {
		root->left = create(root->left, ptr, 2*i + 1, size);
	}
       	if(2*i + 2 < size) {
		root->right = create(root->right, ptr, 2*i + 2, size);
	}
	return root;
}

void preorder(struct node *root)
{
	if(root != NULL) {
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
	}
	return ;
}

int size(struct node* node)
{
  if (node==NULL)
    return 0;
  else
    return(size(node->left) + 1 + size(node->right));
}

int isbst(struct node *node)
{
    return(isbst2(node, INT_MAX, INT_MIN));
}

int isbst2(struct node *node, int max, int min) {

    if(node == NULL)
        return 1;

    if(node->data < min || node->data > max)
        return 0;

    return isbst2(node->left, min, node->data-1) && isbst2(node->right, node->data+1, max);
}

int main()
{
	int i;
	int n;
	scanf("%d", &n);
	int a[n];
	struct node *root = NULL;
	int x;
	int y;

	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	root = create (root, a, 0, n);
	x = size(root);
	y = isbst(root);
    printf("%d", x);
    if(y == 1) {
        printf("Yes");
    } else {
        printf("No");
    }
	return 0;
}
