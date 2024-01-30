#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            nums[j] = nums[i];
            j += (nums[i] != val);
        }
        return j;
    }
};

int main(){
    Solution run;
    vector<int> arr = {3, 3, 3, 1};
    int len, target = 3;
    len = run.removeElement(arr, target);
    cout << len << endl;
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    return 0;
}