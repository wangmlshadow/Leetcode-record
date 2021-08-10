/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
*/

// 将nums转为string 再排序
class Solution {
public:
    string minNumber(vector<int>& nums) {
        if (nums.size() == 0) {
            return "";
        }

        // 全0
        bool ok = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return string(nums.size(), '0');
        }

        vector<string> allNumbers;
        for (int i = 0; i < nums.size(); ++i) {
            allNumbers.push_back(to_string(nums[i]));
        }

        sort(allNumbers.begin(), allNumbers.end(), compare);

        string result;
        for (int i = 0; i < allNumbers.size(); ++i) {
            result += allNumbers[i];
        }

        return result;
    }

    static bool compare(const string lfv, const string rgv) {
        int left = 0, right = 0;
        while (left < lfv.length() && right < rgv.length()) {
            if (lfv[left] < rgv[right]) {
                return true;
            }
            else if (lfv[left] > rgv[right]) {
                return false;
            }
            else {
                ;
            }
            ++left;
            ++right;
        }

        if (left < lfv.length()) {
            return compare(lfv.substr(left, lfv.length() - left), rgv);
        }

        if (right < rgv.length()) {
            return compare(lfv, rgv.substr(right, rgv.length() - right));
        }

        return true;
    }

    // 方法2
    static bool compare2(const string lfv, const string rgv) {
        return lfv + rgv < rgv + lfv;
    }
};
/*
执行结果：通过 显示详情 添加备注
执行用时：8 ms, 在所有 C++ 提交中击败了76.53%的用户
内存消耗：11.1 MB, 在所有 C++ 提交中击败了31.65%的用户
*/
