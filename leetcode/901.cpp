#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        this->buff.emplace(-1, INT_MAX);
        this->index = -1;
    }
    
    int next(int price) {
        int len;
        index++;
        while(buff.top().second <= price){
            buff.pop();
        }
        len = index - buff.top().first;
        buff.emplace(index, price);
        return len;
    }
private:
    int index;
    stack<pair<int, int>> buff;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */