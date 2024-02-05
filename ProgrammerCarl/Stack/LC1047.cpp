#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char> buff1, buff2;
        for(auto i : s){
            buff1.push(i);
        }
        while(!buff1.empty()){
            if(buff2.empty() || buff2.top() != buff1.top()){
                buff2.push(buff1.top());
                buff1.pop();
            }
            else{
                buff1.pop();
                buff2.pop();
            }
        }
        while(!buff2.empty()){
            ans.push_back(buff2.top());
            buff2.pop();
        }
        return ans;
    }
};