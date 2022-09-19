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
    string reverseWords(string s) {
        if(s.empty())
            return s;
        string ans = "";
        int i = s.size()-1, j = s.size()-1;
        while(j >= 0){
            if(i == j && s[i] == ' '){
                i--;
                j--;
            }
            else if(i == j && s[i] != ' '){
                i--;
            }
            else if(i < 0 && s[j] != ' '){
                for(int sub = i+1; sub <= j; sub++){
                    ans.push_back(s[sub]);
                }
                j = i;
            }
            else if(s[i] == ' '){
                for(int sub = i+1; sub <= j; sub++){
                    ans.push_back(s[sub]);
                }
                ans.push_back(' ');
                j = i;
            }
            else if(s[i] != ' '){
                i--;
            }
        }
        if(!ans.empty() && ans[ans.size()-1] == ' ')
            ans.pop_back();
        return ans;
    }
};

int main()
{
    Solution run;
    string s = "       ";
    cout << run.reverseWords(s);

    return 0;
}
