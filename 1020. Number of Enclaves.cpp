class Solution {
public:
    void bfs (int i, int j, vector<vector<int>>& grid) { 
        if (i < 0 || j < 0 || j == grid[i].size() || i == grid.size() || grid[i][j] != 1)       {return;    }
        grid[i][j] = 0;  // mark the area as water
        bfs(i + 1, j, grid);
        bfs(i, j + 1, grid); 
        bfs(i - 1, j, grid); 
        bfs(i, j - 1, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid[0].size(); 
        int n = grid.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        bfs(i, j, grid);
                    }
                    
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {cnt++;}
            }
        }

        return cnt;  
    }

};