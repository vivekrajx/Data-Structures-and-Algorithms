#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

struct Node* head; //head is globally declared here

void insert(int data, int n){
    //basic things
    Node* temp1 = new Node(); //node created
    temp1->data = data; //data inserted in newly created node
    temp1->link = NULL; //link is null 

    //handling special cases like (inserting at 1st pos, or inserting at end)
    //inserting at the beginning 
    if(n==1){
        temp1->link = head;
        head = temp1;
        return; 
    }
    //for all other cases, we need to go to n-1th node and make adjustments
    Node* temp2 = head; //start at head
    for(int i=1; i<n-1; i++){ //n-2 because we start from head
        temp2 = temp2->link; //traverse and pt temp2 to n-1th node
    }
    //now to rearrange connecitons.. newly created node ka link ab usko point krega
    //jisko n-1th node pehle kr rha tha...
    //ek taraf se conn ho gaya 
    //ab n-1th node ko newly created node pe point krado..so beech mei aa gya naya node!!
    temp1->link = temp2->link;
    temp2->link = temp1; //adjust the link of n-1th node to point to newly created node
}

void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<"\n"; 
}

void Delete(int n)
{   
    Node* temp1 = head;
    //case 1 : deleting head or first node
    if(n==1){
        head = temp1->link; //head now points to the second node
        free(temp1);
        return;
    }

    //int n;
    for(int i=1; i<n-1; i++){ //alt for(int i=0; i<n-2; i++)
        temp1 = temp1->link;         
    }
    //temp1 points to n-1th node as of now

    Node* temp2 = temp1->link; //pointing to nth node from temp1 which is at n-1th node
    //now fixing the links
    //we would have to set link of n-1th node to point to n+1th node.
    temp1->link = temp2->link; //(n+1th node) //link is fixed now
    //since temp2 was storing the nth node, the node to be deleted, time to delete it!
    free(temp2); //delete temp2

    //what if n+1 th node is NULL? THINK!
}

int main()
{
    head = NULL; //empty list
    insert(2,1); // LIST:2
    insert(3,2); //LIST :3
    insert(4,1); //LIST : 4,2,3
    insert(5,2); //LIST : 4,5,2,3

    print();
    int n;
    cout<<"Enter a position :";
    cin>>n;
    Delete(n);
    print();

}
