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
    string customSortString(string order, string s) {
        int *hash = new int[26](), *num = new int[26]();
        int olen = order.size(), slen = s.size();
        string ans;
        for(int i = 0; i < slen; i++){
            num[s[i]-97]++;
        }
        for(int i = 0; i < olen; i++){
            hash[order[i]-97] = i+1;
            for(int j = 0; j < num[order[i]-97]; j++){
                ans.push_back(order[i]);
            }
        }
        for(int i = 0; i < slen; i++){
            if(hash[s[i]-97] == 0){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};