#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // int i = 0, len = s.size(), window;
        // bool flag = true;
        // for(window = len-1; window > -1 && flag; window--)
        // {
        //     for(i = 0; i + window < len; i++)
        //     {
        //         if(s[i] == s[i + window])
        //             flag = false;
        //     }
        // }

        // return window;
        int enu[26], len = s.size(), max = -1;
        for(int i = 0; i < 26; i++)
            enu[i] = -1;
        for(int i = 0; i < len; i++)
        {
            if(enu[s[i]-97] == -1)
                enu[s[i]-97] = i;
            else
                max = max < i - enu[s[i]-97] - 1 ? i - enu[s[i]-97] - 1 : max;
        }

        return max;
    }
};
