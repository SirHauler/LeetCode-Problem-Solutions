""" The same as House Robber II solution
except we exclude the first value of the array
or the last value and calculate the max from both
of those solutions (this helps us deal with the adjacent
case at the ends of the array)
"""

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if (len(nums) == 1): 
            return nums[0]
        
        try1, try2 = 0, 0
        rob1, rob2 = 0, 0
        for i in range(1, len(nums)):
            temp = rob1 
            rob1 = rob2 + nums[i]
            rob2 = max(temp, rob2)

        try1 = max(rob1, rob2)

        rob1, rob2 = 0, 0

        for i in range(0, len(nums)-1):
            temp = rob1 
            rob1 = rob2 + nums[i]
            rob2 = max(temp, rob2)

        try2 = max(rob1, rob2)

        return max(try1, try2)
