#include<iostream>
#include<climits>
using namespace std;

int main(){

	int a[100],i, n;
	cout<<"Enter the no. of elements in the array : ";
	cin>>n;

	cout<<"Enter the elements of the array : "<<endl;
	for(i=0; i<=n-1; i++){
		cin>>a[i];
	}

	int largest = INT_MIN; // - infinity

	int smallest = INT_MAX; // + infinity 

	for(int i=0; i<n; i++){

		/*if(a[i]>largest)
			largest = a[i];

		if(a[i]<smallest)
			smallest = a[i];*/

		// we may also do it as below
		largest = max(largest, a[i]); // max of largest and the current no.
		smallest = min(smallest, a[i]); //min of smallest and the current no.
	}

	cout<<"the largest element is "<<largest<<endl;
	cout<<"the smallest element is "<<smallest<<endl;
	return 0;
}