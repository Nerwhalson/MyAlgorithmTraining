#include <String>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string re = "";
        int i, j, len = 0;
        bool start = false;
        for(i = s.size() - 1, j = s.size() - 1; i >= 0; i--){
            if(!start && s[i] != ' '){
                start = true;
                j = i;
            }
            else if(!start){
                j--;
            }
            else if(start && s[i] == ' '){
                re += s.substr(i + 1, j - i) + ' ';
                j = i;
                start = false;
            }
        }
        if(start){
            re += s.substr(0, j + 1);
        }
        re[re.size() - 1] == ' ' ? len = re.size() - 1 : len = re.size();
        return re.substr(0, len);
    }
};

int main(){
    Solution run;
    string str = "a the     hello   world    test aa";
    cout << run.reverseWords(str);

    return 0;
}
