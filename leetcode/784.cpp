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
    vector<string> letterCasePermutation(string s) {
        int len = s.size();
        traverse(s, 0);
        return ans;
    }

    void traverse(string s, int i){
        if(i == s.size()){
            if(hash[s] == 0){
                ans.push_back(s);
                hash[s]++;
            }
            return;
        }
        traverse(s, i+1);
        if(s[i] >= 65 && s[i] <= 90){
            s[i] += 32;
        }
        else if(s[i] >= 97 && s[i] <= 122){
            s[i] -= 32;
        }
        traverse(s, i+1); 
    }
    unordered_map<string, int> hash;
    vector<string> ans;
};