# 此类算法都是靠随机选取元素来获取随机性
# 得到一个在闭区间内的随机整数
def randInt(minValue: int, maxValue: int) -> int:
    pass

# 第一种写法
def shuffle(arr: List[int]):
    n = len(arr)
    for i in range(n):
        # 从i到最后选一个元素
        rand = randInt(i, n - 1)
        arr[i], arr[rand] = arr[rand], arr[i]

# 第二种写法
def shuffle(arr: List[int]):
    n = len(arr)
    for i in range(n - 1):
        rand = randInt(i, n - 1)
        arr[i], arr[rand] = arr[rand], arr[i]
        
# 第三种写法
def shuffle(arr: List[int]):
    n = len(arr)
    for i in range(n - 1, 0, -1):
        rand = randInt(0, i)
        arr[i], arr[rand] = arr[rand], arr[i]
        
# 一个正确的洗牌算法 产生的结果必须有 n! 种可能 否则就是错误的

# 蒙特卡洛方法验证正确性
# 正确性衡量标准：对于每种可能的结果出现的概率必须相等 也就是或要有足够的随机性
