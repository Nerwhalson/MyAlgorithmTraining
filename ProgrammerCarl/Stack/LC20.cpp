#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> buff;
        for(auto i : s){
            if(i == '(' || i == '[' || i == '{')
                buff.push(i);
            else{
                if(buff.empty())
                    return false;
                switch(i){
                    case ')':
                        if(buff.top() == '(')
                            buff.pop();
                        else
                            return false;
                        break;
                    case ']':
                        if(buff.top() == '[')
                            buff.pop();
                        else
                            return false;
                        break;
                    case '}':
                        if(buff.top() == '{')
                            buff.pop();
                        else
                            return false;
                        break;
                }
            }
        }
        if(buff.empty())
            return true;
        else
            return false;
    }
};