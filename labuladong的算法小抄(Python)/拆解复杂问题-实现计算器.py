# 实现一个功能完备的计算器功能 关键在于层层拆解问题 化整为零 逐个击破
# 1.字符串转整数
# 将一个字符串形式的正整数转化为int
# C++
"""
    string s = "458";

    int n = 0;
    for (auto c : s) {
        n = 10 * n + (c - '0');
    }

    cout << "n = " << n << endl;
"""
# 注意：n = 10 * n + (c - '0');
# 括号不能省略 因为变量 c 是一个ASCII码 如果不加括号 按照运算顺序先加后减 有可能造成整形溢出

# 2.处理加减法
# cpp
# 步骤：
# 给第一个数字加上默认符号 +
# 将一个运算符 一个数字 组成一对 将它们转化为数字 然后放到一个栈中
# 将栈中所有数字求和 就是原算式的结果
def calculate(s: str) -> int:
    # 使用list当作stack
    stk = list()
    # 记录算式中的数字
    num = 0
    # 记录num前的符号 初始化为 +
    sign = '+'
    for i, c in enumerate(s):
        # 如果是数字 连续读取到num
        if c.isdigit():
            num = 10 * num + (ord(c) - ord('0'))
        # 如果不是数字 就是遇到了下一个符号
        # 之前的数字和符号就要存进栈中
        if not c.isdigit() or i == len(s) - 1:
            if sign == '+':
                stk.append(num)
            else:
                stk.append(-num)
            # 更新符号为当前符号 数字清零
            sign = c
            num = 0
    # 将栈中所有结果求和就是答案
    res = 0
    while len(stk) != 0:
        res += stk[-1]
        stk.pop()
    return res
  
# 处理乘除法
def calculate(s: str) -> int:
    # 使用list当作stack
    stk = list()
    # 记录算式中的数字
    num = 0
    # 记录num前的符号 初始化为 +
    sign = '+'
    for i, c in enumerate(s):
        # 如果是数字 连续读取到num
        if c.isdigit():
            num = 10 * num + (ord(c) - ord('0'))
        # 如果不是数字 就是遇到了下一个符号
        # 之前的数字和符号就要存进栈中
        if not c.isdigit() or i == len(s) - 1:
            if sign == '+':
                stk.append(num)
            elif sign == '-':
                stk.append(-num)
            # 只需要拿出前一个数字做对应运算即可
            # 乘除法优先于加减法体现在 乘除法可以和栈顶元素结合 而加减法只能把自己放入栈中
            elif sign == '*':
                pre = stk[-1]
                stk.pop()
                stk.append(pre * num)
            else:# /
                pre = stk[-1]
                stk.pop()
                stk.append(pre / num)
            # 更新符号为当前符号 数字清零
            sign = c
            num = 0
    # 将栈中所有结果求和就是答案
    res = 0
    while len(stk) != 0:
        res += stk[-1]
        stk.pop()
    return res

# 处理空格 
# 出现空格会影响 if not c.isdigit() or i == len(s) - 1:
# 因此处理这一部分即可
def calculate(s: str) -> int:
    # 使用list当作stack
    stk = list()
    # 记录算式中的数字
    num = 0
    # 记录num前的符号 初始化为 +
    sign = '+'
    for i, c in enumerate(s):
        # 如果是数字 连续读取到num
        if c.isdigit():
            num = 10 * num + (ord(c) - ord('0'))
        # 如果不是数字 就是遇到了下一个符号
        # 之前的数字和符号就要存进栈中
        if (not c.isdigit() and c != ' ') or i == len(s) - 1:
            if sign == '+':
                stk.append(num)
            elif sign == '-':
                stk.append(-num)
            # 只需要拿出前一个数字做对应运算即可
            # 乘除法优先于加减法体现在 乘除法可以和栈顶元素结合 而加减法只能把自己放入栈中
            elif sign == '*':
                pre = stk[-1]
                stk.pop()
                stk.append(pre * num)
            else:# /
                pre = stk[-1]
                stk.pop()
                stk.append(pre / num)
            # 更新符号为当前符号 数字清零
            sign = c
            num = 0
    # 将栈中所有结果求和就是答案
    res = 0
    while len(stk) != 0:
        res += stk[-1]
        stk.pop()
    return res

# 处理括号
# 利用括号的递归性质进行处理
# 
from typing import List
def calculate(s: str) -> int:
    
    def helper(s: List) -> int:
        stack = []
        sign = '+'
        num = 0
        
        while len(s) > 0:
            c = s.pop(0)
            if c.isdigit():
                num = 10 * num + int(c)
            # 遇到左括号开始递归计算 num
            if c == '(':
                #print('(')
                num = helper(s)
            
            if (not c.isdigit() and c != ' ') or len(s) == 0:
                if sign == '+':
                    #print(f'+ {num}')
                    stack.append(num)
                elif sign == '-':
                    #print(f'- {num}')
                    stack.append(-num)
                elif sign == '*':
                    #print(f'* {num}')
                    stack[-1] = stack[-1] * num
                elif sign == '/':# /
                    #print(f'/ {num}')
                    stack[-1] = int(stack[-1] / float(num))
                # 更新符号为当前符号 数字清零
                sign = c
                num = 0
            
            # 遇到右括号 返回递归结果
            if c == ')':
                #print(')')
                break
        return sum(stack)
    
    return helper(list(s))
