#include <String>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        for(int i = 0; i < magazine.size(); i++){
            arr[magazine[i] - 97]++;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            arr[ransomNote[i] - 97]--;
            if(arr[ransomNote[i] - 97] < 0)
                return false;
        }
        return true;
    }
};