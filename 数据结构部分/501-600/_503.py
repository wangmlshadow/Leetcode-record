class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        cnt = len(nums)
        res = [-1] * cnt
        s = []
        # 既要考虑后面的元素 也要考虑前面的元素
        # 假装数组长度翻倍了
        for i in range(2 * cnt - 1, -1, -1):
            while s and s[-1] <= nums[i % cnt]:
                s.pop()
            res[i % cnt] = s[-1] if s else -1
            s.append(nums[i % cnt])
        return res
"""
执行结果：通过显示详情
执行用时：316 ms, 在所有 Python3 提交中击败了26.60%的用户
内存消耗：15.1 MB, 在所有 Python3 提交中击败了24.78%的用户
"""
