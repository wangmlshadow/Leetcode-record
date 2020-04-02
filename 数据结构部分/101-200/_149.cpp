#include "normal.h"

/*
给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size();

        if (size <= 2)
            return size;

        // 两点确定一条直线
        vector<vector<bool>> sign(size, vector<bool>(size, false));  // 标识哪两个点的直线已经计算过了，避免重复计算
        int i = 1;

        for (; i < size; i++) {
            if (points[i][0] != points[0][0] || points[i][1] != points[1][1])
                break;
        }

        if (i == size)
            return size;

        int max = 2;

        for (i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (sign[i][j])
                    continue;

                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    continue;

                int cnt = 2;
                long long x = points[i][0] * 1.0;
                long long y = points[i][1] * 1.0;
                long long x1 = points[j][0] * 1.0;
                long long y1 = points[j][1] * 1.0;
                // y - y1 / x - x1 = y2 - y1 / x2 - x1表示一条直线
                for (int k = 0; k < size; k++) {
                    if (k == i || k == j)
                        continue;

                    long long x2 = points[k][0] * 1.0;
                    long long y2 = points[k][1] * 1.0;

                    if ((x2 == x && y2 == y) || (x2 == x1 && y2 == y1)) {
                        cnt++;
                        sign[i][k] = true;
                        sign[k][i] = true;
                        sign[j][k] = true;
                        sign[k][j] = true;
                        continue;
                    }

                    if (((y - y1) * (x2 - x1)) == ((y2 - y1) * (x - x1))) {   // 测试时有问题 不能直接用这个等式判断
                        cnt++;
                        sign[i][k] = true;
                        sign[k][i] = true;
                        sign[j][k] = true;
                        sign[k][j] = true;
                    }
                }
                
                if (max < cnt)
                    max = cnt;
            }
        }

        return max;
    }
};