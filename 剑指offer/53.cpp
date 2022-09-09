#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int bin_search(vector<int>& nums, int target, int start, int end){
        int sub = (start + end) / 2;
        if(nums[sub] == target)
            return sub;
        else if(start >= end-1)
            return -1;
        else
            if(nums[sub] > target)
                return bin_search(nums, target, start, sub);
            else
                return bin_search(nums, target, sub, end);
    }

    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int i, count = 0, sub = bin_search(nums, target, 0, nums.size()-1);
        cout << sub;
        int len = nums.size();
        if(sub == -1)
            return 0;
        for(i = sub; nums[i] == target && i < len; i++, count++);
        for(i = sub; nums[i] == target && i >= 0; i--, count++);
        count--;

        return count;
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
