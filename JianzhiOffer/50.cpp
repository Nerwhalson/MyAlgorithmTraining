#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        char ans = ' ';
        int *val = new int[26](), len = s.size();
        queue<char> word;
        for(int i = 0; i < len; i++)
        {
            val[s[i]-97]++;
            if(val[s[i]-97] == 1)
                word.push(s[i]);
        }
        while(!word.empty())
        {
            if(val[word.front()-97] == 1)
                break;
            else
                word.pop();
        }
        if(!word.empty())
            ans = word.front();
        return ans;
    }
};