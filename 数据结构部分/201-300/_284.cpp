#include "normal.h"

/*
给定一个迭代器类的接口，接口包含两个方法： next() 和 hasNext()。设计并实现一个支持 peek() 操作
的顶端迭代器 -- 其本质就是把原本应由 next() 方法返回的元素 peek() 出来。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/peeking-iterator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
class Iterator {
	struct Data;
	Data* data;

public:
    Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		for (auto t : nums)
			n.push_back(t);

		top = 0;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return n[top];
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		return n[top++];
	}

	bool hasNext() const {
		return top < n.size();
	}

private:
	vector<int> n;
	int top;
};