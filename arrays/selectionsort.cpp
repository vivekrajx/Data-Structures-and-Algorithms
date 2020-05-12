#include<iostream>
using namespace std;

void selectionsort(int arr[], int n){

	for(int i=0; i<n-1; i++){

		int smallest_index = i;
		for(int j=i; j<=n-1; j++){
			if(arr[j]<arr[smallest_index])
				smallest_index=j;
		}
		swap(arr[i], arr[smallest_index]);

	}
	
}

int main(){

	int arr[100], n;
	cout<<"Enter the no. of elements in the array: ";
	cin>>n;

	cout<<"Enter array elements : "<<endl;
	for(int i=0; i<n; i++)
		cin>>arr[i];

	selectionsort(arr, n);
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";

	return 0;
}