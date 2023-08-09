class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // update until there are no more new rotten oranges
        // check if there is a valid 

        queue<pair<int, int>> new_rotten;

        int fresh = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    new_rotten.push(make_pair(i, j));
                } 
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int count = 0; 
        while(!new_rotten.empty()) {
            int batch_size = new_rotten.size();
            while(batch_size > 0) {
                pair<int, int> idx = new_rotten.front();
                new_rotten.pop();
                neighbors(grid, new_rotten, idx.first, idx.second, fresh);
                batch_size--;
            }

            if (!new_rotten.empty()) count++;
        }


        return (fresh == 0) ? count : -1;
        
    }

    void neighbors(vector<vector<int>>& grid, queue<pair<int, int>>& new_rotten, int i, int j, int& fresh) {
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            grid[i + 1][j] = 2; 
            new_rotten.push(make_pair(i + 1, j)); 
            fresh--;
        }

        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            grid[i - 1][j] = 2;
            new_rotten.push(make_pair(i - 1, j)); 
            fresh--;
        }

        if (j+ 1 < grid[0].size() && grid[i][j + 1] == 1) {
            grid[i][j + 1] = 2; 
            new_rotten.push(make_pair(i, j + 1)); 
            fresh--;
        }

        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            grid[i][j - 1] = 2;
            new_rotten.push(make_pair(i, j - 1)); 
            fresh--;
        }
    }
};