#include "normal.h"

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k)
            return results;

        N = n;

        vector<int> result;
        solution(result, 1, k);

        return results;
    }

private:
    int N;
    vector<vector<int>> results;

    void solution(vector<int> result, int start, int cnt) {
        if (cnt == 0)
            results.push_back(result);
        else {
            for (int i = start; i <= N - cnt + 1; i++) {
                vector<int> temp = result;
                temp.push_back(i);
                solution(temp, i + 1, cnt - 1);
            }
        }
    }
};