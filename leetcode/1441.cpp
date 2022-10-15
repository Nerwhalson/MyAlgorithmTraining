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
    vector<string> buildArray(vector<int>& target, int n) {
        int len = target.size();
        vector<string> ans;
        for(int i = 0, count = 1; i < len; i++, count++){
            if(target[i] == count)
                ans.push_back(push);
            else{
                while(target[i] != count){
                    ans.push_back(push);
                    ans.push_back(pop);
                    count++;
                }
                ans.push_back(push);
            }
        }
        return ans;
    }
private:
    string push = "Push";
    string pop = "Pop";
};