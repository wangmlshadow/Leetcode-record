/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的
弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压
栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 
就不可能是该压栈序列的弹出序列。
*/

// 压入栈的所有数字均不相等
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) {
            return false;
        }
        // 模拟压栈出栈过程 查看是否可能满足序列
        int i = 0;
        int j = 0;
        stack<int> s;
        for ( ; i < popped.size(); ++i) {
            int curPop = popped[i];
            // 栈顶元素出栈
            if (!s.empty()) {
                if (s.top() == curPop) {
                    s.pop();
                    continue;
                }
                if (j == pushed.size()) {// 所有元素都已经入栈 但是此时栈顶元素和需要出栈的元素不相等 表示序列不满足
                    return false;
                }
            }
            // 栈顶元素不满足 需要继续入栈 再出栈
            while (j < pushed.size() && pushed[j] != curPop) {
                s.push(pushed[j]);// 入栈
                ++j;
            }
            if (j >= pushed.size()) {// 全部元素都入栈 但还是没找到符合出栈的元素 表示序列不满足
                return false;
            }
            if (j < pushed.size()) {
                ++j;// 入栈出栈
            }
        }
        return true;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：12 ms, 在所有 C++ 提交中击败了48.93%的用户
内存消耗：14.6 MB, 在所有 C++ 提交中击败了87.92%的用户
*/