#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans;
        int i, len = s.size();
        for(i = n; i < len; ++i)
            ans.push_back(s[i]);
        for(i = 0; i < n; ++i)
            ans.push_back(s[i]);

        return ans;
    }
};