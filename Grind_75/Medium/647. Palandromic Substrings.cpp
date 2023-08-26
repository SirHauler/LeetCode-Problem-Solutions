class Solution {
public:
    int countSubstrings(string s) {
        /*
        Uses expand outward approach. Basically
        pick a char to start at. Then move two points
        away (left and right) from the char, and keep checking
        if they are equal. 
        */
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += expand(s, i, i);
            count += expand(s, i, i+1);
        }
        return count;
    }

    int expand(string s, int left, int right) {
        int count = 0;
        int l = left, r = right;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }



};