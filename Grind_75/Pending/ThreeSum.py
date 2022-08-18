##### Thrown here for now 
### There is a better solutions so look into that
### involves a O(n^2) solution that uses left and right counters to check
### all combinations for a fixed values but all duplicate values next to each
## other are skipped in order to optimize!


#### Medium ####

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        save = {}
        result = []
        
        for i in range(len(nums)): 
            save[nums[i]] = i
        
        for i in range(len(nums)): 
            for j in range(1, len(nums)): 
                sum = nums[i] + nums[j]
                if (save.get(-sum) != None): 
                    sol = []
                    sol.append(nums[i])
                    sol.append(nums[j])
                    sol.append(-sum)
                    result.append(sol)
                    
        return result
                