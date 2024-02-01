#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[i] + nums[right] == 0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    do{
                        left++;
                    }
                    while(left < right && nums[left] == nums[left-1]);
                }
                else{
                    nums[left] + nums[i] + nums[right] > 0 ? right-- : left++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution run;
    vector<vector<int>> ans = run.threeSum(nums);
    for(auto vec : ans){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
