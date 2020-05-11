#include<iostream>
using namespace std;

int main(){


	int a[10] = {1,2,3};
	int n = sizeof(a)/sizeof(int);

	cout<<"The size of the array is: "<<sizeof(a)<<endl;
	cout<<"Enter the elements of the array : "<<endl;

	for(int i=0; i<n; i++){

		cin>>a[i];
	}

	cout<<"The elements of array you entered are as follows: ";
	for(int i=0; i<n; i++){
		cout<<a[i]<<",";
	}

}