#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int min = 0;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            if(abs(nums[i]) < abs(nums[min]))
                min = i;
        ans.push_back(nums[min] * nums[min]);
        cout << min << " " << ans[0] << endl;
        int i = min - 1, j = min + 1;
        for(int sub = 1; sub < nums.size(); sub++){
            if(i < 0){
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
            else if(j == nums.size()){
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            else if(abs(nums[i]) <= abs(nums[j])){
                ans.push_back(nums[i] * nums[i]);
                i--;
            }
            else if(abs(nums[i]) > abs(nums[j])){
                ans.push_back(nums[j] * nums[j]);
                j++;
            }
        }
        return ans;
    }
};

int main(){
    Solution run;
    vector<int> arr = {-4,-1,0,3,10};
    arr = run.sortedSquares(arr);
    for(int i = 0; i < arr.size()   ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}