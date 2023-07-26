class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0; 
        if (s.size() == 1) return 1; 

        int count = 0;
        int result = 0;

        int front = 0, back = 0;

        set<char> used_chars;
        
        while(front < s.size()) {
            char cur = s[front]; 
            if (used_chars.find(cur) == used_chars.end()) {
                used_chars.insert(cur);
                count++; 
            } else {
                while (s[back] != cur) {
                    used_chars.erase(s[back]); 
                    back++;
                }
                back++;
                result = max(result, count); 
                count = front - back + 1;
            }
            front++;
        }

        result = max(count, result);

        return result; 

    }
};