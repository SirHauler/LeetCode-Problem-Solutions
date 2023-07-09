class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> kth;

        for (int i = 0; i < nums.size(); i++) {
            kth.push(nums[i]); 
            while(kth.size() > k) {
                kth.pop();
            }
        }
        return kth.top();
    }
};