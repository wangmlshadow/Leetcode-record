#include "normal.h"

/*
使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        pVal = 0;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (s.empty())
            pVal = x;

        s.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = 0;
        if (!s.empty()) {
            stack<int> temp;
            while (!s.empty()) {
                temp.push(s.top());
                s.pop();
            }

            res = temp.top();
            temp.pop();

            if (!temp.empty()) {
                pVal = temp.top();

                while (!temp.empty()) {
                    s.push(temp.top());
                    temp.pop();
                }
            }
            else {
                pVal = 0;
            }
        }

        return res;
    }

    /** Get the front element. */
    int peek() {
        return pVal;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }

private:
    int pVal;
    stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */