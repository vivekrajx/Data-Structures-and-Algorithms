#include <bits/stdc++.h>
using namespace std;

//s is source or starting of bfs
bool checkforCycle(int s, int V, vector<int> adj[], vector<int> &visited)
{
  //create a queue for bfs
  //modified queue storing the node and prev or its parent
  queue<pair<int, int>> q;
  visited[s] = true;
  q.push({s, -1}); //initially source ka prev ya parent toh -1 hi hoga...
  while (!q.empty())
  {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        visited[it] = true;
        q.push({it, node});
      }
      else if (parent != it)
        return true; //adjacent node is already visited and parent is not equivalent to prev node so here we have a cycle...
    }
  }
  return false;
}

bool isCycle(int V, vector<int> adj[])
{
  vector<int> vis(V + 1, 0);
  for (int i = 1; i <= V; i++)
  {
    if (!vis[i])
    {
      if (checkforCycle(i, V, adj, vis))
        return true;
    }
  }
  return false;
}

vector<int> bfsofGraph(int V, vector<int> adj[])
{
  vector<int> bfs;
  vector<int> vis(V + 1, 0);

  for (int i = 1; i <= V; i++)
  {
    if (!vis[i])
    {
      queue<int> q;
      q.push(i);
      vis[i] = 1;
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
    }
  }
  return bfs;
}

void PrintGraph(int V, vector<int> adj[])
{
  vector<int> ans = bfsofGraph(V, adj);
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
  PrintGraph(n, adj);
  cout << endl;
  isCycle(n, adj) ? cout << "Cycle found" : cout << "Cycle not present";
  return 0;
}
