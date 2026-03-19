#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

vector<int> getSieve()
{
  vector<int> prime(N + 1, 1);

  prime[0] = prime[1] = 0;

  // Sieve of Eratosthenes
  for (int i = 2; i * i <= N; i++)
  {
    if (prime[i] == 1)
    {
      for (int j = i * i; j <= N; j += i)
      {
        prime[j] = 0;
      }
    }
  }

  // Prefix sum (count of primes till i)

  for (int i = 2; i <= N; i++)
  {
    prime[i] = prime[i] + prime[i - 1];
  }
  return prime;
}

int main()
{
  vector<int> prime = getSieve();

  int q;
  cin >> q;

  while (q--)
  {
    int l, r;
    cin >> l >> r;

    int ans = prime[r] - prime[l - 1];
    cout << ans << endl;
  }
  return 0;
}