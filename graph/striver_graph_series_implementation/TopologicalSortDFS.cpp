#include <bits/stdc++.h>
using namespace std;

//Topological Sort is always done on DAG
//it is the linear ordering of vertices such that if there is an edge u->v ,
//u appears before v in that ordering

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
  vis[node] = 1; //initially jo node aya marked it visited
  //now will check for its adjacent nodes
  for (auto it : adj[node])
  {
    if (!vis[it])
    {
      findTopoSort(it, vis, st, adj);
    }
  }
  st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
  stack<int> st;
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++)
  {
    if (!vis[i])
    {
      findTopoSort(i, vis, st, adj);
    }
  }
  vector<int> topoSortResult;
  while (!st.empty())
  {
    topoSortResult.push_back(st.top());
    st.pop();
  }
  return topoSortResult;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); //DAG
  }
  vector<int> topoSortResult = topoSort(n, adj);
  for (auto it : topoSortResult)
  {
    cout << it << " ";
  }
  return 0;
}
