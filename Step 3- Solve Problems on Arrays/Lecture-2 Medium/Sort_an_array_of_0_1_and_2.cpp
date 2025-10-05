#include <iostream>
#include <vector>
using namespace std;

// Dutch National Flag algorithm for sorting an array of 0s, 1s, and 2s.
int sortArray(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return 1;
}
int main(){
    vector<int> arr = {0,1,0,1,1,1,2,0,2,1,2};
    int n = arr.size();
 int result;
      result = sortArray(arr,n);
      cout << "Return value: " << result << endl;

    cout << "Sorted array: ";

      for(int i = 0;i<n;i++){
        cout<<arr[i] << " ";
      } 
      cout<<endl;

    return 0;
}