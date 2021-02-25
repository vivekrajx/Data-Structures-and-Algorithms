#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

void Reverse(char *c, int n){

    stack<char> S;
    //loop for push 
    for(int i=0; i<n; i++)
        S.push(c[i]);
    
    //loop for pop
    for(int i=0; i<n; i++)
	{
        c[i] = S.top(); //overwrite the character at index i and pointing c[i] to top
        S.pop(); //performs pop
	}
}

int main(){

    char c[51];
    cout<<"Enter the string : ";
    cin.getline(c, 51);
	Reverse(c, strlen(c));
    cout<<"After reversing string : "<<c;
}       
