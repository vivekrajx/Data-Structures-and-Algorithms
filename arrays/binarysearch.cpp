#include<iostream>
using namespace std;

// WORKS EFFICIENTLY ON A SORTED ARRAY, SO TRY ENTERING A SORTED ARRAY
int binarySearch(int a[], int n, int key){

	int start = 0;
	int end = n-1;

	while(start<=end){
		int mid_element = (start+end)/2;

		if(a[mid_element]==key)
			return mid_element;

		else if(a[mid_element]>key)
			end = mid_element-1;

		else
			start = mid_element+1;
}
	return -1;
}
int main(){


	int a[100], n, key;
	cout<<"Enter the no. of elements in array : ";
	cin>>n;

	for(int i=0; i<=n-1; i++){

		cin>>a[i];
	}

	cout<<"Enter the element to search for : ";
	cin>>key;

	cout<<key<<" was found at index : "<<binarySearch(a, n, key);

	return 0;
}