#include <bits/stdc++.h>
using namespace std;

bool DFSRec(vector<int> adj[], int s, bool visited[], int parent)
{
  visited[s] = true;
  for (int u : adj[s])
  {
    if (visited[u] == false)
    {
      if (DFSRec(adj, u, visited, s) == true)
        return true;
    }
    else if (u != parent)
      return true; //cycle detected
    /*
    as if a vertex is adjacent & visited
    & it is not parent then we say that
    a cycle is present else no cycle is
    present.
    */
  }
  return false; //after all iterations if cycle is not present in graph
}

bool DFS(vector<int> adj[], int v)
{
  bool visited[v] = {false};
  for (int i = 0; i < v; i++)
  {
    if (visited[i] == false)
      if (DFSRec(adj, i, visited, -1) == true) //passed -1 as parent of first node
        return true;
  }
  return false;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
    }
    if (DFS(adj, v))
      cout << "cycle is found";
    else
      cout << "no cycle found";
  }
  return 0;
}
