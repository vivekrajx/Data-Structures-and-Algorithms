#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* head; //global variable

void insert(int x){

    Node* temp = new Node();
    temp->data = x;
    //->next = NULL;
    //head= temp;  //since we inserted a node in empty list
    //if list is not empty and we want to  insert at starting
    //if(head!=NULL) temp->next = head;
    temp->next = head; //when list is empty initially
    head = temp;

}
void print(){
     Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


int main(){
    int n,x;
    cout<<"How many numbers : ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter the number \n";
        cin>>x;
        insert(x);
        print();
    }
}