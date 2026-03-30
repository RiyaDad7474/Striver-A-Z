int subStr(string s, int k)
// {
//   int maxlen = 0;
//   int n = s.length();
//   unordered_map<char, int> mpp;

//   for (int i = 0; i < n; i++)
//   {
//     mpp.clear();
//     for (int j = i; j < n; j++)
//     {
//       mpp[s[j]]++;
//       if (mpp.size() <= k)
//       {
//         maxlen = max(maxlen, j - i + 1);
//       }
//       else
//         break;
//     }
//   }
//   return maxlen;
// }