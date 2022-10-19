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
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len = students.size(), pre, ans = 0;
        bool change = false;
        for(int i = 0; i < len; i++){
            if(i == 0 || sandwiches[i] != sandwiches[i-1])
                pre = 0;
            for(int j = pre; j < len; j++){
                if(sandwiches[i] == students[j]){
                    pre = j;
                    change = true;
                    students[j] = -1;
                    break;
                }
            }
            if(!change)
                break;
            change = false;
        }
        for(int i = 0; i < len; i++){
            if(students[i] != -1)
                ans++;
        }
        return ans;
    }
};