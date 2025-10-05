#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count, maxi;
        count = 0;
        maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
                maxi = max(maxi, count);
            }
            else
            {
                count = 0;
            }
        }
        return maxi;
    }
};

int main()
{
    vector<int> nums = {1, 1, 0, 1, 0, 0, 0, 1};
    Solution sol;
    int result = sol.findMaxConsecutiveOnes(nums);
    cout << result;
    return 0;
}