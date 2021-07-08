/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
*/
#include <stack>
using namespace std;

class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        temp1.push(value);
    }
    
    int deleteHead() {
        if (temp1.empty()) {
            return -1;
        }
        while (!temp1.empty()) {
            temp2.push(temp1.top());
            temp1.pop();
        }
        int res = temp2.top();
        temp2.pop();
        while (!temp2.empty()) {
            temp1.push(temp2.top());
            temp2.pop();
        }
        return res;
    }

private:
    stack<int> temp1;
    stack<int> temp2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

/*
执行结果：通过 显示详情 添加备注
执行用时：576 ms, 在所有 C++ 提交中击败了13.86%的用户
内存消耗：108.3 MB, 在所有 C++ 提交中击败了18.35%的用户
*/