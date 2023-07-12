
// Top-Down Approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) {
            return 1;
        }

        vector<vector<int>> dp(m, vector(n, -1)); 

        return numPaths(0, 0, m, n, dp) + 1; 
    }

    int numPaths(int i, int j, int m, int n, vector<vector<int>>& dp) {
            if (i == m - 1 && j == n - 1) {
                // you are in the bottom right corner
                return 1; 
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            if (i >= m - 1 || j >= n - 1) {
                return 0;
            }

            return dp[i][j] = 1 + numPaths(i + 1, j, m, n, dp) + numPaths(i, j + 1, m, n, dp);

    }
};