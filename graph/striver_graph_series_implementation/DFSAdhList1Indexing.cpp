#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDFS)
{
  storeDFS.push_back(node);
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      //make recursive calls
      dfs(it, vis, adj, storeDFS);
    }
  }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
  vector<int> storeDFS; //vector of int storing dfs nodes
  vector<int> vis(V + 1, 0);
  for (int i = 1; i <= V; i++)
  {
    if (!vis[i])
    {
      dfs(i, vis, adj, storeDFS);
    }
  }
  return storeDFS;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> result = dfsOfGraph(n, adj);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
