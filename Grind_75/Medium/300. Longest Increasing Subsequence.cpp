class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp (nums.size(), 1); 
        int longest = 1; 
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]); 
                }
            }
            longest = max(dp[i], longest);
        }
        return longest;
    }

};