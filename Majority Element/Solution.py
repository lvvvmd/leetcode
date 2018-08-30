class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        map = {}
        l = len(nums)
        for i in range(l):
            if map.has_key(nums[i]):
                map[nums[i]] += 1
            else:
                map[nums[i]] = 1

        for k, v in map.items():
            if v > l // 2:
                return int(k) 
