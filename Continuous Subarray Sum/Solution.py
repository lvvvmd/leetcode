class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        map = {}
        map[0] = -1
        sum = 0
        for i in range(len(nums)):
            sum += nums[i]
            if k == 0:
                mod_v = sum
            else:
                mod_v = sum % k
            if map.has_key(mod_v):
                prev = map[mod_v]
                if i - prev > 1:
                    return True
            else:
                map[mod_v] = i

        return False
