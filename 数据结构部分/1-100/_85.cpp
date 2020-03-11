#include "normal.h"

/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
*/

class Solution {     // 测试所有情况，超时了，不能通过所有测试用例
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        max = 0;
        m = matrix.size();

        if (m == 0)
            return 0;

        n = matrix[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (max < 1)
                        max = 1;

                    solution(i, j, i, j, matrix);
                }                   
            }
        }

        return max;
    }

private:
    int max;
    int m;
    int n;

    void solution(int row_1, int col_1, int row_2, int col_2, vector<vector<char>>& matrix) {    //  row和col用来标记矩形的左上角坐标和右下角坐标
        if (row_2 < m - 1) {   // 右下角还没到最后一行
            if (col_2 < n - 1) {    // 还没到最后一列
                // 右下角向左
                bool sign_1 = true;

                for (int i = row_1; i <= row_2; i++) {
                    if (matrix[i][col_2 + 1] == '0') {
                        sign_1 = false;
                        break;
                    }
                }

                bool sign_2 = true;    // 向下

                for (int i = col_1; i <= col_2; i++) {
                    if (matrix[row_2 + 1][i] == '0') {
                        sign_2 = false;
                        break;
                    }
                }

                if (sign_1) {
                    int val = (row_2 - row_1 + 1) * (col_2 - col_1 + 2);
                    max = (max > val) ? max : val;
                    solution(row_1, col_1, row_2, col_2 + 1, matrix);
                }

                if (sign_2) {
                    int val = (row_2 - row_1 + 2) * (col_2 - col_1 + 1);
                    max = (max > val) ? max : val;
                    solution(row_1, col_1, row_2 + 1, col_2 , matrix);
                }

                if (sign_1 && sign_2 && matrix[row_2 + 1][col_2 + 1] == '1') {
                    int val = (row_2 - row_1 + 2) * (col_2 - col_1 + 2);
                    max = (max > val) ? max : val;
                    solution(row_1, col_1, row_2 + 1, col_2 + 1, matrix);
                }
            }
            else {
                bool sign_2 = true;    // 向下

                for (int i = col_1; i <= col_2; i++) {
                    if (matrix[row_2 + 1][i] == '0') {
                        sign_2 = false;
                        break;
                    }
                }

                if (sign_2) {
                    int val = (row_2 - row_1 + 2) * (col_2 - col_1 + 1);
                    max = (max > val) ? max : val;
                    solution(row_1, col_1, row_2 + 1, col_2, matrix);
                }
            }
        }
        else {
            if (col_2 < n - 1) {
                bool sign_1 = true;

                for (int i = row_1; i <= row_2; i++) {
                    if (matrix[i][col_2 + 1] == '0') {
                        sign_1 = false;
                        break;
                    }
                }

                if (sign_1) {
                    int val = (row_2 - row_1 + 1) * (col_2 - col_1 + 2);
                    max = (max > val) ? max : val;
                    solution(row_1, col_1, row_2, col_2 + 1, matrix);
                }
            }
        }
    }
};




class Solution {    // 动态规划,,,,结果错误，错在哪就是没找出来
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();

        if (m == 0)
            return 0;

        int n = matrix[0].size();
        int maxArea = 0;
        vector<int> left(n, 0);
        vector<int> right(n, n - 1);
        vector<int> height(n, 0);

        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n - 1;

            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == 1)
                    right[j] = min(right[j], cur_right);
                else {
                    right[j] = n - 1;
                    cur_right = j;
                }
            }

            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, (right[j] - left[j] + 1) * height[j]);
            }
        }

        return maxArea;
    }
};



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        m = matrix.size();

        if (m == 0)
            return 0;

        n = matrix[0].size();
        vector<int> dp(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = (matrix[i][j] == '1') ? dp[j] + 1 : 0;
            }

            maxArea = max(maxArea, Area(dp));     // dp为每一列的高，传入Area后，就变成了第84题的形式，求柱状图最大矩形面积
        }

        return maxArea;
    }

private:
    int m;
    int n;

    int Area(vector<int> heights) {
        stack<int> mySt;
        mySt.push(-1);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            while (mySt.top() != -1 && heights[mySt.top()] >= heights[i]) {
                int peek = mySt.top();
                mySt.pop();
                maxArea = max(maxArea, heights[peek] * (i - mySt.top() - 1));
            }

            mySt.push(i);
        }

        while (mySt.top() != -1) {
            int peek = mySt.top();
            mySt.pop();

            maxArea = max(maxArea, heights[peek] * (n - mySt.top() - 1));
        }

        return maxArea;
    }
};