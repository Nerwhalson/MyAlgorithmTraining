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
    int totalFruit(vector<int>& fruits) {
        int begin1 = 0, begin2 = 0, len = fruits.size(), type1 = fruits[0], type2 = -1, max = 0;
        fruits[0] = 1;
        for(int i = 1; i < len; i++){
            if(fruits[i] != type1 && fruits[i] != type2){
                type2 = type1;
                begin2 = begin1;
                type1 = fruits[i];
                begin1 = i;
                fruits[i] = i - begin2 + 1;
            }
            else if(fruits[i] != type1){
                type2 = type1;
                begin2 = begin1;
                type1 = fruits[i];
                begin1 = i;
                fruits[i] = fruits[i-1] + 1;
            }
            else
                fruits[i] = fruits[i-1] + 1;
            max = fruits[i] > max ? fruits[i] : max;
        }
        max = fruits[0] > max ? fruits[0] : max;
        return max;
    }
};