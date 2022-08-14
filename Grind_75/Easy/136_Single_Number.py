
## This Solution Leverages the XOR Operator and its 
# Communative Property. This property means that
# any modif. made to the xor var will be undone if there
# pairs for every value, and will equal the singleton
# in all other cases.

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xor = 0
        for i in range(len(nums)): 
            xor ^= nums[i]            
        return xor