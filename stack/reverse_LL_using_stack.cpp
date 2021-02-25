#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* head = NULL;

Node* insert(int data)
{
    Node* temp = new Node(); //new node created
    temp->data = data; 
    temp->next = NULL;
    
    if(head==NULL) head = temp; //insertion at head
    else{
        Node* temp1 = head; //for all other cases, we need to go to n-1th node and make adjustments
        while(temp1->next!=NULL) temp1 = temp1->next;
        temp1->next =temp; //INSERTION AT THE END OF THE LINKED LIST
        }
    return head;
}

void Reverse()
{
    if(head==NULL) return;
    stack<struct Node*> S;
    Node* temp =head;
    while(temp!=NULL){
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top(); //temp now points to top of stack
    head = temp; //we point head to end of list or top of stack
    S.pop();
    while(!S.empty()){ //jbtk stack khali nahi hta krte rho
        temp->next = S.top(); //dereference kiya temp ko to point to top
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL; //finally last node ke link ko null krdo //khtm ab
}

void Print() {
  Node* temp = head;
  while (temp != NULL) {
    cout<<temp -> data;
    temp = temp -> next;
    cout<<" ";
  }
  cout<<"\n";
}

int main()
{
   // char c[51];
    //cout<<"Enter the string : ";
    //gets(c);
    insert(4);
    insert(5);
    insert(8);
    cout<<"Before Reversing : "<<endl;
    Print();
    Reverse();
    cout<<"After reversing : "<<endl;
    Print();
   // cout<<"After reversing string : "<<c;

}