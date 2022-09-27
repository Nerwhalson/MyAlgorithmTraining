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
    int m = 0;
    int n = 0;
    int length = 0;
    int** visit;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        length = word.size();
        visit = new int*[m];
        for(int i = 0; i < m; i++)
            visit[i] = new int[n]();
        bool flag = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    flag |= traverse(board, word, 0, i, j);
                }
            }
        }
        return flag;
    }

    bool traverse(vector<vector<char>>& board, string word, int sub, int line, int col){
        bool flag = false;
        if(sub == length-1)
            return true;
        visit[line][col] = 1;
        if(line+1 < m && visit[line+1][col] == 0 && board[line+1][col] == word[sub+1])
            flag |= traverse(board, word, sub+1, line+1, col);
        if(line-1 >= 0 && visit[line-1][col] == 0 &&  board[line-1][col] == word[sub+1])
            flag |= traverse(board, word, sub+1, line-1, col);
        if( col+1 < n && visit[line][col+1] == 0 &&  board[line][col+1] == word[sub+1])
            flag |= traverse(board, word, sub+1, line, col+1);
        if( col-1 >= 0 && visit[line][col-1] == 0 &&  board[line][col-1] == word[sub+1])
            flag |= traverse(board, word, sub+1, line, col-1);
        visit[line][col] = 0;
        return flag;
    }
};