#include "normal.h"

/*

城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。现在，假设您获得了城
市风光照片（图A）上显示的所有建筑物的位置和高度，请编写一个程序以输出由这些建筑物形
成的天际线（图B）。
每个建筑物的几何信息用三元组 [Li，Ri，Hi] 表示，其中 Li 和 Ri 分别是第 i 座建筑物左右边缘
的 x 坐标，Hi 是其高度。可以保证 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX 和 Ri - Li > 0。
您可以假设所有建筑物都是在绝对平坦且高度为 0 的表面上的完美矩形。

例如，图A中所有建筑物的尺寸记录为：[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] 。

输出是以 [ [x1,y1], [x2, y2], [x3, y3], ... ] 格式的“关键点”（图B中的红点）的列表，它们唯
一地定义了天际线。关键点是水平线段的左端点。请注意，最右侧建筑物的最后一个关键点仅用于标记
天际线的终点，并始终为零高度。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

例如，图B中的天际线应该表示为：[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]。

说明:

任何输入列表中的建筑物数量保证在 [0, 10000] 范围内。
输入列表已经按左 x 坐标 Li  进行升序排列。
输出列表必须按 x 位排序。
输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不
正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-skyline-problem
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {        
        int size = buildings.size();
        vector<vector<int>> res;

        if (size == 0)
            return res;

        multiset<pair<int, int>> points;

        for (int i = 0; i < size; i++) {
            points.insert(make_pair(buildings[i][0], -buildings[i][2]));
            points.insert(make_pair(buildings[i][1], buildings[i][2]));
        }

        multiset<int> height({ 0 });
        vector<int> last(2, 0);
        multiset<pair<int, int>>::iterator iter = points.begin();

        for (; iter != points.end(); iter++) {
            if (iter->second < 0)
                height.insert(-iter->second);
            else
                height.erase(height.find(iter->second));

            int maxH = *height.rbegin();

            if (last[1] != maxH) {
                last[0] = iter->first;
                last[1] = maxH;
                res.push_back(last);
            }
        }
        
        return res;
    }
};