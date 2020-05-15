#include<iostream>
using namespace std;

int partition(int *a, int start, int end){

	int i= start-1;
	int j = start;
	int pivot = a[end]; // here we choose end element as pivot

	for(; j<end; j++){
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	//now bring pivot element to its sorted place
	swap(a[i+1],a[end]);
	return i+1; // returning pivot

}



void quick_sort(int *a, int start, int end){
	//if there is only one or no element in array --> don't sort, as it's not required
		if(start>=end)
			return;

		int pivot = partition(a,start,end);
		quick_sort(a,start, pivot-1);
		quick_sort(a, pivot+1, end);


}




int main(){

	int a[100], n;
	cout<<"Enter the no. of elements in array : ";
	cin>>n;

	cout<<"Enter the array elements : "<<endl;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	quick_sort(a, 0, n-1);
	cout<<"After sorting by quick sort we have : "<<endl;

	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}

	return 0;
}