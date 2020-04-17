#include "normal.h"

/*
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        topV = 0;
        cnt = 0;
    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        topV = x;
        cnt++;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int i = 1;
        if (!q.empty()) {
            queue<int> temp;
            

            while (i < cnt) {
                temp.push(q.front());

                if (i == cnt - 1) {
                    topV = q.front();
                    q.pop();
                    i = q.front();
                    break;
                }
                    
                q.pop();
                i++;               
            }

            q = temp;
            cnt--;
        }

        return i;
    }

    /** Get the top element. */
    int top() {
        return topV;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return cnt == 0;
    }

private:
    queue<int> q;
    int topV;
    int cnt;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
执行结果：通过 显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 C++ 提交中击败了100.00%的用户
*/