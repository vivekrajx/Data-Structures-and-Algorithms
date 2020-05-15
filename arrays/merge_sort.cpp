#include<iostream>
using namespace std;

void merge(int *a, int start, int end){

	int mid = (start+end)/2;

	int i = start;
	int j = mid+1;
	int k = start; // k points to start of temp array in which we put elements after comparison

	//declaring a temporary array in which we store the elements upon comparison and k points to its start
	int temp[100];

	while(i<=mid && j<=end){

		if(a[i]<a[j])
			temp[k++]=a[i++]; // if a[i] is less than a[j] we put a[i] in temp array and increment
							  // the i and k respectively.
		else
			temp[k++]=a[j++];
	}

	//now if an array is exhausted we also copy the remaining elements to temp array
	while(i<=mid){
		temp[k++]=a[i++];
	}

	while(j<=end){
		temp[k++]=a[j++];
	}

	//Finally, we need to copy all elements from sorted temp array to our original array

	for(int i=start; i<=end; i++){
		a[i]=temp[i];
	}
}


void merge_sort(int a[], int start, int end){

	//base case, checking if 1 or 0 elements

	if(start>=end)
		return;

	//3 Steps : 1. Divide 2. Recursively sorting two arrays 3. Merging two arrays

	//Step 1 : Dividing the array
	int mid = (start+end)/2;

	//Step 2: Recursively sorting the two arrays : [start,mid] and [mid+1,end]

	merge_sort(a,start,mid);
	merge_sort(a,mid+1,end);

	//Step 3: Merging the two arrays 
	// here merge function is called which is defined above already separately
	merge(a,start,end);

}


int main(){

	int a[100], n;
	cout<<"Enter the no. of elements in the array :";
	cin>>n;

	cout<<"Enter the array elements : "<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	merge_sort(a,0,n-1); //we call merge_sort function, starting point is '0th' index & ending is 'n-1th' index in array

	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}