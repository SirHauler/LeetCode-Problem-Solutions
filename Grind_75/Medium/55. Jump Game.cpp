class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0; 
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (i > reachable) {
                return false;
            }
            
            reachable = max(reachable, i + nums[i]); 

            if (reachable >= n - 1) {
                // then we can reach the end
                return true;
            }
            
        }

        return false;
    }
};