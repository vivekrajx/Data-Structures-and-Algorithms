#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
	return a>b;
}


int main()
{

	int a[100], n, key;
	
	cout<<"Enter the no. of elments in the array: ";
	cin>>n;

	cout<<"Enter the array elements  :"<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	sort(a, a+n);
	cout<<"After Sorting in ascending order : "<<endl;
	for(int i=0; i<n; i++){

		cout<<a[i]<<" ";
	}

	sort(a, a+n, compare);
	cout<<"\nAfter Sorting in descending order : "<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}


}