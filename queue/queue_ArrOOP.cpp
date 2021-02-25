//Queue Circular Array Implementation
#include<iostream>
using namespace std;

#define MAX_SIZE 101 //max size for array

//creating class queue
class Queue
{
    private:
    int A[MAX_SIZE];
    int front, rear;

    public:
    //constructor which sets front and rear to -1
    //for empty queue both front and rear is -1
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return(front == -1 && rear == -1);
    }

    bool isFull()
    {  //if rear == front
        return(rear+1)%MAX_SIZE == front ? true:false;
    }

    //enqueue function
    void Enqueue(int x)
    {
        cout<<"Enqueuing "<<x<<"\n";
        if(isFull())
        {
            cout<<"Error: Queue is full\n";
            return;
        }
        if(isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear+1)%MAX_SIZE; //or we can do rear=rear+1 only also
        }
        A[rear] = x;
    }

        //dequeue function
        void Dequeue()
        {
            cout<<"Dequeuing \n";
            if(isEmpty())
            {
                cout<<"Error: Queue is empty\n";
                return;
            }
            else if(front == rear)
            {   //only element in queue then
                rear = front = -1;
            }
            else
            {
                front = (front+1)%MAX_SIZE;
            }
        }

        //return front element of queue
        int Front()
        {
            if(front ==-1)
            {
                cout<<"Error: cannot return from empty queue..\n";
                return -1;
            }        
            return A[front];
        }

    void Print()
    {
    // Finding number of elements in queue
    int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
    cout<<"Queue: ";
    for(int i = 0; i <count; i++)
    {
    int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
    cout<<A[index]<<" ";
    }
    cout<<"\n\n";
    }
};

int main()
{
Queue Q; // creating an instance of Queue.
Q.Enqueue(2); Q.Print();
Q.Enqueue(4); Q.Print();
Q.Enqueue(6); Q.Print();
Q.Dequeue(); Q.Print();
Q.Enqueue(8); Q.Print();
}
