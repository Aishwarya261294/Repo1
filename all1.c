// if a binary tree is binary search tree
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

//find the min value in a binary search tree
int minval(struct node *node)
{
    struct node *curr = node;

    while(curr->left != NULL) {
        curr = curr->left;
    }
    return (curr->data);
}

// to find the least coomon ancestor of two particular node
struct node *lca(struct node *node, int n1, int n2)
{
    if(root == NULL)
        return root;
    if(root->data > n1 && root->data >n2)
        return lca(root->left, n1, n2);
    if(root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
}

// to find the inoreder successor of given element in binary search tree
struct node *succ(struct node *node, struct node *n)
{
    if(n->right != NULL)
        return minval(n->right);

    struct node *p;
    p = n->parent;

    while(p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

// to print all the values lying b/w k1 and k2 in binary search tree
void print(struct node *root, int k1, int k2)
{

    if(root == NULL)
        return;

    if(k1 < root->data)
        print(root->left, k1, k2);
    if(k1 <= root->data && k2 >= root->data)
        printf("%d", root->data);
    if(k2 > root->data)
        print(root->right, k1, k2);
}


// to make a balanced binary search tree from array elements given
struct node *bst(int a[], int start, int end)
{
    if(start > end)
        return NULL;
    int mid = (start + end)/2;

    struct node *root = newnode(arr[mid]);

    root->left(arr, start, mid-1);
    root->right(arr, mid+1, end);
    return root;
}

//to delete the node of binary search tree which is not in the given range_error
struct node *remove(struct node *root, int min, int max)
{
    if(root == NULL)
        return NULL;

    remove(root->left, min, max);
    remove(root->right, min, max);

    if(root->data < min)
        struct node *rchild = root->right;
        delete root;
        return rchild;

    if(root->data > max)
        struct node *lchild = root->left;
        delete root;
        return lchild;

    return root;
}

//

struct node *insert(struct node *root) { struct node *temp = (struct node *) malloc(sizeof(struct node));
int s;
cin >> s;
temp -> n = s;
temp -> lchild = NULL;
temp -> rchild = NULL;
if (root == NULL)
    return temp;
struct queue q; q.front = 0; q.rear = 0; q.a[q.front] = root; struct node *temp2 = q.a[0]; while (q.front <= q.rear) {
    if (temp2 -> lchild == NULL) {
            temp2 -> lchild = temp;
    break;
    } else {
        q.a[++q.rear] = temp2 -> lchild;
        }
        if (temp2 -> rchild == NULL) {
                temp2 -> rchild = temp;
        break;
        } else {
            q.a[++q.rear] = temp2 -> rchild;
}
    temp2 = q.a[++q.front];
    } return root; }
Chat conversation end

