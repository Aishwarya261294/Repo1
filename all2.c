/* Recursive function which checks whether all leaves are at same level */
bool checkUtil(struct Node *root, int level, int *leafLevel)
{
    // Base case
    if (root == NULL)  return true;

    // If a leaf node is encountered
    if (root->left == NULL && root->right == NULL)
    {
        // When a leaf node is found first time
        if (*leafLevel == 0)
        {
            *leafLevel = level; // Set first found leaf's level
            return true;
        }

        // If this is not first leaf node, compare its level with
        // first leaf's level
        return (level == *leafLevel);
    }

    // If this node is not leaf, recursively check left and right subtrees
    return checkUtil(root->left, level+1, leafLevel) &&
           checkUtil(root->right, level+1, leafLevel);
}

/* The main function to check if all leafs are at same level.
   It mainly uses checkUtil() */
bool check(struct Node *root)
{
   int level = 0, leafLevel = 0;
   return checkUtil(root, level, &leafLevel);
}

/ C++ program to print postorder traversal from preorder and inorder traversals
#include <iostream>
using namespace std;

// A utility function to search x in arr[] of size n
int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
      if (arr[i] == x)
         return i;
    return -1;
}

// Prints postorder traversal from given inorder and preorder traversals
void printPostOrder(int in[], int pre[], int n)
{
   // The first element in pre[] is always root, search it
   // in in[] to find left and right subtrees
   int root = search(in, pre[0], n);

   // If left subtree is not empty, print left subtree
   if (root != 0)
      printPostOrder(in, pre+1, root);

   // If right subtree is not empty, print right subtree
   if (root != n-1)
      printPostOrder(in+root+1, pre+root+1, n-root-1);

   // Print root
   cout << pre[0] << " ";
}

// Driver program to test above functions
int main()
{
   int in[] = {4, 2, 5, 1, 3, 6};
   int pre[] =  {1, 2, 4, 5, 3, 6};
   int n = sizeof(in)/sizeof(in[0]);
   cout << "Postorder traversal " << endl;
   printPostOrder(in, pre, n);
   return 0;
}
