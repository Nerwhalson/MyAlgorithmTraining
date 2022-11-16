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
    bool isIdealPermutation(vector<int>& nums) {
        int len = nums.size(), min = len;
        for(int i = len-1; i > 1; i--){
            min = min > nums[i] ? nums[i] : min;
            if(nums[i-2] > min){
                return false;
            }
        }
        return true;
    }
};