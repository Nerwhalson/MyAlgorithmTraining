#include <String>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for(int i = 0; i < s.size(); i++)
            arr[s[i] - 97]++;
        for(int i = 0; i < t.size(); i++)
            arr[t[i] - 97]--;
        for(int i = 0; i < 26; i++)
            if(arr[i] != 0)
                return false;
        return true;
    }
};