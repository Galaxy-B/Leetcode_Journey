from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        val2idx = {}

        for i in range(len(nums)):
            diff = target - nums[i]

            # 记录出现过的元素 便于直接通过差值索引其下标
            if diff in val2idx:
                return [val2idx[diff], i]
            else:
                val2idx[nums[i]] = i

        return [0, 0]  # unreachable
