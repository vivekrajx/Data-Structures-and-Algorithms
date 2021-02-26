#include<iostream>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* getNewNode(int data)
{
    BSTNode* newNode = new BSTNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//function to insert nodes in BST
BSTNode* Insert(BSTNode*root, int data){
    //case 1: if tree is empty
    if(root==NULL){
        root=getNewNode(data);
        return root;
     }
    //case 2: left subtree (data<root)
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
        return root;
    }
    //case 3: right subtree(data>root)
    else
    {
        root->right = Insert(root->right, data);
        return root;
    }
    
}

void PreOrder(BSTNode* root) //DLR
{
    if(root==NULL) return;
    cout<<root->data<<" ";     //D
    PreOrder(root->left); //L 
    PreOrder(root->right); //R
}

void Inorder(BSTNode* root) //LDR
{
    if(root==NULL) return;
    Inorder(root->left); //L
    cout<<root->data<<" ";  //D
    Inorder(root->right); //R
}

void PostOrder(BSTNode* root) //LRD
{
    if(root==NULL) return;
    PostOrder(root->left); //L
    PostOrder(root->right); //R
    cout<<root->data<<" "; //D
}

int main()
{
    BSTNode* root = NULL;
    root = Insert(root,15); root = Insert(root,10); root = Insert(root,20);
    root = Insert(root,25); root = Insert(root,8); root = Insert(root,12);

    cout<<"Preorder Traversal (D,L,R): "<<" ";
    PreOrder(root); cout<<"\n";
    cout<<"Inorder Traversal (L,D,R): "<<" ";
    Inorder(root); cout<<"\n";
    cout<<"Postorder Traversal (L,R,D): "<<" ";
    PostOrder(root);

}