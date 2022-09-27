class Solution {
public:
    int** visited;

    int movingCount(int m, int n, int k) {
        visited = new int*[m];
        for(int i = 0; i < m; i++)
            visited[i] = new int[n]();
        traverse(m, n, k, 0, 0);
        int count = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(visited[i][j] == 1)
                    count++;
        return count;
    }

    void traverse(int m, int n, int k, int i, int j){
        visited[i][j] = 1;
        if(i+1 < m && visited[i+1][j] == 0 && legal(i+1, j, k))
            traverse(m, n, k, i+1, j);
        if(i-1 > -1 && visited[i-1][j] == 0 && legal(i-1, j, k))
            traverse(m, n, k, i-1, j);
        if(j+1 < n && visited[i][j+1] == 0 && legal(i, j+1, k))
            traverse(m, n, k, i, j+1);
        if(j-1 > -1 && visited[i][j-1] == 0 && legal(i, j-1, k))
            traverse(m, n, k, i, j-1);
    }

    bool legal(int i, int j, int k){
        int num = 0;
        while(i != 0){
            num += i % 10;
            i /= 10;
        }
        while(j != 0){
            num += j % 10;
            j /= 10;
        }
        return num <= k;
    }
};