class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> mp; 
        
        for (string s: strs) {
            string sorted = s;
            std::sort(sorted.begin(), sorted.end());
            vector<string> cur = mp[sorted]; 
            cur.push_back(s); 
            mp[sorted] = cur;
        }

        vector<vector<string>> res;
        for (const auto& [key, value] : mp) {
            res.push_back(value);
        }

        return res;

    }


    // SECONDARY SOLUTION WITH BETTER RUNTIME, but worse SPACE USAGE


class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> mp; 

        for (auto word: strs) {
            string key = getKey(word); 
            mp[key].push_back(word);
        }

        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }

        return res;
    }


    string getKey(string word) {

        vector<int> alph (26);

        for (int i = 0; i < word.size(); i++) {
            alph[word[i] - 'a']++;
        }

        string key = "";
        for (int i = 0; i < 26; i++) {
            // can be anything that is a unique descriptor of this anagram!
            key.append(to_string(alph[i]) + to_string(i + 'a'));  
        }

        return key;
    }
};



};