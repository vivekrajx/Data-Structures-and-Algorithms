#include<iostream>
#include<algorithm>
using namespace std;

int main(){


	int n, k;

	cout<<"Enter the no. of elements in array : \n";
	cin>>n;

	int a[n];

	cout<<"Enter the array elements : \n";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	//works on sorted array
	sort(a, a+n);

	cout<<"Enter the desired sum : \n";
	cin>>k;

	int i=0;
	int j = n;
	cout<<"The pair/s which gives the desired sum "<<k<<" is/are : "<<endl;
	while(i<j){

		int current_sum = a[i] + a[j];
		if(current_sum > k){
			j--;
		}
		else if(current_sum < k){
			i++;
		}
		else if(current_sum == k){
			cout<<a[i]<< " and "<<a[j]<<endl;
			i++;
			j--;
		}
	}

	return 0;
}