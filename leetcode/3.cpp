#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, max=0, head = 0, end = 0, len = s.length();
        for(; end < len; end++)
        {
            for(i = head; i < end; i++)
                if(s[i] == s[end])
                    head = i+1;
            max = max > end - head + 1 ? max : end - head + 1;
        }

        return max;
    }
};

int main()
{
    string s = "pwwkew";
    Solution run;
    cout << run.lengthOfLongestSubstring(s);

    return 0;
}