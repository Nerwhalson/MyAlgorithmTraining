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
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1, tot;
        while(i < j){
            tot = nums[i] + nums[j];
            if(tot > target)
                j--;
            else if(tot < target)
                i++;
            else
                break;
        }
        return {nums[i], nums[j]};
    }
};