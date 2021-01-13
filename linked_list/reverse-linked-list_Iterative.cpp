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

struct Node* reverse(struct Node* head)
{
    //reverse fn will reverse the linked list pointed to by the head
    //at each step as we traverse the list 
    // we'll modify the link part of the node to point to prev node instead of next
    Node *current, *prev, *next;
    current = head; //created a ptr to head for traversal purpose
    prev = NULL; //prev for head node is always null
    while(current!=NULL){
       // current->next = prev; //as we traverse we set current node to pt to prev node
        //but it breaks the link to go to next node
        //so we should store the addr of next node in another temp variable

        next = current->link; //first we store the addr of next node in link
        //now we can set the link part of current node to prev
        current->link = prev;
        prev = current;    
        current  = next;
        //we redefine prev and current , we first move prev to current and
        //then current to next

    }
    //after exiting the loop we have to adjust the head
    head = prev;
    //list is reversed now
    return head;

}


void print(Node* head)
{
  
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->link;
    }
    cout<<"\n";
}


int main()
{   
    //head = NULL; //empty list, we used head directly because it's a global variable
    struct Node* head = NULL; //head is declared as a local variable
    cout<<"How many elements ? ";
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {   
        int x;
        cout<<"Enter Element : "<<i+1<<"\n";
        cin>>x;
        head = insert(head,x);
        
    }

   /* head = insert(head,2);
    head = insert(head,4);
    head = insert(head,6);
    head = insert(head,8);
    */ 
    cout<<"Before Reversing the linked list : "<<endl;
    print(head);
    
    cout<<"After Reversing the linked list : "<<endl;
    head = reverse(head);
    print(head);
}