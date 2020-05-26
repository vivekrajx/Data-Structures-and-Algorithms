#include<iostream>
using namespace std;

int main(){

	int a[1000] = {0};
	int currentSum =0;
	int maxSum=0;
	int n;
	cout<<"Enter the no. of elements in array : \n";
	cin>>n;

	cout<<"Enter the elements of the array : \n";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	//KADANE'S ALGO FOR MAX SUBARRAY SUM. 
	for(int i=0; i<n; i++)
	{
		if(currentSum < 0)
		{
			currentSum=0; // ignore -ve sum element
			
		} 
		currentSum = currentSum +a[i]; // updating current sum to the sum of prev currentsum + present array element

		maxSum = max(currentSum, maxSum); //updating the max sum
		
	}

	cout<<"The max sum is : "<<maxSum<<endl;
	
	return 0;

}