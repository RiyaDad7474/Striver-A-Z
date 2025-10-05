#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int ind = -1;
        int n = A.size();

        // Step 1: Find the breakpoint
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no breakpoint, reverse array
        if (ind == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // Step 3: Find next greater element and swap
        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(A.begin() + ind + 1, A.end());
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};  // Example input
    cout << "Original: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
