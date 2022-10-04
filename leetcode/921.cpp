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
    int minAddToMakeValid(string s) {
        int count = 0, len = s.size(), left = 0;
        for(int i = 0; i < len; i++){
            if(s[i] == '(')
                left++;
            else
                if(left > 0)
                    left--;
                else
                    count++;
        }
        count += left;
        return count;
    }
};