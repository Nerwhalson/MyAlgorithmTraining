#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        ans.resize(n);
        for(int i = 0; i < n; i++)
            ans[i].resize(n);
        int count = 1, left = -1, upper = -1, right = n, down = n, i = 0, j = 0;
        while(count <= n * n){
            while(j < right){
                ans[i][j] = count;
                count++;
                j++;
            }
            if(count > n*n)
                break;
            right--;
            j--;
            i++;
            while(i < down){
                ans[i][j] = count;
                count++;
                i++;
            }
            if(count > n*n)
                break;
            down--;
            i--;
            j--;
            while(j > left){
                ans[i][j] = count;
                count++;
                j--;
            }
            if(count > n*n)
                break;
            left++;
            j++;
            i--;
            upper++;
            while(i > upper){
                ans[i][j] = count;
                count++;
                i--;
            }
            i++;
            j++;
        }
        return ans;
    }
};

int main(){
    Solution run;
    int target = 5;
    vector<vector<int>> arr = run.generateMatrix(target);
    for(int i = 0; i < target; i++){
        for(int j = 0; j < target; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}