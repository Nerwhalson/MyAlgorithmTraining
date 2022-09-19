#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int ans, len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            map[nums[i]] += 1;
            if(map[nums[i]] > 1)
                return nums[i];
        }
        return -1;
    }
};