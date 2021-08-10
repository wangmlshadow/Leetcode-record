/*
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
*/
// 输入所有可能 
class Solution {
public:
    vector<string> permutation(string s) {
        set<string> resSet;
        vector<bool> used(s.length(), false);
        createStr(resSet, s, used, "");
        vector<string> resVec;
        for (set<string>::iterator iter = resSet.begin(); iter != resSet.end(); ++iter) {
            resVec.push_back(*iter);
        }
        return resVec;
    }

    void createStr(set<string>& resSet, string& s, vector<bool> used, string res) {
        if (res.length() == s.length()) {
            resSet.insert(res);
        }

        for (int i = 0; i < used.size(); ++i) {
            if (!used[i]) {
                vector<bool> moreUsed = used;
                moreUsed[i] = true;
                createStr(resSet, s, moreUsed, res + string(1, s[i]));
            }
        }
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：684 ms, 在所有 C++ 提交中击败了5.08%的用户
内存消耗：72.2 MB, 在所有 C++ 提交中击败了5.03%的用户
*/