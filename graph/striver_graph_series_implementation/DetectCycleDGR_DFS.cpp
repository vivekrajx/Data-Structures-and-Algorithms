#include <iostream>
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
      dfs(it, vis, adj, storeDFS);
    }
  }
}

vector<int> dfsofGraph(int V, vector<int> adj[])
{
  vector<int> storeDFS;
  vector<int> vis(V + 1, 0); //1 based indexing
  for (int i = 1; i <= V; i++)
  {
    if (!vis[i])
    {
      dfs(i, vis, adj, storeDFS);
    }
  }
  return storeDFS;
}

bool checkForCycle(int node, vector<int> adj[], int vis[], int dfsVis[])
{
  vis[node] = 1;
  dfsVis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      if (checkForCycle(it, adj, vis, dfsVis))
        return true; //go deeper and check for cycle and return true if exists
    }
    else if (dfsVis[it])
    { //means if the node was visited in vis and also visited in dfsVis, there exists a cycle
      return true;
    }
  }
  dfsVis[node] = 0; //else make the visited unvisited in dfsVis and move back
  return false;
}

bool isCyclic(int V, vector<int> adj[])
{
  int vis[V], dfsVis[V];
  memset(vis, 0, sizeof vis);
  memset(dfsVis, 0, sizeof dfsVis);
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      if (checkForCycle(i, adj, vis, dfsVis))
      {
        return true;
      }
    }
  }
  return false;
}

void Print(int V, vector<int> adj[])
{
  vector<int> ans = dfsofGraph(V, adj);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
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
    //adj[v].push_back(u); //coz its a directed graph
  }
  //  dfsofGraph(n, adj);
  Print(n, adj);
  cout << endl;
  isCyclic(n, adj) ? cout << "Cycle detected" : cout << "Cycle not present";
  return 0;
}
