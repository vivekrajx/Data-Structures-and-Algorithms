#include <bits/stdc++.h>
using namespace std;
//TIME COMPLEXITY: O(V+E)
//Recursive function to detect a cycle in directed graph
bool DFSRec(vector<int> adj[], int s, bool visited[], bool rec_stack[])
{
  visited[s] = true;   //mark source as visited initially
  rec_stack[s] = true; //mark it as true in recursive stack as well
  for (int u : adj[s]) //iterating for all the adjacent nodes of a given node
  {
    //if the adjacent node is not visited and re-pass in DFSRec function to mark it true and receive true overall
    if (visited[u] == false && DFSRec(adj, u, visited, rec_stack) == true)
      return true;
    //else if the adjacent node was already previously marked true, return true which means a cycle is detected at this point (backedge detection)
    else if (rec_stack[u] == true)
      return true;
  }
  rec_stack[s] = false; //when no adjacent edges are left to be marked mark the entry as F
  return false;         //cycle was not detected so exiting
}

bool DFS(vector<int> adj[], int v)
{
  bool visited[v] = {false};                          //initializing visited array of v vertices as false
  bool rec_stack[v] = {false};                        //initializing rec_stack array to track recursion as false
  for (int i = 0; i < v; ++i)                         //iterating over all the vertices...
    if (visited[i] == false)                          //if the ith node is not visited, i.e = false
      if (DFSRec(adj, i, visited, rec_stack) == true) //call dfsrec to get true
        return true;
  return false; //else return false if we get false from above dfsrec call overall
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
    for (int i = 0; i < e; ++i)
    {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
    }
    if (DFS(adj, v)) //calling DFS function by passing in adj[] array of vectors and number of vertices v in graph as arguments
      cout << "cycle is found";
    else
      cout << "no cycle found";
  }
  return 0;
}
