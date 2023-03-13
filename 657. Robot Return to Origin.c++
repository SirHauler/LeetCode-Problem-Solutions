#include <vector>;
#include <iostream>;

class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> m = {0, 0};
        for (char s: moves) {
            if (s == 'U') {
                m[0]++; 
            }
                
            if (s == 'D') {
                m[0]--;
            }

            if (s == 'R') {
                ++m[1]; 
            }

            if (s == 'L') {
                --m[1];
            }

        }

        if (m[0] == 0 && m[1] == 0) {
            return true;
        }
        return false;

    }
};
