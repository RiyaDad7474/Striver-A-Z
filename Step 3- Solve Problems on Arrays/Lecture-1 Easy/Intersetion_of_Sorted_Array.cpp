#include <iostream>
using namespace std;
#include <vector>

vector<int> findArrayIntersection(vector<int> &A, int n,
                                  vector<int> &B, int m)
{
    vector<int> ans;
    int vis[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i] == B[j] && vis[j] == 0)
            {
                ans.push_back(A[i]);
                vis[j] = 1;
                break;
            }

            if (B[j] > A[i])
                break;
        }
    }
    return ans;

    // optimal approach

    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if(B[j] < A[i]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 2, 2, 3, 4};
    vector<int> B = {2, 2, 3, 5};
    int n = A.size();
    int m = B.size();

    vector<int> result = findArrayIntersection(A, n, B, m);

    cout << "Intersection: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}