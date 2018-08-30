import numpy as np

class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        nums = np.unique(nums)
        nums = np.sort(nums)
        
        if nums.shape[0] < 3:
            return int(nums[-1])
        else:
            return int(nums[-3])
