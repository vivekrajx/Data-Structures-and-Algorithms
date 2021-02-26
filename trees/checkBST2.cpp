#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode *getNewNode(int data)
{
    BSTNode *newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *Insert(BSTNode *root, int data)
{
    //case 1 : if tree is empty
    if (root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    //case 2 : if data <= root //left subtree
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
        return root;
    }
    //case 3: if data > root //right subtree
    else
    {
        root->right = Insert(root->right, data);
        return root;
    }
}

bool isBSTUtil(BSTNode *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true; //base case
    if (root->data > minVal && root->data < maxVal && isBSTUtil(root->left, minVal, root->data) && isBSTUtil(root->right, root->data, maxVal))

        return true;
    else
        return false;
}

bool isBST(BSTNode *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    BSTNode *root = NULL;

    /*root = Insert(root,7); root = Insert(root,4); 
   // root = Insert(root, 9); root= Insert(root, 1);
    root = Insert(root, 6);
    */
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 18);
    cout << isBST(root);
}
