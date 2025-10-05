#include <iostream>
using namespace std;
#include <vector>

vector<int> moveZeros(int n, vector<int> a)
{
//bruteforce approach
    // step-1
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }

    // step-2
    int nz = temp.size();
    for (int i = 0; i < nz; i++)
    {
        a[i] = temp[i];
    }

    // step-3
    for (int i = nz; i < n; i++)
    {
        a[i] = 0;
    }
    return a;
}



    //optimal approach

    // int j = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] == 0)
    //     {
    //         j = i;
    //         break;
    //     }
    // }
    // // no non zero numbers
    // if (j == -1)
    //     return a;

    // for (int i = j + 1; i < n; i++)
    // {
    //     if (a[i] != 0)
    //     {
    //         swap(a[i], a[j]);
    //         j++;
    //     }
    // }
    // return a;

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    int n = arr.size();

    vector<int> result = moveZeros(n, arr);

    cout << "Array after moving zeros: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}