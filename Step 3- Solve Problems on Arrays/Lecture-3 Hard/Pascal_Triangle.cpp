#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> generate(int N)
// {
//   vector<vector<int>> ans;
//   for (int i = 1; i <= N; i++)
//   {
//     long long ans = 1;
//     vector<int> ansRow;
//     ansRow.push_back(1);
//     for (int col = 1; col < row; col++)
//     {
//       ans = ans * (row - col);
//       ans = ans / col;
//       ansRow.push_back(ans);
//     }
//     return ansRow;
//     ans.push_back(ansRow);
//   }
//   return ans;
// }

vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> triangle;

  for (int row = 0; row < numRows; row++)
  {
    vector<int> ansRow(row + 1, 1); // initialize row with 1s
    for (int col = 1; col < row; col++)
    {
      ansRow[col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
    }
    triangle.push_back(ansRow);
  }
  return triangle;
}

int main()
{
  int n = 5;
  vector<vector<int>> res = generate(n);

  // Print Pascal's Triangle
  for (auto &row : res)
  {
    for (int x : row)
      cout << x << " ";
    cout << "\n";
  }
  return 0;
}