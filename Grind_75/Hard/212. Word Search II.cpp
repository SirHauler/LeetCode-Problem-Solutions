class TrieNode {
public:
    bool isWord; 
    TrieNode *child[26]; 
    string word;
    TrieNode() {
        isWord = false;
        for (auto &a: child) {
            a = nullptr;
        }
        word = ""; 
    }
}; 


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        TrieNode *root = new TrieNode();
        for (auto word: words) {
            TrieNode *curr = root;
            for (char a: word) {
                int idx = a - 'a'; 
                if (!curr->child[idx]) curr->child[idx] = new TrieNode();
                curr = curr->child[idx]; 
            }
            curr->isWord = true;
            curr->word = word;
        }

        int m = board.size(), n = board[0].size(); 

        int numWords = words.size(); 

        set<string> found;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) { 
                int idx = board[i][j] - 'a'; 
                search(i, j, m, n, board, root, found);
                if (found.size() == numWords) {
                    vector<string> result (found.begin(), found.end());
                    return result;
                }
            }
        }

        vector<string> result (found.begin(), found.end()); 

        return result;
    }


    bool search(int i, int j, int m, int n, vector<vector<char>>& board, TrieNode* root, set<string>& found) {
        
        // out of bounds
        if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || board[i][j] == '*') {
            return false; 
        }

        int idx = board[i][j] - 'a'; 
        root = root->child[idx];
         
        if (!root) return false;

        if (root->isWord) {
            found.insert(root->word);
        }

        
        char c = board[i][j]; 
        board[i][j] = '*'; 

        search(i + 1, j, m, n, board, root, found); 
        search(i - 1, j, m, n, board, root, found);
        search(i, j + 1, m, n, board, root, found);
        search(i, j - 1, m, n, board, root, found);

        board[i][j] = c; 

        return true;
    }
};