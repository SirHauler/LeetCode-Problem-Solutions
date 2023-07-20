class TrieNode {
public: 
    TrieNode *child[26];
    bool isWord;
    
    TrieNode() {
        isWord = false;
        for (auto &a: child) {
            a = nullptr;  // setting all children to nullptr
        }
    }
}; 


class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (char a: word) {
            int idx = a - 'a'; 
            if (!curr->child[idx]) curr->child[idx] = new TrieNode();
            curr = curr->child[idx]; // advance curr
        }
        curr->isWord = true;
    }
    
    bool search(string word, bool prefix=false) {
        TrieNode *curr = root;
        for (char a: word) {
            int idx = a - 'a'; 
            if (!curr->child[idx]) return false;
            curr = curr->child[idx]; 
        }

        if (!prefix) return curr->isWord;
        return true;

    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */