# sqrt(n)
# 逐一判断每个数是否为素数不够高效
# 排除法

def countPrimes(n: int) -> int:
    isPrim = [True for _ in range(n)]
    for i in range(2, int(math.sqrt(n))):# 此处只需要到sqrt(n)
        if isPrim[i]:
            # 此处从i * i开始 
            for j in range(i * i, n, i):# i的整数倍都不是素数 
                isPrim[j] = False
    count = 0
    for i in range(2, n):
        if isPrim[i]:
            count += 1
    return count
