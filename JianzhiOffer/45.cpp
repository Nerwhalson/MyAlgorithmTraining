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
    string minNumber(vector<int>& nums) {
        vector<string> buff;
        int len = nums.size();
        for(int i = 0; i < len; i++)
            buff.push_back(to_string(nums[i]));
        string_sort(buff, 0, len-1);
        string ans = "";
        for(int i = 0; i < len; i++)
            ans += buff[i];
        return ans;        
    }

    void string_sort(vector<string>& list, int begin, int end){
        if(begin >= end)
            return;
        int i = begin, j = end;
        string temp, pivot = list[begin];
        while(i < j){
            while(i < j && pivot+list[j] <= list[j]+pivot){
                j--;
            }
            while(i < j && pivot+list[i] >= list[i]+pivot){
                i++;
            }
            if(i < j){
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        list[begin] = list[i];
        list[i] = pivot;
        string_sort(list, begin, i-1);
        string_sort(list, i+1, end);
    }
};