//ADJ LIST IMPLEMENTATION
#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool visited[], int N)
{
  queue<int> q;
  q.push(s);
  visited[s] = true;
  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    cout << current << " ";
    for (int i = 0; i < adj[current].size(); ++i)
    {
      if (visited[adj[current][i]] == false)
      {
        q.push(adj[current][i]);
        visited[adj[current][i]] = true;
      }
    }
  }
}

void PrintAdjList(vector<int> adj[], int N)
{
  for (int i = 0; i < N; i++)
  {
    cout << "Vertex " << i << " is connected to: ";
    for (int x : adj[i])
      cout << x << " ";
    cout << endl;
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int N, E;
    cin >> N >> E;
    vector<int> adj[N];
    bool visited[N] = {false};
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      //use both pushbacks for undirected graph and one of them for directed graph
      adj[u].push_back(v);
      //adj[v].push_back(u);
    }
    cout << "Printing the adjacency list : \n";
    PrintAdjList(adj, N);
    cout << "Traversing and Printing in BFS : \n";
    bfs(0, adj, visited, N);
    cout << endl;
  }
}
