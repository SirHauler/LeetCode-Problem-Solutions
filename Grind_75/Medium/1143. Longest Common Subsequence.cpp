class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));
        return helper(text1, text2, 0, 0, dp);
    }

    int helper(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        } 
        if (dp[i][j] != -1) {
            return dp[i][j]; 
        }
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + helper(text1, text2, i + 1, j + 1, dp); 
            return dp[i][j];
        } else {
            return dp[i][j] = max(helper(text1, text2, i + 1, j, dp), helper(text1, text2, i, j + 1, dp)); 
        }
    }
};