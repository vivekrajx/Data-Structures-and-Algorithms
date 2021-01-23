#include<iostream>
using namespace std;


struct Node {
    int data;
    struct Node* link;
};

struct Node* top =NULL; //declared top of the stack or head of LL as Null

void Push(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->link = top;  //point new node to existing top
    top = temp;         //just inserting the element at the top or beginning of list
}

void Pop(){
    struct Node* temp;
    if(top==NULL) return; //empty list
    temp = top; //ptr to node temp points to top
    top = top->link; //we are breaking the link and making top point to next el in list
    free(temp);
}

int Top(){
    return top->data; //just returns the element at top index
}

bool isEmpty(){
    if(top==NULL)
        return true;
    else
        return false;
}

void Print(){
    cout<<"Stack: ";  
    Node* current = top; // Initialize current  
    while (current != NULL)  
    {  
        cout<<current->data<<endl;
        current = current->link;  
    }  
    //cout<<endl;
}


int main(){
    Push(2); Print();
    Pop();
    Push(5); Print();
    Push(10); Print();
    Pop(); Print();
    Push(12); Print();
    

}
