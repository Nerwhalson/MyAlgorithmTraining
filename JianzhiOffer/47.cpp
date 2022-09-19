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
    int maxValue(vector<vector<int>>& grid) {
        int len_i = grid.size(), len_j = grid[0].size();
        for(int i = 0; i < len_i; i++)
        {
            for(int j = 0; j < len_j; j++)
            {
                if(i == 0 && j == 0)
                    grid[i][j] = grid[i][j];
                else if(i == 0)
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                else if(j == 0)
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                else
                    grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

int main()
{
    Solution run;

    return 0;
}