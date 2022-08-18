class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> m = {}; 
        
        if (s.length() != t.length()) return false; 
        
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++; 
            m[t[i]]--; 
        }
        
        for (auto c: m) {
            if(c.second) return false;
        }
        return true;
        
    }
};



/// Another possible solution that leverages the alphabet


def isAnagram2(self, s, t):
    dic1, dic2 = [0]*26, [0]*26
    for item in s:
        dic1[ord(item)-ord('a')] += 1
    for item in t:
        dic2[ord(item)-ord('a')] += 1
    return dic1 == dic2


