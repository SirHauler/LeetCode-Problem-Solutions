class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_dict = {}
        for i in range(len(nums)): 
            remainder = target - nums[i]
            if (num_dict.get(remainder) != None): 
                return [i, num_dict[remainder]]
            else: 
                num_dict[nums[i]] = i          


              

