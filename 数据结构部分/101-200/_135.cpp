#include "normal.h"

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int cnt = ratings.size();

        if (cnt == 0)
            return 0;

        map<int, vector<int>> helper;   // 保存rate和位置
        vector<int> give(cnt, 0);
        vector<int> sortR = ratings;
        sort(sortR.begin(), sortR.end());

        for (int i = 0; i < cnt; i++) {
            map<int, vector<int>>::iterator key = helper.find(ratings[i]);

            if (key == helper.end())
                helper[ratings[i]] = { i };
            else
                helper[ratings[i]].push_back(i);
        }

        for (int i = 0; i < cnt; i++) {
            vector<int> poss = helper[sortR[i]];

            for (int j = 0; j < poss.size(); j++) {
                int pos = poss[j];
                if (pos == 0) {   // 最左
                    if (cnt == 1 || give[pos + 1] == 0)
                        give[pos] = 1;
                    else {
                        if (ratings[pos] == ratings[pos + 1])
                            give[pos] = 1;
                        else
                            give[pos] = give[pos + 1] + 1;
                    }
                }
                else if (pos == cnt - 1) {   // 最右
                    if (cnt == 1 || give[pos - 1] == 0)
                        give[pos] = 1;
                    else {
                        if (ratings[pos] == ratings[pos - 1])
                            give[pos] = 1;
                        else
                            give[pos] = give[pos - 1] + 1;
                    }
                }
                else {
                    if (give[pos - 1] == 0 && give[pos + 1] == 0)
                        give[pos] = 1;
                    else if (give[pos - 1] == 0 && give[pos + 1] != 0) {
                        if (ratings[pos] == ratings[pos + 1])
                            give[pos] = 1;
                        else
                            give[pos] = give[pos + 1] + 1;
                    }
                    else if (give[pos - 1] != 0 && give[pos + 1] == 0) {
                        if (ratings[pos] == ratings[pos - 1])
                            give[pos] = 1;
                        else
                            give[pos] = give[pos - 1] + 1;
                    }
                    else {
                        if (ratings[pos - 1] > ratings[pos + 1]) {
                            if (ratings[pos - 1] == ratings[pos])
                                give[pos] = give[pos + 1] + 1;
                            else
                                give[pos] = max(give[pos - 1], give[pos + 1]) + 1;
                        }
                        else if (ratings[pos - 1] < ratings[pos + 1]) {
                            if (ratings[pos + 1] == ratings[pos])
                                give[pos] = give[pos - 1] + 1;
                            else
                                give[pos] = max(give[pos - 1], give[pos + 1]) + 1;
                        }
                        else {
                            if (ratings[pos + 1] == ratings[pos])
                                give[pos] = 1;
                            else
                                give[pos] = max(give[pos - 1], give[pos + 1]) + 1;
                        }
                    }
                }

            }

            while (i + 1 < cnt && sortR[i] == sortR[i + 1])
                i++;
        }

        int sum = 0;

        for (int i = 0; i < cnt; i++)
            sum += give[i];

        return sum;
    }
}; 