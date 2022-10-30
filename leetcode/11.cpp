#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size(), i = 0, j = len-1, max = 0;
        while(i != j){
            if(height[i] < height[j]){
                max = max > (j-i)*height[i] ? max : (j-i)*height[i];
                i++;
            }
            else{
                max = max > (j-i)*height[j] ? max : (j-i)*height[j];
                j--;
            }
        }
        return max;
    }
};