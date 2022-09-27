class Solution {
public:
    int rob(std::vector<int>& nums) {
        int rob1 = 0; 
        int rob2 = 0; 
        
        for (int n = 0; n < nums.size(); n++) {
            int temp = max(rob1 + nums[n], rob2); 
            rob1 = rob2; 
            rob2 = temp;
        }
        return rob2; 
    }
    
    
};