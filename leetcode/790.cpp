class Solution {
public:
    int numTilings(int n) {
        long long *pre = new long long[4](), *now = new long long[4](), *temp;
        pre[3] = 1;
        for(int i = 0; i < n; i++){
            now[0] = pre[3] % mod;
            now[1] = (pre[2] + pre[0]) % mod;
            now[2] = (pre[1] + pre[0]) % mod;
            now[3] = (pre[0] + pre[1] + pre[2] + pre[3]) % mod;
            pre[0] = now[0];
            pre[1] = now[1];
            pre[2] = now[2];
            pre[3] = now[3];
        }
        return now[3];
    }
    int mod = 1e9+7;
};