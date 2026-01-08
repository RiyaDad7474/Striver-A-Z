#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
  stack<pair<int, int>> st;
  StockSpanner()
  {
  }

  int next(int price)
  {
    int span = 1;
    while (!st.empty() && st.top().first <= price)
    {
      span = span + st.top().second;
      st.pop();
    }

    st.push({price, span});
    return span;
  }
};

int main()
{
  StockSpanner *obj = new StockSpanner();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int price;
    cin >> price;
    cout << obj->next(price) << endl;
  }
  return 0;
}