#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool arePairs(char opening, char closing){
    if(opening == '(' and closing == ')') return true;
    else if(opening == '{' and closing == '}' )return true;
    else if(opening == '[' and closing == ']') return true;
    return false;
}
// TODO  fix more code

bool CheckBalancedParantheses(string exp){

    stack<char> S;
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i] == '[')
            S.push(exp[i]); //agr opening symbol h toh push to stack
        else if(exp[i]==')' || exp[i]=='}' || exp[i] == ']')
        {   
            //jb closing symbol aaye toh check whether the opening symbol at
            //top of stack is of same type as closing symbol and then pop
            //or say that it should be the closing symbol for the last opened symbol
            if(S.empty() || !arePairs(S.top(), exp[i]))
                return false; //not balanced
            else
                S.pop(); //balanced
        }
    }   
    return S.empty() ? true:false; 
}

int main(){
    string expression;
    cout<<"Enter an expression : ";
    cin>>expression;
    if(CheckBalancedParantheses(expression))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not balanced"<<endl; 
}
