class Solution {
public:
    int mod = 1e9+7;
    int numWays(int n) {
        if(n < 2)
            return 1;
        int* arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 2; i <= n; i++)
            arr[i] = (arr[i-1] + arr[i-2]) % mod;
        return arr[n];
    }
};