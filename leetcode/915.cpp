#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        int *rmin = new int[len], max = 0;
        rmin[len-1] = nums[len-1];
        for(int i = len-2; i >= 0; i--)
            rmin[i] = rmin[i+1] < nums[i] ? rmin[i+1] : nums[i];
        for(int i = 0; i < len-1; i++){
            max = max < nums[i] ? nums[i] : max;
            if(max <= rmin[i+1])
                return i+1;
        }
        return len-2;
    }
};