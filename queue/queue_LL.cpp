#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

//declated glboally
struct Node * front = NULL;
struct Node * rear = NULL; 

//Enqueue from front & Dequeue from rear both take O(1) time here.

//Enqueue from rear 
void Enqueue(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->link = NULL;

    //if queue is empty
    if(front == NULL and rear == NULL)
    {
        front = rear = temp; //set both front and rear as to temp
        return;
    }
    rear->link = temp; //build new link while enqueuing
    rear = temp; //update rear 
}

//Dequeue from front
void Dequeue()
{
    Node * temp = front; 
    // we created this temp ptr to node in which we store 
    //the addr of current head or current front

    //CASE 1: if queue is empty
    if(front == NULL) return;

    //CASE 2: only element in queue
    if(front == rear)
    {
        front = rear = NULL; //removed the only element in the queue
    }
    //CASE 3: all other cases
    else
    {
        front =  front->link;
    }

    free(temp); //since front was incr, leaving a prev front in mem we free it
}

void Print(){
    cout<<"Queue: ";  
    Node* current = front; // Initialize current  
    while (current != NULL)  
    {  
        cout<<current->data<<" ";
        current = current->link;  
    }  
    cout<<endl;
}

int Front(){
    return front->data; //return front element of queue
}

int Rear(){
    return rear->data; //return rear element of queue 
}

bool isEmpty(){
    if(front==NULL)
        return true;
    else
        return false;
}


int main(){
    Enqueue(2); Print();
    Enqueue(4); Print();
    Enqueue(6); Print();
    Dequeue(); Print();
    Dequeue(); Print();
    Dequeue(); Print();
    
}