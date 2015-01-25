// construct binary search tree from given preorder traversal method 2

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct stack {
    int info;
    int top;
    struct node **array;
};

struct node * newnode(struct node * root, int x) {

    if(root == NULL) {
        root = (struct node *) malloc(sizeof(struct node));
        root->data = x;
        root->left = root->right = NULL;
        return root;
    } else {
        if(x > root->data){
            root->right = newnode(root->right, x);
        } else {
            root->left = newnode(root->left, x);
        }
    }
    return root;
}


struct stack * createstack(int x)
{
    struct stack* stack1 = (struct stack *) malloc(sizeof(struct stack));
    stack1->top = -1;
    stack1->info = x;
    stack1->array = (struct node **) malloc(stack1->info * sizeof(struct node*));
    return stack1;
}

int isfull(struct stack * stack1)
{
    return stack1->top == stack1->info - 1;
}

int isempty(struct stack * stack1)
{
    return stack1->top == -1;
}

void push(struct stack * stack1, struct node * item)
{
    if(isfull(stack1))
        return;
    stack1->array[++stack1->top] = item;
}

struct node * pop(struct stack * stack1)
{
    if(isempty(stack1))
        return NULL;
    return stack1->array[stack1->top--];
}

struct node * peek(struct stack * stack1)
{
    return stack1->array[stack1->top];
}

struct node* constructtree(int pre[], int size)
{
    struct stack* stack1 = createstack(size);

    // The first element of pre[] is always root
    struct node* root = newnode(root, pre[0]);

    // Push root
    push(stack1, root);

    int i;
    struct node* temp;

    // Iterate through rest of the size-1 items of given preorder array
    for (i = 1; i < size; ++i)
    {
        temp = NULL;

        /* Keep on popping while the next value is greater than
           stack's top value. */
        while (!isempty(stack1) && pre[i] > peek(stack1)->data)
            temp = pop(stack1);

        // Make this greater value as the right child and push it to the stack
        if (temp != NULL)
        {
            temp->right = newnode(temp->right, pre[i] );
            push(stack1, temp->right);
        }

        // If the next value is less than the stack's top value, make this value
        // as the left child of the stack's top node. Push the new node to stack
        else
        {
            peek(stack1)->left = newnode(peek(stack1)->left, pre[i]);
            push(stack1, peek(stack1)->left);
        }
    }

    return root;
}

void printinorder (struct node* node)
{
    if (node == NULL)
        return;
    printinorder(node->left);
    printf("%d ", node->data);
    printinorder(node->right);
}

// Driver program to test above functions
int main ()
{
    int size;
    scanf("%d", &size);
    int pre[size];
    int i;
    struct node *root = NULL;

    for(i = 0; i < size; i++) {
        scanf("%d", &pre[i]);
        root = newnode(root, pre);
    }

    root = constructtree(pre, size);

    printf("Inorder traversal of the constructed tree: \n");
    printinorder(root);

    return 0;
}
