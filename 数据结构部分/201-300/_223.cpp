#include "normal.h"

/*
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int s1 = (C - A) * (D - B);
        int s2 = (G - E) * (H - F);
        int overlap = 0;

        if (!(E >= C || G <= A || F >= D || H <= B)) {
            int x1 = max(A, E);
            int x2 = min(C, G);
            int y1 = max(B, F);
            int y2 = min(D, H);

            overlap = (x2 - x1) * (y2 - y1);
        }

        return s1 - overlap + s2; // 防止溢出
    }
};