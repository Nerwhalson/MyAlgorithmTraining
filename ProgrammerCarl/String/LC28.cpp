#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int *next = new int[needle.size()];
        // create the next array
        next[0] = 0;
        for(int i = 0, j = 1; j < needle.size(); j++){
            while(i > 0 && needle[i] != needle[j]){
                i = next[i - 1];
            }
            if(needle[i] == needle[j]){
                i++;
            }
            next[j] = i;
        }
        // using next array to compare the string
        for(int i = 0, j = 0; i < haystack.size(); i++){
            if(j == needle.size() - 1 && haystack[i] == needle[j]){
                return i - needle.size() + 1;
            }
            else if(j < needle.size() - 1 && haystack[i] == needle[j]){
                j++;
            }
            else if(j != 0){
                j = next[j - 1];
                i--;
            }
        }
        return -1;
    }
};

int main(){
    string str = "ababcaababcaabc";
    string sub = "ababcaabc";
    Solution run;
    cout << run.strStr(str, sub);

    return 0;
}
