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

int main()
{   
    head = NULL; //empty list
    int n;
    cout<<"How many elements in linked list ? : ";
    cin>>n;
    int x, pos;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter element "<<i+1<<" and its position : \n";
        cin>>x>>pos;
        insert(x,pos);
    }
   /* insert(2,1); // LIST:2
    insert(3,2); //LIST :3
    insert(4,1); //LIST : 4,2,3
    insert(5,2); //LIST : 4,5,2,3
    */
    print();

}
