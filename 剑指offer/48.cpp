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
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        else if(s.size() == 1)
            return 1;
        int left = 0, right = 1, len = s.size(), max_len = 1;
        unordered_map<char, int> buf;
        buf[s[0]]++;
        while(right < len)
        {
            buf[s[right]]++;
            if(buf[s[right]] > 1)
            {
                while(s[left] != s[right])
                {
                    buf[s[left]]--;
                    left++;
                }
                buf[s[left]]--;
                left++;
            }
            max_len = max_len > right-left+1 ? max_len : right-left+1;
            right++;
        }
        return max_len;
    }
};