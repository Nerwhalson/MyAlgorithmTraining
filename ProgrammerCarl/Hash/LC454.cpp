#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;   

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum12;
        int count = 0;
        for(auto i : nums1){
            for(auto j : nums2){
                sum12.find(i+j) == sum12.end() ? sum12[i+j] = 0 : sum12[i+j] += 1;
                sum12[i+j]++;
            }
        }
        for(auto i : nums3){
            for(auto j : nums4){
                if(sum12.find(0 - i - j) != sum12.end())
                    count += sum12[0 - i - j];
            }
        }
        return count;
    }
};