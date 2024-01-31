#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool hash[1001] = {false};
        vector<int> ans;
        for(auto i : nums1)
            hash[i] = true;
        for(auto i : nums2)
            if(hash[i]){
                ans.push_back(i);
                hash[i] = false;
            }
        return ans;
    }
};