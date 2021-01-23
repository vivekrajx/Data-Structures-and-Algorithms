#include<iostream>
using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;   //both maximum size for the array and top of the array declared globally

void Push(int x){
    //handling overflow condition
    //(if stack of arrays is full we can't insert new elements)
    if(top == MAX_SIZE -1){
        cout<<"Error: Stack Overflow \n";
        return;
    }
    top++; //incrementing top whenever we push a element 
    A[top] = x; //top points to the element just pushed
    //or just A[++top] = x;
}

void Pop(){
    //handling underflow condition
    //(if stack is already empty, we can not pop anything)
    if(top == -1){
        cout<<"Error: Stack Underflow \n";
        return;
    }
    top--; //simply decrementing the top to point to element below it
}

int Top(){
    return A[top]; //just returns the element at top index
}

bool isEmpty(){
    if(top==-1)
        return true;
    else
        return false;
}

void Print(){
    cout<<"Stack: ";
    for(int i=0; i<=top; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main(){
    Push(2); Print();
    Push(5); Print();
    Push(10); Print();
    Pop(); Print();
    Push(12); Print();
}
