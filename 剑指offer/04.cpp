#include <vector>

using namespace std;

class Solution {
public:
    int line_b_search(vector<vector<int>>& matrix, int target, int col)
    {
        int mid, line = -1, left = 0, right = matrix.size() - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(matrix[mid][col] <= target)
            {
                line = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        return line;
    }

    int col_b_search(vector<vector<int>>& matrix, int target, int line)
    {
        int mid, col = -1, left = 0, right = matrix[0].size() - 1;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(matrix[line][mid] <= target)
            {
                col = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        return col;
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        int low = 0, l_high = matrix.size() - 1, c_high = matrix[0].size() - 1;
        while(low <= l_high && low <= c_high)
        {
            l_high = line_b_search(matrix, target, low);
            c_high = col_b_search(matrix, target, low);
            // cout << l_high << " " << c_high << endl;
            if(l_high != -1 && c_high != -1 && (matrix[low][c_high] == target || matrix[l_high][low] == target))
                break;
            low++;
        }
        if(l_high != -1 && c_high != -1 && low < matrix.size() && low < matrix[0].size() &&(matrix[low][c_high] == target || matrix[l_high][low] == target))
            ans = true;
        
        return ans;
    }
};