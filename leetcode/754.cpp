class Solution {
public:
    int reachNumber(int target) {
        target = target < 0 ? -target : target;
        int i = 0;
        while(target > 0){
            i++;
            target -= i;
        }
        return target % 2 == 0 ? i : i + 1 + i % 2;
    }
};