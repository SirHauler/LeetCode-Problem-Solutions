// APPROACH 1: Try all combinations from, start with 
// outmost characters and then move inwards.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max = -1;
        string result = ""; 
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                int l = j - i + 1; 
                if (isPalandromic(s, i, j)) {
                    int length = j - i + 1;
                    if (length > max) {
                        result = s.substr(i, length); 
                        max = length;
                    }
                }
            }
        }

        return result;
    }


    bool isPalandromic(string& s, int i, int j) {
        while(i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }
};