#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int sub;
        while(start <= end){
            sub = (end + start) / 2;
            if(nums[sub] == target){
                return sub;
            }
            else if(nums[sub] > target){
                end = sub - 1;
            }
            else {
                start = sub + 1;
            }
        }
        return -1;
    }
};


int main(){
    Solution run;
    vector<int> arr;
    int target = 10;
    for(int i = 0; i < 10; i++){
        arr.push_back(i);
    }
    cout << run.search(arr, target);

    return 0;
}