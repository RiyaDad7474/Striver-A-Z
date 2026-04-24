#include <bits/stdc++.h>
using namespace std;

struct item
{
  int value, weight;
};

bool comparator(item val1, item val2)
{
  if ((double)(val1.value / (double)val1.weight) >= ((double)val2.value / (double)val2.weight))
  {
    return true;
  }
  return false;
}

int fracKnapsack(vector<item> &items, int w)
{
  int n = items.size();
  sort(items.begin(), items.end(), comparator);

  double totalVal = 0.0;

  for (int i = 0; i < n; i++)
  {
    if (items[i].weight <= w)
    {
      totalVal += items[i].value;
      w = w - items[i].weight;
    }
    else
    {
      totalVal += ((double)(items[i].value) / (items[i].weight)) * w;
      break;
    }
  }
  return totalVal;
}

int main()
{
  vector<item> items = {{60, 10}, {100, 20}, {120, 30}};
  int w = 50;
  cout << fracKnapsack(items, w);
  return 0;
}
