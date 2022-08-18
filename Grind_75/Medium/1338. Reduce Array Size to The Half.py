## Note this is not the best possible solution
## The best solution involves using counting sort (and two extra arrays) to properly sort the values
## before using them regard -> https://www.youtube.com/watch?v=OKd534EWcdk


class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        save = {}
        
        for num in arr: 
            val = save.get(num, 0)
            save[num] = val + 1
                  
        print(save)
        
        s, ans = 0, 0
        for freq in sorted(save.values(), reverse=True): 
            s += freq
            ans += 1
            if (s >= (len(arr)/2)): 
                return ans