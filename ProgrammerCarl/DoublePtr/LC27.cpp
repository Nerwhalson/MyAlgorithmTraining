#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        char j = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[j] = nums[i];
            j += (nums[i] != val);
        }
        return j;
    }
};