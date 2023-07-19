// BFS & Backtracking

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size(); 
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(i, j, m, n, board, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    
    }


    bool search(int i, int j, int m, int n, vector<vector<char>>& board, string& word, int idx) {
        if (idx == word.size()) {
            return true;
        }

        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || board[i][j] != word[idx]) {
            return false;
        }

        char c = board[i][j]; 
        board[i][j] = '*'; 
        bool left = search(i, j - 1, m, n, board, word, idx + 1);
        bool right = search(i, j + 1, m, n, board, word, idx + 1); 
        bool up = search(i - 1, j, m, n, board, word, idx + 1); 
        bool down = search(i + 1, j, m, n, board, word, idx + 1);
        board[i][j] = c;

        return left || right || up || down;
    }
};