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
    bool areAlmostEqual(string s1, string s2) {
        int sub[3], count = 0, len = s1.size();
        char buff[3];
        for(int i = 0; i < len && count < 3; i++){
            if(s1[i] != s2[i]){
                count ++;
                sub[count-1] = i;
                buff[count-1] = s1[i];
            }
        }
        if(count > 2)
            return false;
        else if(count == 1){
            for(int i = 0; i < len; i++){
                if(s1[i] == s2[sub[0]] && s2[i] == s1[sub[0]])
                    return true;
            }
            return false;
        }
        else if(count == 2){
            if(buff[0] != s2[sub[1]] || buff[1] != s2[sub[0]])
                return false;
        }
        return true;
    }
};