class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> storage; 

        if (nums.size() == 0) return 0;

        // storing numbers
        for (int n: nums) {
            storage.insert(n); 
        }

        int max = 0; 
        for (auto s: storage) { 
            int count = 1;
            int i = 1; 
            if (storage.find(s - 1) == storage.end()) {
                while (storage.find(s + i) != storage.end()) {
                    count++; 
                    i++;
                }
                if (count > max) {
                    max = count; 
                } 
            }
        }

        return max;
    }
};