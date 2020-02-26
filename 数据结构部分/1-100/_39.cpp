#include "normal.h"

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {    // 排序，递归
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> one;

        if (target < candidates[0])
            return result;

        isMatch(target, result, 0, candidates, one);

        return result;
    }

    void isMatch(int target, vector<vector<int>>& result, int begin, vector<int>& candidates, vector<int> one) {
        if (begin >= candidates.size() || candidates[begin] > target)
            return;
        else if (target == candidates[begin]) {
            one.push_back(target);
            result.push_back(one);
            return;
        }
        else {
            isMatch(target, result, begin + 1, candidates, one);
            one.push_back(candidates[begin]);
            isMatch(target - candidates[begin], result, begin, candidates, one);
            //isMatch(target - candidates[begin], result, begin + 1, candidates, one);   
            // 去除重复，因为这一步其实在第二个isMatch的下一步会分裂出来，即第二个isMatch + 第二个isMatch的下一步的第一个isMatch
        }
    }
};