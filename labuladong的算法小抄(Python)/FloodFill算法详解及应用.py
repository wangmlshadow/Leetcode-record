# 第733题
# 有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
# 给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
# 为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这
# 四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。
# 最后返回经过上色渲染后的图像。

# 其实就是一个二维矩阵遍历问题
# 即深度优先搜索或者四叉树遍历

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        origColor = image[sr][sc]
        self.fill(image, sr, sc, origColor, newColor)
        return image

    def fill(self, image: List[List[int]], x: int, y: int, origColor: int, newColor: int):
        # 出界：超出边界索引
        if not self.inArea(image, x, y):
            return
        # 碰壁：遇到其他颜色 超出origColor区域
        if image[x][y] != origColor:
            return
        image[x][y] = newColor
        self.fill(image, x, y + 1, origColor, newColor)
        self.fill(image, x, y - 1, origColor, newColor)
        self.fill(image, x + 1, y, origColor, newColor)
        self.fill(image, x - 1, y, origColor, newColor)
        
    
    def inArea(self, image: List[List[int]], x: int, y: int) -> bool:
        return x >= 0 and x < len(image) and y >= 0 and y < len(image[0])
      
# 上述代码可以解决大部分情况 但是当origColor和newColor相同时 会出现无限递归的问题
# 解决方案 记录那些路径是已经经过的

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        origColor = image[sr][sc]
        self.fill(image, sr, sc, origColor, newColor)
        return image

    def fill(self, image: List[List[int]], x: int, y: int, origColor: int, newColor: int):
        # 出界：超出边界索引
        if not self.inArea(image, x, y):
            return
        # 碰壁：遇到其他颜色 超出origColor区域
        if image[x][y] != origColor:
            return
        # 已经走过的路径
        # 我们将已经走过的路径标记为-1
        if image[x][y] == -1:
            return
        
        # 打标记 避免重复
        image[x][y] = -1
        self.fill(image, x, y + 1, origColor, newColor)
        self.fill(image, x, y - 1, origColor, newColor)
        self.fill(image, x + 1, y, origColor, newColor)
        self.fill(image, x - 1, y, origColor, newColor)
        # 将标记替换为newColor
        image[x][y] = newColor
        # 通过两次替换 避免了使用辅助数组
    
    def inArea(self, image: List[List[int]], x: int, y: int) -> bool:
        return x >= 0 and x < len(image) and y >= 0 and y < len(image[0])
    
"""
执行结果：通过
显示详情
执行用时：92 ms, 在所有 Python3 提交中击败了40.10%的用户
内存消耗：15 MB, 在所有 Python3 提交中击败了43.74%的用户
"""
