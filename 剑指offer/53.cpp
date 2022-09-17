#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int bin_search(vector<int>& nums, int target, bool large){
        int mid, ans = nums.size(), left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(large)
                if(nums[mid] > target)
                {
                    right = mid - 1;
                    ans = mid;
                }
                else
                    left = mid + 1;
            else
                if(nums[mid] >= target)
                {
                    right = mid -1;
                    ans = mid;
                }
                else
                    left = mid + 1;
        }

        return ans;
    }

    int search(vector<int>& nums, int target) {
        int left = bin_search(nums, target, false), right = bin_search(nums, target, true) - 1;
        int ans = 0;
        if(left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
            ans = right - left + 1;

        return ans;
    }

};

int main()
{
    vector<int> q = {5,7,7,8,8,10};
    int target = 8;
    Solution run;
    cout << run.search(q, target);

    return 0;
}
