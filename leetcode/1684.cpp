#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int* allowed_hash = new int[26]();
        int len_a = allowed.size(), len_w = words.size(), ans = 0;
        bool flag = true;
        for(int i = 0; i < len_a; i++){
            allowed_hash[allowed[i]-97] = 1;
        }
        for(int i = 0; i < len_w; i++){
            for(int j = 0, len = words[i].size(); j < len; j++){
                if(allowed_hash[words[i][j]-97] == 0)
                    flag = false;
            }
            if(flag)
                ans++;
            flag = true;
        }
        return ans;
    }
};