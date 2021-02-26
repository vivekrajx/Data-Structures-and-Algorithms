#include <stdio.h>
#include <iostream>
using namespace std;
// * code to check bst
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

//function to getNewNode
BSTNode *getNewNode(int data)
{
    BSTNode *newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//inserting nodes in BST
BSTNode *Insert(BSTNode *root, int data)
{
    //case 1 : empty tree
    if (root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    //case 2 : if tree not empty and data is <= root, insert in left subtree
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data); //recursive call
        return root;
    }
    //case 3 : if data > root, insert in right subtree
    else
    {
        root->right = Insert(root->right, data); //recursive call
        return root;
    }
}

bool isSubtreeLesser(BSTNode *root, int value);
bool isSubtreeGreater(BSTNode *root, int value);
bool isBST(BSTNode *root);

bool isBST(BSTNode *root)
{
    //base case
    if (root == NULL)
        return true;
    if (isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data)
        //recursive calls now to check whether left and right ST are also BST or not
        && isBST(root->left) && isBST(root->right))
        return true;
    else
        return false;
}

bool isSubtreeLesser(BSTNode *root, int value)
{
    //we will have to traverse all the values in root to check if it's less or not
    if (root == NULL)
        return true;
    if (root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value)) //recursive calls
        return true;
    else
        return false;
}

bool isSubtreeGreater(BSTNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

int main()
{
    BSTNode *root = NULL;
    /*root = Insert(root,15); root = Insert(root,10); root = Insert(root,20);
    root = Insert(root,25); root = Insert(root,8); root = Insert(root,12);
    root = Insert(root,18);*/

    root = Insert(root, 7);
    root = Insert(root, 4);
    // root = Insert(root, 9); root= Insert(root, 1);
    root = Insert(root, 6);
    cout << isBST(root);
}
