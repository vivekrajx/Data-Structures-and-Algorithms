#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int,int> p2){
	return p1.second < p2.second;
}

int main(){

	int n, start, finish;
	vector<pair<int,int> > activity_pair;
	cout<<"Enter the no. of activities : "<<endl;
	cin>>n;

	
	cout<<"Enter the starting and finishing time of activities : "<<endl;
	for(int i=0; i<n; i++){

		cin>>start>>finish;
		activity_pair.push_back(make_pair(start, finish));

	}
	
	//activity selection algorithm

	// step 1 :  sort a/q to finish time of activity
	sort(activity_pair.begin(), activity_pair.end(), compare);

	//activity 1 is selected by default
	int activities = 1;
	int fin = activity_pair[0].second; // finishing time of 1st activity

	//displaying first activity as it's selected 
	cout<<"The start and finish time of activities selected are : "<<endl;
	cout<<"Activity \t Start \t Finish"<<endl;
	cout<<"0 \t \t "<<activity_pair[0].first<<" \t "<<activity_pair[0].second<<endl;

	//iterating over remaining activities and displaying them 
	for(int i=1; i<n; i++){
		if(activity_pair[i].first>=fin){
			fin= activity_pair[i].second;
			activities++;
			cout<<i<<" \t \t "<<activity_pair[i].first<<" \t "<<activity_pair[i].second<<endl;
		}
}
	cout<<"Total activites selected : "<<activities<<endl;
	return 0;

}