#include "normal.h"

/*
数组

给你一个餐馆信息数组 restaurants，其中  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]。
你必须使用以下三个过滤器来过滤这些餐馆信息。

其中素食者友好过滤器 veganFriendly 的值可以为 true 或者 false，如果为 true 就意味着你应该只包括
 veganFriendlyi 为 true 的餐馆，为 false 则意味着可以包括任何餐馆。此外，我们还有最大价格 maxPrice 
 和最大距离 maxDistance 两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。

过滤后返回餐馆的 id，按照 rating 从高到低排序。如果 rating 相同，那么按 id 从高到低排序。简单起见，
 veganFriendlyi 和 veganFriendly 为 true 时取值为 1，为 false 时，取值为 0 。

 思路：先把符合条件的选出来，然后使用sort()，重写sort()中的compare()函数
*/

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> allRes;

        for (int i = 0; i < restaurants.size(); i++) {
            if ((veganFriendly == 0 || veganFriendly == restaurants[i][2]) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
                allRes.push_back(restaurants[i]);
        }

        sort(allRes.begin(), allRes.end(), cmp);

        vector<int> res;

        for (int i = 0; i < allRes.size(); i++)
            res.push_back(allRes[i][0]);

        return res;
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] != b[1])
            return a[1] > b[1];

        return a[0] > b[0];
    }
};

/*
执行结果：通过 显示详情
执行用时：148 ms, 在所有 C++ 提交中击败了53.85%的用户
内存消耗：21.3 MB, 在所有 C++ 提交中击败了100.00%的用户
*/