#include <stdio.h>
#include <stdlib.h>

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

int main()
{
	int i;
	int n;
	scanf("%d", &n);
	int a[n];
	struct node *root = NULL;

	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	root = create (root, a, 0, n);
	preorder(root);

	return 0;
}
