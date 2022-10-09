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
    int scoreOfParentheses(string s) {
        int curr = 0, len = s.size();
        stack<int> buff;
        for(int i = 0; i < len; i++){
            if(s[i] == '(')
                buff.push(-1);
            else{
                if(buff.top() == -1){
                    buff.pop();
                    buff.push(1);
                }
                else{
                    while(buff.top() != -1){
                        curr += buff.top();
                        buff.pop();
                    }
                    buff.pop();
                    buff.push(curr * 2);
                    curr = 0;
                }
            }
        }
        while(!buff.empty()){
            curr += buff.top();
            buff.pop();
        }
        return curr;    
    }
};