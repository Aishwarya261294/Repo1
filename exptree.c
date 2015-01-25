#include <stdio.h>
#include <stdlib.h>
#define n 100

struct node {
    char item;
    int stkptr;
    struct node* left;
    struct node* right;
    struct node* stack[n];
}s;

struct node* pop();
void push(struct node* root);
void infix(struct node* root);
void prefix(struct node* root);
void postfix(struct node* root);

void disptree()
{
    int choice;
    printf("Select the output form: 1.infix, 2.prefix, 3.postfix: \n");
    scanf("%d", &choice);

    switch(choice) {
    case 1:
        printf("Inorder: \n");
        infix(s.stack[s.stkptr]);
    break;

    case 2:
        printf("Preorder: \n");
        prefix(s.stack[s.stkptr]);
    break;

    case 3:
        printf("Postorder: \n");
        postfix(s.stack[s.stkptr]);
    break;

    default:
        printf("Wrong choice\n");
    }
}

void infix(struct node* root)
{
    if(root->left != NULL)
        infix(root->left);
        printf("%c", root->item);

    if(root->right !=NULL)
        infix(root->right);
}

void prefix(struct node* root)
{
    printf("%c", root->item);

    if(root->left != NULL)
        prefix(root->left);

    if(root->right !=NULL)
        prefix(root->right);
}

void postfix(struct node* root)
{
    if(root->left != NULL)
        postfix(root->left);

    if(root->right !=NULL)
        postfix(root->right);

    printf("%c", root->item);
}

void opfunc(char optr, struct node *root)
{
    root = (struct node*)malloc(sizeof(struct node));
    root->item = optr;
    root->right = pop();
    root->left = pop();
    push(root);
}

void varfunc(char var, struct node *root)
{
    root = (struct node*)malloc(sizeof(struct node));
    root->item = var;
    root->right = NULL;
    root->left = NULL;
    push(root);
}

void push(struct node* root)
{
    s.stack[++s.stkptr] = root;
}

struct node* pop()
{
    return(s.stack[s.stkptr--]);
}

int chkelement(char element)
{
    switch(element) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
        return(1);
    default:
        return(0);
    }
}

int main()
{
    int count;
    char equation[25];
    s.stkptr = -1;
    struct node *root;

    gets(equation);
    puts(equation);

    for(count = 0; equation[count] != '\0'; count++) {
        switch(chkelement(equation[count])) {
            //1.operator, 0.notoperator
            case 1:
                opfunc(equation[count], root);
            break;

            case 0:
                varfunc(equation[count], root);
            break;

            default:
                printf("Wrong entry\n");
        }
    }

    disptree();

    return 0;
}
