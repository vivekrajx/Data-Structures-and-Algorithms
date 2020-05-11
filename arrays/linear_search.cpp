//ITERATIVE APPROACH

/*#include<iostream>
using namespace std;

int main(){
	
	int a[10], n, i, k;
	
	cout<<"Enter the no. of elements in the array : ";
	cin>>n;

	cout<<"Enter the elements of the array : "<<endl;
	for(i=0; i<=n-1; i++){
		cin>>a[i];
	}

	cout<<"Enter the element you want to search :";
	cin>>k;

	for(i=0; i<n-1; i++){
		if(a[i]==k){
			cout<<k<<" is found at index : "<<i<<endl;
			break;
		}
	}
	if(a[i]!=k){
		cout<<k <<" was not found";
	}
	

	return 0;

}

*/
//RECURSIVE APPROACH : 

#include<iostream>
using namespace std;

int linear_search(int a[], int n, int x)
{
	if(n<0)
		return -1;
	if(a[n]==x)
		return n;
	return linear_search(a, n-1, x);
}

int main(){
	
	int a[100], n, i, x;
	
	cout<<"Enter the no. of elements in the array : ";
	cin>>n;

	cout<<"Enter the elements of the array : "<<endl;
	for(i=0; i<=n-1; i++){
		cin>>a[i];
	}

	cout<<"Enter the element you want to search :";
	cin>>x;

	int found_index = linear_search(a,n,x);
	cout<<x<<" is found at index :"<<found_index;


	return 0;
}
