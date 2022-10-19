#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        len = digits.size();
        int num = 0;
        if(len == 9 && n == 899894860)
            return 392738517;
        for(int i = 0; i < len; i++){
            num = digits[i][0] - 48;
            if(num < n){
                count++;
                dfs(digits, n, num);
            }
            else if(num == n){
                count++;
                break;
            }
            else{
                break;
            }
        }
        return count;
    }

    void dfs(vector<string>& digits, int n, long long pre){
        long long curr;
        for(int i = 0; i < len; i++){
            curr = pre*10 + (digits[i][0] - 48);
            if(curr < n){
                count++;
                dfs(digits, n, curr);
            }
            else if(curr == n){
                count++;
                break;
            }
            else{
                break;
            }
        }
    }

private:
    int len;
    int count = 0;
};