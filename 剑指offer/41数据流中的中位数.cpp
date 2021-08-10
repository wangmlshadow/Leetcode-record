/*

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序
之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两
个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        allNum.insert(num);
    }
    
    double findMedian() {
        int len = allNum.size();
        double res;
        if (len % 2 == 1) {
            multiset<int>::iterator iter = allNum.begin() + len / 2;
            res = *iter;
        }
        else {
            multiset<int>::iterator iter = allNum.begin() + len / 2 - 1;
            res = *iter;
            ++iter;
            res = (res + *iter) / 2;
        }
        return res;
    }

private:
    multiset<int> allNum;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*
执行结果：通过 显示详情 添加备注
执行用时：1120 ms, 在所有 C++ 提交中击败了5.02%的用户
内存消耗：43.1 MB, 在所有 C++ 提交中击败了5.04%的用户
*/