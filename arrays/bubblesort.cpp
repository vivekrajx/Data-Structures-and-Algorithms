#include<iostream>
using namespace std;

void bubblesort(int a[], int n)
{
	for(int i=0; i<n-1; i++){

		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
	}

}


int main(){

	int a[100],n;
	cout<<"Enter the no. of elements in the array : ";
	cin>>n;

	cout<<"Enter the array elements :"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}

	bubblesort(a, n);
	for(int i=0; i<n; i++){

		cout<<a[i]<<" ";
	}
}