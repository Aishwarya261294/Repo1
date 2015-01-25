#include <stdio.h>
#include <stdlib.h>

struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};

struct tree *insert(struct tree *root, int x)
{
	if(root == NULL) {
		root = (struct tree *)malloc(sizeof (struct tree));
		root-> info = x;
		root-> left = NULL;
		root-> right = NULL;

		return (root);
	} else {
		if (root-> info > x) {
			root-> left = insert(root-> left, x);
		} else if (root-> info < x) {
			root-> right = insert(root-> right, x);
		}
	}

	return (root);
}

void preorder(struct tree *root)
{
	if(root != NULL) {
		printf("%d\n", root-> info);
		preorder(root-> left);
		preorder(root-> right);
	}
}

void inorder(struct tree *root)
{
	if (root != NULL) {
		inorder(root-> left);
		printf("%d\n", root-> info);
		inorder(root-> right);
	}
}

void postorder(struct tree *root)
{
	if (root != NULL) {
		postorder(root-> left);
		postorder(root-> right);
		printf("%d", root-> info);
	}
}

struct tree *delete(struct tree *root, int x)
{
	struct tree *p1;
	struct tree *p2;
	struct tree *p3;

	if(root == NULL) {
		printf("NOT FOUND");
		return root;
	} else {
		if (root-> info > x) {
			root-> left = delete(root-> left, x);
		} else if (root-> info < x) {
			root-> right = delete(root-> right, x);
		}

		if(root-> info == x) {
			if(root-> left == root-> right) {
				free(root);
				return NULL;
			} else if (root-> right != NULL && root-> left == NULL) {
				free(root);
				return (root-> right);
			} else if (root-> left != NULL && root-> right == NULL) {
				free(root);
				return (root-> left);
			} else {
				p1 = root;
				p2 = root-> right;
				p3 = p2-> left;

				while (p3 != NULL) {
					p1 = p2;
					p2 = p3;
					p3 = p2-> left;
				}

				if(p1 != root) {
					p1-> left = p2-> right;
					p2-> right = root-> right;
				}

				p2-> left = root-> left;

				return p2;
			}
		}
	}

	return root;
}

void print(struct tree *root)
{
	int c;
	 printf("1. inorder\n2. preorder\n3. postorder");
	 scanf("%d", &c);

	 switch (c)
	{
		case 1:
		 inorder(root);
		 break;
		case 2:
		 preorder(root);
		 break;
		case 3:
		 postorder(root);
		 break;
	}

}


int main()
{
	int i;
	int n;
	int a;
	int x;
	struct tree *root = NULL;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		root = insert(root, a);
	}

	print(root);

	printf("enter a no. u want to delete: ");

	scanf("%d", &x);

	root = delete(root, x);

	print(root);

	return 0;
}
