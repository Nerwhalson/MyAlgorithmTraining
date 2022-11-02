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
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int d, power = 0, xmin = 50, xmax = 0, ymin = 50, ymax = 0, len = towers.size();
        int* ans = new int[3]();
        for(int i = 0; i < len; i++){
            if(towers[i][0] < xmin)
                xmin = towers[i][0];
            if(towers[i][0] > xmax)
                xmax = towers[i][0];
            if(towers[i][1] < ymin)
                ymin = towers[i][1];
            if(towers[i][1] > ymax)
                ymax = towers[i][1];
        }
        for(int x = xmin; x <= xmax; x++){
            for(int y = ymin; y <= ymax; y++){
                for(int i = 0; i < len; i++){
                    d = (x-towers[i][0])*(x-towers[i][0]) + (y-towers[i][1])*(y-towers[i][1]);
                    if(d <= radius*radius)
                        power += (int)(towers[i][2] / (1 + sqrt(d)));
                }
                if(power > ans[2]){
                    ans[0] = x;
                    ans[1] = y;
                    ans[2] = power;
                }
                power = 0;
            }
        }
        return {ans[0], ans[1]};
    }
};