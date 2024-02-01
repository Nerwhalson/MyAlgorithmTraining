#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        long long value = target;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size() - 1; i++){
            if(i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                continue;
            for(int j = 0; j < i; j++){
                if(i > 1 && nums[i] == nums[i - 1] && nums[i - 1] != nums[i - 2])
                    j = i - 1;
                else if(j > 0 && nums[j] == nums[j - 1])
                    continue;
                int left = i + 1, right = nums.size() - 1;
                while(left < right){
                    if(nums[j] == value - nums[left] - nums[right] - nums[i]){
                        ans.push_back({nums[j], nums[i], nums[left], nums[right], });
                        do{
                            left++;
                        }
                        while(left < right && nums[left] == nums[left-1]);
                    }
                    else{
                        value - nums[left] - nums[right] - nums[i] < nums[j] ? right-- : left++;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {-5,-5,-3,-1,0,2,4,5};
    Solution run;
    int target = -7;
    vector<vector<int>> ans = run.fourSum(nums, target);
    for(auto vec : ans){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
