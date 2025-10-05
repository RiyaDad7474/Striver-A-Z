void explainUnorderedMap()
{
  // same as set and unordered_Set difference.
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.second < p2.second)
  {
    return true;
  }
  else if (p1.second == p2.second)
  {
    if (p1.first > p2.second)
      return true;
  }
  return false;
}

void explainExtra()
{

  sort(a + 2, a + 4);

  sort(a, a + n, greater<int>);

  pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

  // sort it according to second element
  //  if second element is same, then sort
  //  it according to first element but in descending

  sort(a, a + n, comp);

  // {4,1}, {2,1}, {1,2};

  int num = 7;
  int cnt = _builtin_popcount();

  long long num = 165786578687;
  int cnt = _builtin_popcountll();

  string s = "123";

  do
  {
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));

  int maxi = *max_element(a, a + n);
}

int main()
{
  return 0;
}