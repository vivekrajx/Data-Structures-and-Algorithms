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
BSTNode *FindMin(BSTNode *root)
{
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

void Inorder(BSTNode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

BSTNode *Find(BSTNode *root, int data)
{
    if (root == NULL)
        return NULL;
    //BASE CONDITION
    //case 1 : data == root->data
    else if (root->data == data)
        return root;
    //case 2 : data in right subtree
    else if (root->data < data)
        return Find(root->right, data);
    //case 3: data in left subtree
    else
        return Find(root->left, data);
}

BSTNode *getSuccessor(BSTNode *root, int data)
{
    //first of all let's search the node for which we want Inorder Successor
    BSTNode *current = Find(root, data);
    if (current == NULL)
        return NULL;

    //case 1 : Node has right subtree, (go to leftmost node in right subtree)
    if (current->right != NULL)
        return FindMin(current->right); //O(h)

    //case 2 : If there is no right subtree walk the tree from root to current node
    //         & find the deepest ancestor for which current node will be in its left subtree

    else
    {
        BSTNode *successor = NULL;
        BSTNode *ancestor = root;

        while (ancestor != NULL) //walk the tree until we have reached the current node
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                //if data in current node is < than data in ancestor
                ancestor = ancestor->left;
            }
            else //current node in right ancestor
            {
                ancestor = ancestor->right;
                //if current->data > ancestor->data
            }
        }
        return successor;
    }
    //OVERALL T.C : O(h)
}

int main()
{
    BSTNode *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 1);
    root = Insert(root, 11);
    cout << "Inorder : ";
    Inorder(root);
    cout << endl;

    //Now finding successor of a given node
    BSTNode *successor = getSuccessor(root, 1);
    if (successor == NULL)
        cout << "No successor exists! \n";
    else
        cout << "Successor is " << successor->data;
}
