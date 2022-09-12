#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, len = nums.size(), i = nums[len-1]+1;
        while(i >= 0)
        {
            --i;
            while(len-count > 0 && nums[len-count-1] == i)
                ++count;
            if(i == count)
                break;

        }

        return i;
    }
};