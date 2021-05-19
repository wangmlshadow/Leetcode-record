# 第20
"""
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
"""

class Solution:
    def isValid(self, s: str) -> bool:
        # 使用栈求解
        left_stack = list()
        for c in s:
            if c == '(' or c == '{' or c == '[':# 左括号
                left_stack.append(c)# 入栈
            else:# 右括号
                if left_stack and self.leftOf(c) == left_stack[-1]:
                    left_stack.pop()# 出栈
                else:
                    return False
        # 是否所有左括号都被匹配
        return len(left_stack) == 0
                
    def leftOf(self, c: str) -> str:
        if c == '}':
            return '{'
        if c == ')':
            return '('
        return '['
    
"""
执行结果：通过 显示详情 添加备注
执行用时：48 ms, 在所有 Python3 提交中击败了26.11%的用户
内存消耗：14.9 MB, 在所有 Python3 提交中击败了44.55%的用户
"""
