// CPP to generate subarrays
#include<iostream>
using namespace std;

int main(){

	int a[1000], n;
	int maxSum=0;
	int currentSum =0;
	int cumulative_Sum[1000] = {0};
	int left = -1;
	int right =-1;
	cout<<"Enter the size of the array : \n";
	cin>>n;
	cout<<"Enter the elements of the array: \n";

	cin>>a[0]; 
	cumulative_Sum[0] =a[0];
	for(int i=1; i<n; i++){
		cin>>a[i];
		cumulative_Sum[i] = cumulative_Sum[i-1]+a[i];
	}

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){

			//elements of the sub-array
			currentSum =0;
			currentSum = cumulative_Sum[j] - cumulative_Sum[i-1];
			
			//updating maxSum if currentSum > maxSum
			if(currentSum>maxSum){
				maxSum=currentSum;
				left=i;
				right=j;
			}

		}
	}
	cout<<"The max sum is : "<<maxSum<<endl;
	cout<<"The max subarray is : "<<endl;
	for(int k=left; k<=right; k++){
		cout<<a[k]<<" , ";
	}
	return 0;
}