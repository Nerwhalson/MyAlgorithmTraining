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
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() < 2)
            return nums;
        int i = 0, j = nums.size()-1, temp = nums[0];
        while(i < j){
            for(; nums[j] % 2 == 0 && i < j; j--);
            if(i == j)
                break;
            nums[i] = nums[j];
            i++;
            for(; nums[i] % 2 == 1 && i < j; i++);
            if(i == j)
                break;
            nums[j] = nums[i];
            j--;
        }
        nums[i] = temp;
        return nums;
    }
};