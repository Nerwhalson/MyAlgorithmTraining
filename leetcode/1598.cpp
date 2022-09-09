#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0, len = size(logs);
        for(int i = 0; i < len; ++i)
        {
            if(logs[i] == "./");
            else if(logs[i] == "../")
                count = count == 0 ? 0 : count-1;
            else
                count++;
        }
    
        return count;
    }
};