#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};
//struct Node* head; //head is declared global here

Node* insert(Node* head, int data)
{
    Node* temp = new Node(); //new node created
    temp->data = data; 
    temp->link = NULL;
    
    if(head==NULL) head = temp;
    else{
        Node* temp1 = head; //for all other cases, we need to go to n-1th node and make adjustments
        while(temp1->link!=NULL) temp1 = temp1->link;
        temp1->link =temp; 
        }
    return head;
}

void Print(struct Node* temp){
    //argument is the address of a node which is of type ptr to a node
    //here head is a local var
    if(temp==NULL)return; //exit condition
    cout<<temp->data<<" "; //first print the value in node
    //and then make recursive calls
    Print(temp->link);

    //for printing in reverse order just send the recursive call before printing elements
    /*
        Print(temp->link);
        cout<<temp->data<<" ";
    */
}

void ReversePrint(struct Node* temp){
    if(temp==NULL) return;
    ReversePrint(temp->link);
    cout<<temp->data<<" ";
}

int main()
{
    struct Node* head = NULL; //local var , head init to NULL means list is empty
    //we modify head everytime
    head = insert(head,2);
    head = insert(head,4);
    head = insert(head,6);
    head = insert(head,5);

    cout<<"Printing the linked list : \n";
    Print(head);
    cout<<"\nPrinting in reverse order now : \n";
    ReversePrint(head);
}