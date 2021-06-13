#include <bits/stdc++.h>
using namespace std;
//Kahn's algorithm
//can be done through DFS as well, better approach!
bool isCyclic(int V, vector<int> adj[])
{
  queue<int> q;
  vector<int> indegree(V, 0); //0 BASED INDEXING
  for (int i = 0; i < V; i++)
  {
    for (auto it : adj[i])
    {
      indegree[it]++; //if a node is incoming to adj node indegree incr by 1
    }
  }

  //now pushing all the nodes to q with indegree 0
  for (int i = 0; i < V; i++)
  {
    if (indegree[i] == 0)
    {
      q.push(i);
    }
  }

  //toposort
  //vector<int> topoSortResult;
  int count = 0;
  while (!q.empty())
  { //bfs basically implemented here..
    int node = q.front();
    q.pop();
    count += 1;
    //topoSortResult.push_back(node);
    for (auto it : adj[node])
    {
      //traverse all the nodes and subtract indegree of all adj nodes
      indegree[it]--;
      if (indegree[it] == 0)
      {
        q.push(it);
      }
    }
  }
  if (count == V)
    return false;
  else
    return true;
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<int> adj[n];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  // vector<int> topoSortResult = topoSort(n, adj);
  // for (auto it : topoSortResult)
  // {
  //   cout << it << " ";
  // }
  isCyclic(n, adj) ? cout << "Cycle detected" : cout << "Cycle not detected";
  return 0;
}
