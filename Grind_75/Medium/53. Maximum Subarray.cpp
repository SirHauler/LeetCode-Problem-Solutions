class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count + nums[i] < nums[i]) {
                count = 0;
            }
            count += nums[i]; 
            largest = max(largest, count);
        }

        return largest;
    }
};