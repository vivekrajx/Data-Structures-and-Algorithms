#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

struct Node* head; //globally declared

struct Node* getNewNode(int x){     //this function creates a new node and returns it
    Node* newNode = new Node();
    newNode->data =x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;    
}

void insertAtHead(int x){
    Node* newNode = getNewNode(x);
    if(head==NULL){
        head = newNode;   //if the list is empty
        return;
    }
    //when list is not empty
    head->prev = newNode;
    newNode->next = head;
    head = newNode; //very cool

}
void print(){
     Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void ReversePrint(){
    
    Node* temp = head;
    if(temp==NULL) return; //empty list, exit
    //first we go to the end of the list using next ptr
    while(temp->next!=NULL){
        temp = temp->next;
    }
    //and then we traverse backwards...
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<"\n";
}

int main()
{
    head = NULL;

    insertAtHead(2); print(); ReversePrint();
    insertAtHead(4); print(); ReversePrint();
    insertAtHead(6); print(); ReversePrint();  

}
