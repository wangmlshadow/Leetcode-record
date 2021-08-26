/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/

// 试一下暴力求解
// 果然超时
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) {
                    res++; // 出现一个逆序对
                }
            }
        }

        return res;
    }
};

// 将nums元素从后向前 做一个类似于插入排序的过程 使用二分查找寻找每次插入的位置
// 还是超时
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;

        for (int i = nums.size() - 2; i >= 0; i--) {
            res += insertPos(nums, i);
        }

        return res;
    }

    // 从大到小排序
    int insertPos(vector<int>& nums, int pos) {
        int left = pos + 1, right = nums.size() - 1;
        int finalPos = pos;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[pos]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[pos]) {
                right = mid - 1;
            }
            else {
                while (mid < nums.size() && nums[mid] == nums[pos]) {
                    mid++;
                }
                finalPos = mid;
                break;
            }
        }

        if (left > right) {
            finalPos = left;
        }

        int temp = nums[pos];
        while (pos < finalPos - 1) {  // 应该是此处耗时太大
            nums[pos] = nums[pos + 1];
            ++pos;
        }

        nums[finalPos - 1] = temp;

        return nums.size() - finalPos;
    }
};

// 用map试一下
// 超时
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;

        int res = 0;
        map<int, int> numsMap;
        numsMap[nums[nums.size() - 1]] = 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (numsMap.count(nums[i]) == 0) {
                numsMap[nums[i]] = 1;
            }
            else {
                numsMap[nums[i]] += 1;
            }

            for (map<int, int>::iterator it = numsMap.begin(); it != numsMap.end(); it++) {
                if (it->first == nums[i]) {
                    break;
                }
                res += it->second;
            }
        }

        return res;
    }
};


// 通过归并排序
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};