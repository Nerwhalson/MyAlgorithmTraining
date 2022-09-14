class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size(), k = len-(len/10), sum = 0, count = 0;
        for(int i = len/20; count < k; count++, i++)
            sum += arr[i];
        double ans = double(sum) / double(k);

        return ans;
    }

    // 其实可以用快排思路优化，但题目数据量没有必要
    // int quick_find(vector<int>& arr, int start, int end, int k, bool large){
    //     // if(start == end)
    //     //     return arr[start];
    //     int tot = 0, buf = 0, i = start, j = end, pivot = arr[start]; 
    //     while(i != j)
    //     {
    //         while(arr[i] <= pivot)
    //             i++;
    //         arr[j] = arr[i] ^ arr[j];
    //         arr[i] = arr[i] ^ arr[j];
    //         arr[j] = arr[i] ^ arr[j];
    //         while(arr[j] >= pivot)
    //             j--;
    //         arr[j] = arr[i] ^ arr[j];
    //         arr[i] = arr[i] ^ arr[j];
    //         arr[j] = arr[i] ^ arr[j];
    //     }
    //     if(large)
    //     {
    //         if(end-i > k)
    //             tot = quick_find(arr, i+1, end, k, large);
    //         else if(end - i < k)
    //         {
    //             for(int sub = end; sub > i; sub--)
    //                 buf += arr[sub];
    //             tot = buf + quick_find(arr, start, i, k-end+i, large);
    //         }
    //         else
    //         {
    //             for(int sub = end; sub > i; sub++)
    //                 tot += arr[sub];
    //         }
    //     }
    //     else
    //     {
    //         if(i-start > k)
    //             tot = quick_find(arr, start, i-1, k, large);
    //         else if(i-start < k)
    //         {
    //             for(int sub = start; sub < i; sub++)
    //                 buf += arr[sub];
    //             tot = buf + quick_find(arr, start, i-1, k-i+start, large);
    //         }
    //         else
    //         {
    //             for(int sub = start; sub < i; sub++)
    //                 tot += arr[sub];
    //         }
    //     }

    //     return tot;
    // }
};