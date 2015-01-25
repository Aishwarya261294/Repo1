int isbst(struct node *root)
{
    return isbst2(root, INT_MIN, INT_MAX);
}

int isbst2(struct node *node, int min, int max)
{
    if(node == NULL)
        return 1;

    if(node->data < min || node->data > max)
        return 0;

   return(isbst2(node->left, min, node->data - 1)&&
    isbst2(node->right, node->data + 1, max));
}

struct node *lca(struct node * node, int n1, int n2)
{
    if(node == NULL)
        return NULL;

    if(node->data > n1 && node->data > n2)
        return lca(node->left, n1, n2);

    if(node->data < n1 && node->data < n2)
        return lca(node->right, n1, n2);

    return node;
}

struct node *succ(struct node *root, struct node *n)
{
    if(n->right != NULL)
        return minval(n->right);

    struct node *succ = NULL;

    while(root != NULL) {
        if(n->data < root->data) {
            root = succ;
            root = root->left;
        } else if(n->data > root->data)
            root = root->right;
         else
            break;
    }
    return succ;
}

int largestbst(struct node *root)
{
    if(isbst(root)){
        return size(root)
    } else {
        return max(largestbst(root->left),largestbst(root->right));
    }
}

void print(struct node *root, int k1, int k2)
{
    if(root == NULL)
        return;

    if(k1 < root->data)
        print(root->left, k1, k2);

    if(k1 <= root->data && k2 >=root->data)
        printf("%d", root->data);

    if(k2 > root->data)
        print(root->right, k1, k2);
}

struct node *remove(struct node * root, int k1, int k2)
{
    if(root == NULL)
        return NULL;

    root->left = remove(root->left, k1, k2);
    root->right = remove(root->right, k1, k2);

    if(root->data < k1){
        struct node *lchild = root->left;
        delete root;
        return lchild;
    }

    if(root->data < k2){
        struct node *rchild = root->right;
        delete root;
        return rchild;
    }
    return root;
}

int onechild(int pre[], int size)
{
    int min, max;

    if(pre[size - 1] > pre[size - 2]) {
        max = pre[size - 1];
        min = pre[size - 2]
    } else {
        min = pre[size - 1];
        max = pre[size - 2];
    }

    int i;

    for(i = size - 3; i >= 0; i--) {
        if(pre[i] < min) {
            min = pre[i];
    } else if(pre[i] > max)
            max = pre[i];
    else
    return false;
    }
    return true;
}

void correctbst(struct node *root)
{
    struct node *first, *mid, *last, *prev;
    first = mid = last = prev = NULL;

    correctbst2(root, &first, &mid, &last, &prev);

    if(first && last)
        swap(&first->data, &last->data);
    else if(first && mid)
        swap(&first->data, &mid->data);
}

void correctbst2(struct node *root, struct node **first, struct node **mid, struct node **last, struct node **prev)
{
    if(root) {
        correctbst2(root->left, first, mid, last, prev);

        if(*prev && root->data < prev->data) {
            if(!(*first)) {
                *first = *prev;
                *mid = root;
            } else {
                *last = root;
            }
        }
        *prev = root;
        correctbst2(root->right, first, mid, last, prev);
    }
}


struct node *delete(struct node *root, int x)
{
    struct node *p1;
    struct node *p2;
    struct node *p3;

    if(root == NULL) {
        printf("NOT FOUND");
        free root;
    } else {
        if(root->data > x) {
            root->left = delete(root->left, x);
        } else if(root->data < x) {
            root->right = delete(root->right, x);
        }

        if(root->data == x) {
                if(root->left == root->right) {
                    free root;
                    return NULL;
                } else if(root->right != NULL && root->left == NULL) {
                    free root;
                    return root->right;
                } else if(root->left != NULL && root->right == NULL) {
                    free root;
                    return root->left;
                } else {

                p1 = root;
                p2 = root->right;
                pr = p2->left;

                while(p3 != NULL){
                    p1 = p2;
                    p2 = p3;
                    p3 = p2->left;
                }
                if(p1 != root) {
                    p1->left = p2->right;
                    p2->right = root->right;
                }
                p2->left = root->left;
                return p2;
            }
        }
    }
    return root;
}

