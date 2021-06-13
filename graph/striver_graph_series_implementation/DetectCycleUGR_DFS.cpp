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

bool checkForCycle(int node, int parent, vector<int> &vis, vector<int> adj[])
{
  vis[node] = 1;
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      if (checkForCycle(it, node, vis, adj))
        return true; //if deeper returns true, return true
      else if (it != parent)
        return true; //actual condition to detect cycle...
      //if previosly visited node is not parent //parent k case mei chod dete h..
      //so a cycle is detected here...
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<int> vis(V + 1, 0); //1 based indexing
  for (int i = 0; i <= V; i++)
  {
    if (!vis[i])
    {
      if (checkForCycle(1, -1, vis, adj))
        return true;
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
    adj[v].push_back(u);
  }
  //  dfsofGraph(n, adj);
  Print(n, adj);
  cout << endl;
  isCycle(n, adj) ? cout << "Cycle detected" : cout << "Cycle not present";
  return 0;
}
