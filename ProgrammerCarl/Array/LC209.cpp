#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int window = 0, sum = 0;
        int min = nums.size() + 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            window ++;
            while(sum - nums[i - window + 1] >= target){
                sum -= nums[i - window + 1];
                window --;
            }
            if(sum >= target && window < min)
                min = window;
        }
        if(min == nums.size() + 1)
            min = 0;
        return min;
    }
};

int main(){
    Solution run;
    int target = 7;
    vector<int> arr = {2,3,1,2,4,3};
    cout << run.minSubArrayLen(target, arr);

    return 0;
}