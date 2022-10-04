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
    bool checkOnesSegment(string s) {
        int count = 1, pre = s[0], len = s.size();
        bool flag = false;
        for(int i = 1; i < len && count <= 1; i++){
            if(pre != s[i] && s[i] == '1')
                count++;
            pre = s[i];
        }
        return count <= 1 ? true : false;
    }
};