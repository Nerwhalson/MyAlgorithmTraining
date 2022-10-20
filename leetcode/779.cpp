class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k == 1)
            return 0;
        else
            return k % 2 ? kthGrammar(n, (k+1)/2) : !kthGrammar(n, (k+1)/2);
    }
};