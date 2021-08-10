/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
*/

// 排序
// O(NlogN)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> res;

        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：16 ms, 在所有 C++ 提交中击败了99.53%的用户
内存消耗：18.6 MB, 在所有 C++ 提交中击败了57.85%的用户
*/

// 滑动
// O(KN)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        int max = INT_MIN;
        int pos = -1;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i]);

            if (max < arr[i]) {
                max = arr[i];
                pos = i;
            }
        }

        for (int i = k; i < arr.size(); ++i) {
            if (max <= arr[i]) {
                continue;
            }
            else {
                res[pos] = arr[i];
                max = res[pos];
                for (int j = 0; j < k; ++j) {
                    if (max < res[j]) {
                        max = res[j];
                        pos = j;
                    }
                }
            }
        }

        return res;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：224 ms, 在所有 C++ 提交中击败了5.11%的用户
内存消耗：18.6 MB, 在所有 C++ 提交中击败了57.13%的用户
*/