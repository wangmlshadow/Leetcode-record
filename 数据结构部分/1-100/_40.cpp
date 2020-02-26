#include "normal.h"

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> one;

        sort(candidates.begin(), candidates.end());
        isMatch(target, result, candidates, 0, one);

        return result;
    }

    void isMatch(int target, vector<vector<int>>& result, vector<int>& candidates, int begin, vector<int> one) {
        if (begin >= candidates.size() || target < candidates[begin]) {
            return;
        }
        else if (target == candidates[begin]) {
            one.push_back(target);
            result.push_back(one);
            return;
        }
        else {
            int j = begin;
            while (j + 1 < candidates.size() && candidates[j + 1] == candidates[j])    // 跳过想等元素，避免结果中出现重复
                j++;


            isMatch(target, result, candidates, j + 1, one);
            one.push_back(candidates[begin]);
            isMatch(target - candidates[begin], result, candidates, begin + 1, one);
        }
    }
};