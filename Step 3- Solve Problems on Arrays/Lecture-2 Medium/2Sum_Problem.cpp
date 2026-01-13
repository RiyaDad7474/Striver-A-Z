#include <iostream>
#include <map>
#include <vector>
using namespace std;

pair<int, int> read(int n, vector<int> book, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = book[i];
        int more = target - a;
        if (mpp.find(more) != mpp.end())
        {
            return {mpp[more], i};
        }
        mpp[a] = i;
    }
    return {-1, -1};
}
int main()
{
    vector<int> book = {2, 7, 11, 15};
    int target = 9;
    int n = book.size();

    pair<int, int> ans = read(n, book, target);
    if (ans.first != -1)
    {
        cout << "Indices: " << ans.first << ", " << ans.second << endl;
    }
    else
    {
        cout << "No pair found!" << endl;
    }

    return 0;
}