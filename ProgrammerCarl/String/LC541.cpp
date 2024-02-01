#include <String>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        string ans;
        char temp;
        int start = 0, ans_ptr = 0;
        for(int ptr1 = 0, ptr2 = 0; ptr1 < s.size(); ptr1++, ptr2 += 2){
            if(ptr2 == 2 * k){
                for(int i = start; i < ptr1; i++, ans_ptr++){

                }
                for(int i = ptr1; i < ptr2; i++, ans_ptr++){
                    ans.append(s[i]);
                }
                ptr1 = ptr2 + 1;
                start = ptr1;
            }
        }
        return ans;
    }
};