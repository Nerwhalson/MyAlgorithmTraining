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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        bool flag = true;
        int *buff = new int[n](), len = dislikes.size(), count = 0, temp;
        int **matrix = new int*[n];
        for(int i = 0; i < n; i++){
            matrix[i] = new int[n]();
        }
        queue<int> q;
        for(int i = 0; i < len; i++){
            matrix[dislikes[i][0]-1][dislikes[i][1]-1] = 1;
            matrix[dislikes[i][1]-1][dislikes[i][0]-1] = 1;
            buff[dislikes[i][0]-1] += 1;
            buff[dislikes[i][1]-1] += 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << "end of matrix." << endl;
        for(int i = 0; i < n; i++){
            if(buff[i] <= 1)
                q.push(i);
        }
        while(!q.empty()){
            temp = q.front();
            for(int i = 0; i < n; i++){
                if(matrix[i][temp] == 1){
                    buff[i] -= 1;
                    if(buff[i] == 1)
                        q.push(i);
                }
            }
            q.pop();
            count++;
            for(int j = 0; j < n; j++){
                cout << buff[j] << " ";
            }
            cout << endl;
        }
        return count == n;
    }
};

int main()
{
    Solution run;
    int n = 10;
    vector<vector<int>> dislikes = {{4,7},{4,8},{5,6},{1,6},{3,7},{2,5},{5,8},{1,2},{4,9},{6,1},{8,1},{3,6},{2,1},{9,1},{3,9},{2,3},{1,9},{4,6},{5,7},{3,8},{1,8},{1,7},{2,4}};
    cout << (run.possibleBipartition(n, dislikes) ? "True" : "False");

    return 0;
}
