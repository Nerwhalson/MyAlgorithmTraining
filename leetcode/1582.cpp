#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = size(mat);
        int cols = size(mat[0]);
        int* row_vec = new int[rows] ();
        int* col_vec = new int[cols] ();
        int i, j, count=0;
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(mat[i][j] == 1)
                {
                    row_vec[i] ++;
                    col_vec[j] ++;
                }
            }
        }
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(mat[i][j] == 1 && row_vec[i] == 1 && col_vec[j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};