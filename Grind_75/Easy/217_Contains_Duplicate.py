class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        save = {}
        for i in range(len(nums)): 
            if (save.get(nums[i]) != None): 
                return True
            else:
                save[nums[i]] = i
        return False