#include <iostream>
#include <queue>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

//function to get new node
BSTNode *getNewNode(int data)
{
    BSTNode *newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//function to insert nodes in BST
BSTNode *Insert(BSTNode *root, int data)
{
    //case 1: if tree is empty
    if (root == NULL)
    {
        root = getNewNode(data);
        return root;
    }
    //case 2: left subtree (data<root)
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
        return root;
    }
    //case 3: right subtree(data>root)
    else
    {
        root->right = Insert(root->right, data);
        return root;
    }
}

void levelOrder(BSTNode *root)
{
    if (root == NULL)
        return;
    queue<BSTNode *> Q;
    Q.push(root);
    //while there is atleast 1 discovered node
    while (!Q.empty())
    {
        BSTNode *current = Q.front();
        cout << current->data << endl;
        //ek node ka data print krwa do uske baad uske left ya right child check kro
        //agr h toh push them in the queue and pop the node jiske child insert hue..
        //SO BFS (level by level or level order) traversal takes place
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop(); //removing the element at the front of the queue
    }
}

int main()
{
    BSTNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    cout << "Level Order Traversal of tree: " << endl;
    levelOrder(root);
}
