#include<iostream>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left; //left child
    BSTNode* right; //right child
};

//function to create a new node
BSTNode* GetNewNode(int data) {
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


//function to insert a node in the BST
BSTNode* Insert(BSTNode* root, int data)
{   
    //case 1 : empty tree
    if(root==NULL)
    {
        root=GetNewNode(data);
        return root; 
    }
    //case 2 : if tree not empty and data is <= root, insert in left subtree
    else if(data<=root->data)
    {
        root->left=Insert(root->left, data); //recursive call 
        return root;
    }
    //case 3 : if data > root, insert in right subtree
    else
    {
        root->right = Insert(root->right, data); //recursive call
        return root;
    }

}

//function to search data in BST
bool Search(BSTNode* root, int data)
{
    //returns true if data is present,else false
    //case 1 
    if(root==NULL) return false; //empty tree
    //case 2 
    if(root->data == data) return true;
    //case 3.1 left subtree
    else if(data<=root->data) return Search(root->left, data); //recursive call
    //case 3.2 right subtree
    else return Search(root->right, data); //recursive call
}

/*int FindMin(BSTNode * root)
{   //iterative approach
    //here we use root as local variable
    if(root==NULL){cout<<"Empty Tree!"; return -1;}
    while(root->left!=NULL)
    {
        root = root->left;
    }
    return root->data;   
}

int FindMax(BSTNode * root)
{
    //iterative approach
    //here we use root as local variable
    if(root==NULL){cout<<"Empty Tree!"; return -1;}
    while(root->right!=NULL)
    {
        root = root->right;
    }
    return root->data;
}*/

//RECURSIVE APPROACH FOR FINDMIN AND FINDMAX
int FindMin(BSTNode* root)
{
    if(root==NULL){cout<<"Empty Tree! "; return -1;}
    else if (root->left == NULL)
        return root->data;   // recursion applied!
    //search in left subtree 
    return FindMin(root->left);
}

int FindMax(BSTNode* root)
{
    if(root==NULL){cout<<"Empty Tree"; return -1;}
    else if(root->right==NULL)
        return root->data; //recursion applied!
    //search in right subtree
    return FindMax(root->right);
}

//Finding height of tree or maximum depth.
int FindHeight(BSTNode* root)
{
    if(root==NULL)
        return -1;
    return max(FindHeight(root->left),FindHeight(root->right))+1;
}


int main()
{
    BSTNode* root= NULL;   //initially, when the tree is empty
   
    root = Insert(root,15); root = Insert(root,10); root = Insert(root,20);
    root = Insert(root,25); root = Insert(root,8); root = Insert(root,12);

    int number;
    cout<<"Minimum Element : "<<FindMin(root)<<endl;
    cout<<"Maximum Element : "<<FindMax(root)<<endl;
    cout<<"Height of tree is : "<<FindHeight(root)<<endl;
    cout<<"Enter a number to be searched in BST : ";
    cin>>number;
    if(Search(root, number)==true) cout<<"Found \n";
    else cout<<"Not Found \n";
    
}
