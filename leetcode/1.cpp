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
        unordered_map<int, int> buff;
        int sub, len = nums.size();
        vector<int> ans;
        for(int i = 0; i < len; i++){
            buff[nums[i]] ++;
        }
        for(int i = 0; i < len; i++){
            sub = target - nums[i];
            if(sub != nums[i] && buff[sub] != 0){
                ans.push_back(i);
                break;
            }
            else if(sub == nums[i] && buff[sub] > 1){
                ans.push_back(i);
                break;
            }
        }
        for(int i = 0; i < len; i++){
            if(nums[i] == sub && i != ans[0]){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};