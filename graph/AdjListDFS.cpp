#include <bits/stdc++.h>
using namespace std;

void dfs(int source, vector<int> g[], bool *visited)
{
  //initially
  visited[source] = true;
  cout << source << " ";
  for (int i = 0; i < g[source].size(); ++i)
  {
    if (visited[g[source][i]] == false)
      dfs(g[source][i], g, visited);
  }
}

void PrintAdjList(vector<int> g[], int N)
{
  for (int i = 0; i < N; i++)
  {
    cout << "Vertex " << i << " is connected to: ";
    for (int x : g[i])
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
    vector<int> g[N];
    bool visited[N];
    //memset sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char)
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < E; ++i)
    {
      int u, v;
      cin >> u >> v;
      //use both of them for undirected graph else only first for directed
      g[u].push_back(v);
      //g[v].push_back(u);
    }
    cout << "Printing adjacency list: \n";
    PrintAdjList(g, N);
    cout << "DFS Traversal over graph: \n";
    dfs(0, g, visited);
    cout << endl;
  }
}
