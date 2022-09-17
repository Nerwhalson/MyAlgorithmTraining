#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0], curr = nums[0], len = nums.size();
        for(int i = 1; i < len; i++)
        {
            curr = curr + nums[i] > nums[i] ? curr + nums[i] : nums[i];
            if(curr > max)
                max = curr;
        }
        return max;
    }
};

int main()
{
    Solution run;

    return 0;
}