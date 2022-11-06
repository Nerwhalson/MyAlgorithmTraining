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
    string interpret(string command) {
        int len = command.size();
        string ans;
        for(int i = 0; i < len; i++){
            if(command[i] == 'G'){
                ans.push_back('G');
            }
            else if(command[i] == '('){
                if(command[i+1] == ')'){
                    i++;
                    ans.push_back('o');
                }
                else{
                    i += 3;
                    ans.append("al");
                }
            }
        }
        return ans;
    }
};