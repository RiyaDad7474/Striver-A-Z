#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, vector<int> &color, bool graph[101][101], int n, int col)
{
  for (int k = 0; k < n; k++)
  {
    if (k != node && graph[k][node] == 1 && color[k] == col)
      return false;
  }
  return true;
}

bool solve(int node, vector<int> &color, int m, int N, bool graph[101][101])
{
  if (node == N)
    return true;

  for (int i = 1; i <= m; i++)
  {
    if (isSafe(node, color, graph, N, i))
    {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph))
        return true;
      color[node] = 0;
    }
  }
  return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
  vector<int> color(N, 0);
  return solve(0, color, m, N, graph);
}

int main()
{
  int n, m;
  cin >> n >> m;

  bool graph[101][101];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> graph[i][j];

  if (graphColoring(graph, m, n))
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
