#include "normal.h"

/*
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-from-data-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        med = 0;
    }

    void addNum(int num) {
        nums.insert(num);
        int n = nums.size();

        if (n % 2 == 0) {
            multiset<int>::iterator iter = nums.begin();
            
            double res = 0;

            for (int i = n / 2 - 1; i >= 1; i--)
                iter++;

            res += *iter;
            iter++;
            res += *iter;
            med = res / 2;
        }
        else {
            multiset<int>::iterator iter = nums.begin();

            for (int i = n / 2; i >= 1; i--)
                iter++;

            med = *iter;
        }
    }

    double findMedian() {
        return med;
    }

private:
    multiset<int> nums;
    double med;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */