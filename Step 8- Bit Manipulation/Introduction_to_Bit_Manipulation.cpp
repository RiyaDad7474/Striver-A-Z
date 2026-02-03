#include <bits/stdc++.h>
using namespace std;

// string convertToBinary(int n)
// {
//   string res = "";
//   while (n > 0)
//   {
//     if (n % 2 == 1)
//     {
//       res = res + '1';
//     }
//     else
//     {
//       res += '0';
//     }
//     n = n / 2;
//   }
//   reverse(res.begin(), res.end());
//   return res;
// }

// int main()
// {
//   int n;
//   cin >> n;
//   cout << convertToBinary(n) << endl;
//   return 0;
// }

int convertToDecimal(string x)
{
  int len = x.length();
  int num = 0;
  int power = 1; // 2^0
  for (int i = len - 1; i >= 0; i--)
  {
    if (x[i] == '1')
    {
      num += power;
    }
    power = power * 2;
  }
  return num;
}

int main()
{
  string x;
  cin >> x;
  cout << convertToDecimal(x) << endl;
  return 0;
}