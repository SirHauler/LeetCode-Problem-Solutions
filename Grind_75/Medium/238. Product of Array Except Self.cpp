class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> right(n);
        vector<int> left(n); 


        int prev = 1; 
        for (int i = 0; i < n; i++) {
            left[i] = prev;
            prev *= nums[i]; 
        }

        prev = 1;
        for (int i = n - 1; i >= 0; i--) {
            right[i] = prev;
            prev *= nums[i]; 
        }

        vector <int> res(n, 1);

        for (int i = 0; i < n; i++) {
            res[i] = left[i] * right[i]; 
        }

        return res; 
    }
};