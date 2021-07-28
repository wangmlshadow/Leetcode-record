/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int x) {
        nums.push_back(x);
        if (minVal > x) {
            minVal = x;
        }
    }
    
    void pop() {
        int res = nums[nums.size() - 1];
        nums.pop_back();
        if (res == minVal) {
            minVal = INT_MAX;
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < minVal) {
                    minVal = nums[i];
                }
            }
        }
    }
    
    int top() {
        return nums[nums.size() - 1];
    }
    
    int min() {
        return minVal;
    }
private:
    vector<int> nums;
    int minVal;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

/*
执行结果：通过 显示详情 添加备注
执行用时：20 ms, 在所有 C++ 提交中击败了89.01%的用户
内存消耗：14.6 MB, 在所有 C++ 提交中击败了85.33%的用户
*/