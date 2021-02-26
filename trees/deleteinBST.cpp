#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode *GetNewNode(int data)
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
        root = GetNewNode(data);
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

//RECURSIVE APPROACH FOR FINDMIN AND FINDMAX
BSTNode *FindMin(BSTNode *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

//DELETING A NODE
BSTNode *Delete(BSTNode *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data) //Left Subtree
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data); //right subtree

    //so, when data is neither greater nor lesser, i.e if it is equal
    // we can try deleting the node
    else
    {
        //CASE 1 : No Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            //return root;
        }

        //CASE 2: One Child
        else if (root->left == NULL) // Left Child is Null
        {
            //store the addr of current node in temp ptr to node
            BSTNode *temp = root;
            root = root->right;
            delete temp;
            //return root;
        }
        else if (root->right == NULL) // Right Child is Null
        {
            //store the addr of current node in temp ptr to node
            BSTNode *temp = root;
            root = root->left;
            delete temp;
            //return root;
        }

        //CASE 3: 2 Child
        else
        {
            //a) We need to search for min element in right subtree
            //b) then we need to copy that minimum element to root
            //c) then we need to delete the duplicate min value from right subtree

            BSTNode *temp = FindMin(root->right);
            root->data = temp->data; //copied minimum element from right subtree to root

            //now deleting duplicate min value from right subtree
            root->right = Delete(root->right, temp->data);
        }
    }
    return root; //all at once if not provided individually
}

void Inorder(BSTNode *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
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

    // Deleting node with value 5, change this value to test other cases
    root = Delete(root, 5);

    //Print Nodes in Inorder
    cout << "Inorder: ";
    Inorder(root);
    cout << "\n";
}
