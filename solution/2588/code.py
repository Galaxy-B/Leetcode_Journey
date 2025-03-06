from typing import List
from collections import defaultdict

class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        # count记录遍历过程中每个异或值出现的次数 初始化时考虑空串
        count, ans, xor = defaultdict(int), 0, 0
        count[0] = 1

        # 若nums[0,i)的异或为x 且nums[0,j)的异或为x 则nums[i,j)是美丽子数组
        for num in nums:
            xor ^= num
            ans += count[xor]
            count[xor] += 1
        
        return ans
