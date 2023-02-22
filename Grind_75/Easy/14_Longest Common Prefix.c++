#include <string>; 
#include <iostream>; 

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end()); 

        int len = strs.size(); 

        string beg=strs[0], end=strs[len - 1], res=""; 

        for (int i = 0; i < beg.size(); i++) {
            if (beg[i] == end[i]) {
                res += beg[i]; 
            }
            else {
                break; 
            }
        }
        return res; 

        /*
            we can exploit the structure of the problem
            by only looking at the first and last words, 
            due to the sort 
        */

    }
    
};