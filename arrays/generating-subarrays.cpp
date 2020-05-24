// CPP to generate subarrays
#include<iostream>
using namespace std;

int main(){

	int a[1000], n;
	cout<<"Enter the size of the array : \n";
	cin>>n;
	cout<<"Enter the elements of the array: \n";

	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<endl;
	cout<<"The sub-arrays generated are as follows : \n";
	//Printing the sub-arrays 
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){

			//elements of the sub-array
			for(int k=i; k<=j; k++){	//ITERATE

				cout<<a[k]<<",";
			}
			cout<<"\n";
		}
	}

	return 0;
}