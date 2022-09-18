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
    int translateNum(int num) {
        if(num < 10)
            return 1;
        else if(num <= 25)
            return 2;
        else if(num < 100)
            return 1;
        vector<int> buf;
        while(num != 0)
        {
            buf.push_back(num % 10);
            num /= 10;
        }
        int len = buf.size();
        int *arr = new int[len];
        reverse(buf.begin(), buf.end());
        int temp = buf[0]*10 + buf[1];
        arr[0] = 1;
        arr[1] = temp <= 25 ? 2 : 1;
        for(int i = 2; i < len; i++)
        {
            temp = buf[i-1]*10 + buf[i];
            if(temp <= 25 && buf[i-1] != 0)
                arr[i] = arr[i-1] + arr[i-2];
            else
                arr[i] = arr[i-1];
        }
        return arr[len-1];
    }
};