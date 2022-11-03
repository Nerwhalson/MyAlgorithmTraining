#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size(), m = word.size(), ans = 0;
        if (n < m) {
            return 0;
        }

        int *f = new int[n]();
        for (int i = m - 1; i < n; ++i) {
            bool valid = true;
            for (int j = 0; j < m; ++j) {
                if (sequence[i - m + j + 1] != word[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                f[i] = (i == m - 1 ? 0 : f[i - m]) + 1;
            }
        }
        for(int i = 0; i < n; i++){
            ans = ans < f[i] ? f[i] : ans;
        }
        return ans;
    }
};