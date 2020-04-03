#include "normal.h"

/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



class MinStack {
public:   
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }

    void push(int x) {
        val.push_back(x);
        minVal = min(minVal, x);
    }

    void pop() {
        int n = top();
        val.pop_back();

        if (n == minVal) {
            minVal = INT_MAX;
            for (int i = 0; i < val.size(); i++) {
                minVal = min(minVal, val[i]);
            }
        }
    }

    int top() {
        if (val.empty()) 
            return minVal;
        else
            return val[val.size() - 1];
    }

    int getMin() {
        return minVal;
    }
 
private:
    vector<int> val;
    int minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */