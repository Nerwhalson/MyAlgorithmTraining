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
    long long max_int = 2147483647;
    long long min_int = -2147483648;
    int myAtoi(string s) {
        int i = 0, len = s.size(), count = 0;
        long long ans = 0;
        bool neg = false;
        while(i < len && s[i] == ' ')
            i++;
        if(i < len && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-')
                neg = true;
            i++;
        }
        while(i < len && s[i] >= 48 && s[i] <=57 && count < 15){
            ans *= 10;
            ans += s[i] - 48;
            i++;
            if(ans != 0)
                count++;
        }
        if(neg){
            ans = -ans < min_int ? min_int : -ans;
        }
        else{
            ans = ans > max_int ? max_int : ans;
        }
        return ans;
    }
};