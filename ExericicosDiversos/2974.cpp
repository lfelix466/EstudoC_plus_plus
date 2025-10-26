#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        vector<int> arr;
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size(); i += 2)
        {
            arr.push_back(nums[i + 1]);
            arr.push_back(nums[i]);
        }

        return arr;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2,5};
    vector<int> arr = sol.numberGame(nums);

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ",";
    }
}
