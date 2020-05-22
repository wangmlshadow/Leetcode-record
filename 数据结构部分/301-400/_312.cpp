#include "normal.h"

/*
有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬
币。 这里的 left 和 right 代表和 i 相邻的两个气球的序号。注意当你戳破了气球 i 后，气球 left 和气
球 right 就变成了相邻的气球。

求所能获得硬币的最大数量。

说明:

你可以假设 nums[-1] = nums[n] = 1，但注意它们不是真实存在的所以并不能被戳破。
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/burst-balloons
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {   // 递归在第30个测试案例超时
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> newNums(n, 1);

        for (int i = 0; i < nums.size(); i++)
            newNums[i + 1] = nums[i];

        vector<vector<int>> res(n, vector<int>(n, 0));
        return dp(res, newNums, 0, n - 1);
    }

    int dp(vector<vector<int>>& res, vector<int>& newNums, int left, int right) {
        if (left + 1 == right)
            return 0;

        if (res[left][right] > 0)
            return res[left][right];

        int ans = 0;

        for (int i = left + 1; i < right; i++) {
            ans = max(ans, newNums[left] * newNums[i] * newNums[right] + dp(res, newNums, left, i) + dp(res, newNums, i, right));
        }

        return ans;
    }
};

class Solution {  // 这个过了 但是也很慢啊
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> newNums(n, 1);

        for (int i = 0; i < nums.size(); i++)
            newNums[i + 1] = nums[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int left = n - 2; left > -1; left--) {
            for (int right = left + 2; right < n; right++) {
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right], newNums[left] * newNums[i] * newNums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }

        return dp[0][n - 1];
    }
};