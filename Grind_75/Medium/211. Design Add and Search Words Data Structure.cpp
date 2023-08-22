class TrieNode {
public: 
    TrieNode* children[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
    
}; 


class WordDictionary {
public:
    TrieNode* head = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* root = head;
        for (char c: word) {
            int idx = c - 'a'; 
            if (root->children[idx] == NULL) {
                root->children[idx] = new TrieNode();
            }
            root = root->children[idx];
        }
        root->isWord = true;
    }
    
    bool search(string word) {
        return dfs(head, word, 0);
    }

    bool dfs(TrieNode* root, string word, int index) {
        if (index == word.size()) {
            return root->isWord;
        }

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->children[i] != NULL) {
                    if (dfs(root->children[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }
        
        int idx = word[index] - 'a'; 
        if (root->children[idx] == NULL) {
            return false;
        } 
        return dfs(root->children[idx], word, index + 1); 
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */