#include <bits/stdc++.h>
using namespace std;

void bfs(int source, vector<int> adj[], bool visited[], int N)
{
  queue<int> q;
  q.push(source);
  visited[source] = true;
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

void topologicalSort(vector<int> adj[], int N)
{
  //step 1 : store indegree of every vertex
  vector<int> in_degree(N, 0); //instead of indegree array we use vector
  for (int i = 0; i < N; i++)
  {
    for (int x : adj[i])
      in_degree[x]++; //since we have control over the edge creation fn
  }

  //step 2: create a queue q
  queue<int> q;
  for (int i = 0; i < N; i++)
    if (in_degree[i] == 0)
      q.push(i); //adding all zero indegree vertices to queue

  //step 3: looping..

  //step 3: looping
  /*
	   taking out a vertex from q and printing it
	   then we will reduce the indegree by 1 of adjacent 
	   vertiecs to which it has edges
	   and if indegree becomes zero, enequeu it
	   */
  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    cout << current << " ";

    for (int x : adj[current])
      if (--in_degree[x] == 0) //reduced indegree by 1
        q.push(x);
  }
}

void PrintAdjList(vector<int> adj[], int N)
{
  for (int i = 0; i < N; i++)
  {
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
    //bool visited[N];

    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      //adj[v].push_back(u);
    }
    /* cout << "printing adj list: \n";
    PrintAdjList(adj, N);
    cout << "bfs traversal : \n";
    bfs(0, adj, visited, N); */
    cout << "topological sorting : \n";
    topologicalSort(adj, N);
  }
}
