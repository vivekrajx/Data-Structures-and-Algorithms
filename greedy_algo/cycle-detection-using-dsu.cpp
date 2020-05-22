// How to give inputs?
/*  It takes two inputs on first line specifying how many vertice pairs(edges) are provided to check for cycle
/* example executions:
4 4 // 4 inputs each of two vertices that form an edge
1 4 
2 3
1 2
4 3
This edge will give a cycle
Cycle in the graph!

Ex: 2 

5 5
1 2
4 3
1 4
2 3
This edge will give a cycle
1 3
This edge will give a cycle
Cycle in the graph!

*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct dsu
{
	vector<int> par,sz;
	int total_comp;
	//initalize 
	void init(int n){
		par.resize(n);
		sz.resize(n);
		for(int i=0; i<n; i++)
			par[i] = i;
		for(int i=0; i<n; i++)
			sz[i]=1;
		int total_comp = n;
	}

	int get_superparent(int x){
		if(x==par[x]){
			return x;
		}
		else{
			return par[x] = get_superparent(par[x]);
		}
	}

void unite(int x, int y){

	int super_parent_x = get_superparent(x);
	int super_parent_y = get_superparent(y);
	if(super_parent_x!= super_parent_y)
	{
		par[super_parent_x]= super_parent_y;
		sz[super_parent_y] += sz[super_parent_x];
		sz[super_parent_x] = 0;
		total_comp--;
		}
	}
} G;





void solve(){
	int i,j,k,n,m, ans=0, cnt=0, sum=0;
	cin>>n>>m;
	dsu G;
	G.init(n); //0 ->n-1 //init by n bcoz side should be n
	
	bool cycle = 0;
	for(i=0; i<m; i++){
		int x,y;

		cin>>x>>y; //storing only edges and no input
		// input being taken as 1 based index (1-2),(2-3) and so on...
		x--; y--; //all edges made as 1 based index .. 2 to 1 , 1 to 0 etc.
		
		if(G.get_superparent(x)!= G.get_superparent(y)){

			//different component

			G.unite(x,y);
		}
		else{
			//same component
			//there was a path from x to y
			cycle =1;
			cout<<"This edge will give a cycle\n";
		}
		
	}
	if(cycle) cout<<"Cycle in the graph! \n";
	else cout<<"No cycle in the graph\n";
}



int main(){


	solve();
	return 0;

}