#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int len = s.size();
        string ans;
        for(int i = 0; i < len; ++i)
        {
            if(s[i] != ' ')
                ans.push_back(s[i]);
            else
            {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
        }

        return ans;
    }
};