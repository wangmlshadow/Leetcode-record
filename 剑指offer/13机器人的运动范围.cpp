/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从
坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移
动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不
能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
*/

// 可到达 存在一条路径 从(0, 0)开始 路径上所有点都是可到到
class Solution {
public:
    int movingCount(int m, int n, int k) {
        allRows = m;
        allClos = n;
        res = 0;
        limit = k;
        // 标记每个格子是否已经经过或者已经被判定为不能到达
        vector<vector<bool>> existed(m, vector<bool>(n, false));
        toNext(0, 0, existed);
        return res;
    }

    bool canArrive(int row, int clo) {
        int sum = 0;
        while (row != 0) {
            sum += row % 10;
            row /= 10;
        }
        while (clo != 0) {
            sum += clo % 10;
            clo /= 10;
        }
        return limit >= sum;
    }

    void toNext(int row, int clo, vector<vector<bool>>& existed) {
        if (row < 0 || clo < 0 || row >= allRows || clo >= allClos) {
            return;
        }
        if (existed[row][clo]) {
            return;
        }
        existed[row][clo] = true;
        if (!canArrive(row, clo)) {
            return;
        }
        res++;
        // 去下一个格子 上下左右
        toNext(row - 1, clo, existed);
        toNext(row + 1, clo, existed);
        toNext(row, clo - 1, existed);
        toNext(row, clo + 1, existed);
    }

private:
    int allRows;
    int allClos;
    int res;
    int limit;
};

/*
执行结果：通过 显示详情 添加备注
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了67.68%的用户
*/