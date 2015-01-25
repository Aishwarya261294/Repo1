#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

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

void print_pre(struct node *tree)
{
    if(tree != NULL) {
        printf("%d", tree->data);
        print_pre(tree->lchild);
        print_pre(tree->rchild);
    }
    return;
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

void print_in(struct node *tree)
{
    if(tree != NULL) {
        print_in(tree->lchild);
        print_in(tree->rchild);
        printf("%d",tree->data);
    }
    return;
}

void deletenode(struct node **tree, int num)
{
    int found ;
    struct node *parent, *x, *y;    /*y is successor of x */

    if (*tree == NULL) {            /* if tree is empty */
        printf("Tree is empty\n");
        return ;
    }

    parent = x = NULL;
    searchnode(tree, num, &parent, &x, found);

    if (found == FALSE) {         /* if the node to deleted is not found */
        printf("Data to be deleted is not found\n");
        return;
    }


    if (x->lchild != NULL && x->rchild != NULL ) {      /* if the node to be deleted has two children */
        parent = x;
        y = x->rchild;

        while (x->lchild != NULL) {
            parent = y;
            y = y->lchild;
        }

        x->data = y->data;
        x = y;
    }

    if (x->lchild == NULL && x->rchild == NULL) {       /* if the node to be deleted has no child */
        if (parent->rchild == x)
            parent->rchild = NULL;
        else
            parent->lchild = NULL;

        free(x);
        return;
    }

    if (x->lchild == NULL && x->rchild != NULL) {       /* if the node to be deleted has only rightchild */
        if (parent-> lchild == x)
            parent->lchild = x->rchild ;
        else
            parent->rchild = x->rchild ;

        free(x);
        return;
    }

    if (x->lchild != NULL && x->rchild == NULL) {      /* if the node to be deleted has only left child */
        if (parent->lchild == x )
            parent->lchild = x->lchild;
        else
            parent->rchild = x->lchild ;

        free(x);
        return;
    }
}

/*returns the address of the node to be deleted, address of its parent and
   whether the node is found or not */

void searchnode(struct node **tree, int num, struct node **par, struct node **x, int *found)
{
    struct node *q ;

    q = *tree;
    *found = FALSE ;
    *par = NULL ;

    while (q != NULL) {
        if(q->data == num) {            /* if the node to be deleted is found */
            *found = TRUE;
            *x = q;
            return;
        }
        *par = q;

        if(q->data > num)
            q = q->lchild ;
        else
            q = q->rchild ;
    }
}

int main()
{
    struct node *tree;
    int i;
    int n;
    int x;
    int y;
    int z;
    int choice;
    int option = 1;

    scanf("%d", &n);

    while (option) {
        printf("1. Insert in tree\n");
        printf("2. Search in tree\n");
        printf("3. Preoreder traversal of tree\n");
        printf("4. Postorder traversal of tree\n");
        printf("5. Inorder traversal of tree\n");
        printf("6. Delete a node from tree\n");
        printf("wrong choice\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for(i = 0; i < n; i++) {
                printf("Enter the value to be inserted:\n");
                scanf("%d", &x);
                insertnode(&tree, x);
            }
            break;
        case 2:
            printf("Enter the value to be searched:\n");
            scanf("%d", );
            temp = searchnode(&tree, &y);
            printf("%d", &temp);
            break;
        case 3:
            print_pre(tree);
            break;
        case 4:
            print_post(tree);
            break;
        case 5:
            print_in(tree);
            break;
        case 6:
            printf("Enter the node to be deleted\n");
            scanf("%d", &z);
            deletenode(&tree, z);
            break;
        case 7:
            return;
        }
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &option);
    }
    return 0;
}
