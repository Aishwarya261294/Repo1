#include <iostream>

using namespace std;

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *create(struct tree *root, int value)
{
    if (root == NULL) {
        root = new (struct tree);

        root->data = value;
        root->left = NULL;
        root->right = NULL;
    } else if (root->data > value)
        root->left = create(root->left, value);
    else if (root->data < value)
        root->right = create (root->right, value);

    return root;
}

struct tree *delete_node(struct tree *root, int value)
{
    if (root == NULL)
        return root;
    else if (root->data > value)
        root->left = delete_node(root->left, value);
    else if (root->data < value)
        root->right = delete_node(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->right == NULL)
            return root->left;
        else if (root->left == NULL)
            return root->right;
        else {
            struct tree *temp = NULL;

            temp = root->right;

            if (temp->left == NULL) {
                temp->left = root->left;
                return temp;
            } else {
                while (temp->left->left != NULL) {
                    temp = temp->left;
                }

                struct tree *temp2 = NULL;
                temp2 = temp->left;
                temp2->left = root->left;
                temp->left = temp2->right;
                temp2->right = root->right;

                return temp2;
            }
        }
    }
}

int height(struct tree *root)
{
    if (root == NULL)
        return 0;
    else {
        int Hleft = 1;
        int Hright = 1;

        Hleft = Hleft + height(root->left);
        Hright = Hright + height(root->right);

        if (Hleft > Hright)
            return Hleft;
        else
            return Hright;
    }
}

struct tree *level_del(struct tree *root1, struct tree *root, int level)
{
    if (root == NULL)
        return NULL;
    if (level == 0)
        root1 = delete_node(root1, root->data);
    else {
        root1 = level_del(root1, root->left, level-1);
        root1 = level_del(root1, root->right, level-1);
    }

    return root1;
}

struct tree *level(struct tree *root, int i)
{
    //int i;
    //int h = height(root);

    //for (i = 0; i < h; i++)
        root = level_del(root, root, i);

        return root;
}

int ancestors(struct tree *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    else {
        if(ancestors(root->left, value) || ancestors(root->right, value)) {
            cout<<root->data<<' ';
        }
    return 1;
    }
}

void PreOrder(struct tree *root)
{
    if (root != NULL) {
        cout<<root->data<<' ';
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(struct tree *root)
{
    if (root != NULL) {
        InOrder(root->left);
        cout<<root->data<<' ';
        InOrder(root->right);
    }
}

void PostOrder(struct tree *root)
{
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<' ';
    }
}

void ancestor1(struct tree*temp,int x,int y)
{
    if (temp != NULL) {
        if (temp->data > x && temp->data > y) {
            ancestor1(temp->left,x,y);
        } else if (temp->data < x&& temp->data < y) {
            ancestor1(temp->right,x,y);
        } else {
            cout<<"Common Parent "<<temp->data<<endl;
        }
    }
}

int main()
{
    int i, n, r;
    struct tree *root = NULL;

    cout<<"enter the number of elements to be inserted : ";
    cin>>n;

    for (i = 0; i < n; i++) {
        cin>>r;
        root = create(root, r);
    }

    cout<<"inputed tree"<<endl;
    PreOrder(root);
    cout<<endl<<endl;

    cout<<"neter the value to be deleted : ";
    cin>>r;

    root = level(root, r);
    cout<<endl;

    //root = delete_node(root, r);

    cout<<endl<<"tree after deleting the value"<<endl;
    PreOrder(root);
    cout<<endl<<endl;

    cout<<endl<<"enter the elemnt whose ancestor u want to print :";
    cin>>r;
    r = ancestors(root, r);
    ancestor1(root,42,49);
    return 0;
}
