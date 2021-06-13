#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  //in case of weights do : vector<pair<int,int>> adj[n+1];
  for (int i = 0; i < m; i++)
  {
    int u, v;            //in case of weight declare 3rd variable weight as well
    cin >> u >> v;       //in case of weight take its input as well
    adj[u].push_back(v); //in case of weight do: adj[u].push_back({v,weight});
    adj[v].push_back(u); //in case of weight do: adj[v].push_back({u,weight});
  }
  return 0;
}
