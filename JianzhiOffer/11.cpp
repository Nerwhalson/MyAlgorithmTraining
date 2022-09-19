#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // int i = 0, len = numbers.size();
        // for(int i = 0; i < len-1; i++)
        // {
        //     if(numbers[i] > numbers[i+1])
        //         return numbers[i+1];
        // }
        // return numbers[0];
        int ans, len = numbers.size(), left = 0, right = len-1;
        int mid = (left + right) / 2;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(numbers[right] < numbers[mid])
                left = mid + 1;
            else if(numbers[right] > numbers[mid])
                right = mid;
            else
                right--;
        }
        return numbers[mid];
    }
};