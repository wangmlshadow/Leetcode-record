#include "normal.h"

/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



class Solution {
public:
    int maxArea(vector<int>& height) {    // 最直接的方法，直接将所有可能情况求出来
        int cur = 0, max = 0;

        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                cur = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);

                if (max < cur)
                    max = cur;
            }
        }

        return max;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {    // 双指针法，移动较长边肯定会使面积减小，而移动较短边则可能使面积变大
        
        int left = 0;
        int right = height.size() - 1;
        int max = 0;
        int cur = 0;

        while (left < right) {
            cur = (right - left) * min(height[left], height[right]);

            if (cur > max)
                max = cur;

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return max;
    }
};