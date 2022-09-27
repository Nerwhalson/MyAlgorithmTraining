#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        bool flag = false;
        int i, buff[14]{}, len = nums.size();
        for(i = 0; i < len; i++)
            buff[nums[i]]++;
        int zero, all = buff[0];
        if(all >= 4)
            return true;
        for(i = 1; i < 10 && !flag; i++){
            zero = all;
            flag = true;
            for(int j = 0, zero = all; j < 5; j++){
                if(buff[i+j] == 0)
                    zero--;
                if(buff[i+j] > 1 || zero < 0){
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};