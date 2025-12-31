#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int> &a)
{
  vector<int> st;

  for (int i = 0; i < a.size(); i++)
  {

    while (!st.empty() && st.back() > 0 && a[i] < 0)
    {

      if (st.back() < -a[i])
      {
        st.pop_back(); // stack asteroid destroyed
        continue;
      }
      else if (st.back() == -a[i])
      {
        st.pop_back(); // both destroyed
      }

      a[i] = 0; // current asteroid destroyed
      break;
    }

    if (a[i] != 0)
      st.push_back(a[i]);
  }

  return st;
}
int main()
{
  vector<int> asteroids = {5, 10, -5};
  vector<int> result = asteroidCollision(asteroids);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}