#include<iostream>
using namespace std;


void insertionsort(int arr[], int n){

	for(int i=1; i<=n-1; i++){
		int current_element = arr[i];
		int j = i-1;
		//putting current element at right place in sorted order
		while(j>=0 & arr[j]>current_element){
			arr[j+1]=arr[j];
			j=j-1; // go on comparing
		}
		arr[j+1] = current_element;
	}


}

int main(){

	int arr[100], n;
	cout<<"Enter the no. of elements in array :";
	cin>>n;

	cout<<"Enter array elements : "<<endl;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	insertionsort(arr, n);
	cout<<"Array in sorted order : ";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";

}