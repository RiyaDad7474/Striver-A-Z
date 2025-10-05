#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Check if current element is greater than the next (with wrap-around)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
                if (count > 1)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    if (sol.check(nums))
        cout << "The array is sorted and rotated." << endl;
    else
        cout << "The array is NOT sorted and rotated." << endl;

    return 0;
}
