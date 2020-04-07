#include "normal.h"

/*
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。

你可以假设版本字符串非空，并且只包含数字和 . 字符。

 . 字符不代表小数点，而是用于分隔数字序列。

例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。

你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compare-version-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {    // 
public:
    int compareVersion(string version1, string version2) {
        if (version1 == version2)
            return 0;

        vector<int> v1;
        vector<int> v2;
        int len1 = version1.length();
        int len2 = version2.length();

        for (int i = 0; i < len1; ) {
            while (i < len1 && version1[i] == '.')
                i++;

            if (i >= len1)
                break;

            int cur = 0;

            while (i < len1 && version1[i] != '.') {
                int temp = version1[i] - '0';

                if (cur != 0 || temp != 0)
                    cur = cur * 10 + temp;

                i++;
            }

            v1.push_back(cur);
        }

        for (int i = 0; i < len2; ) {
            while (i < len2 && version2[i] == '.')
                i++;

            if (i >= len2)
                break;

            int cur = 0;

            while (i < len2 && version2[i] != '.') {
                int temp = version2[i] - '0';

                if (cur != 0 || temp != 0)
                    cur = cur * 10 + temp;

                i++;
            }

            v2.push_back(cur);
        }

        int size1 = v1.size();
        int size2 = v2.size();
        int i = 0;

        while (i < size1 && i < size2) {
            if (v1[i] > v2[i])
                return 1;

            if (v1[i] < v2[i])
                return -1;

            i++;
        }

        if (i == size1 && i == size2)
            return 0;

        if (i == size1) {
            while (i < size2) {
                if (v2[i] > 0)
                    return -1;

                i++;
            }
        }
        else {
            while (i < size1) {
                if (v1[i] > 0)
                    return 1;
                i++;
            }
        }

        return 0;
    }
};

/*
执行结果：通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户
*/