#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
  vector<int> bfs;       //vector of int storing traversal nodes
  vector<int> vis(V, 0); //created vis array, marked false initially V+1, if 1 based indexing
  queue<int> q;          //if 1 based indexing put all this queue stuff inside for loop
  q.push(0);
  vis[0] = 1;
  /*   for (int i = 1; i <= V; i++)
  {
    if (!vis[i])
    {
      queue<int> q;
      q.push(i);
      vis[i] = 1;
      //put  while loop content here
    }
  } */
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        q.push(it);
        vis[it] = 1;
      }
    }
  }
  return bfs;
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
  vector<int> ans = bfsOfGraph(n, adj);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
}
