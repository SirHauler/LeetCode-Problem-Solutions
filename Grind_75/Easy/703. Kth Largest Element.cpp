class KthLargest {
public:
    int kth; 
    priority_queue<int, vector<int>, greater<int>> pq; 
    KthLargest(int k, vector<int>& nums) { 
        kth = k; 
        for (auto n: nums) {
            pq.push(n);  // we are saving values in a min_heap()
        }

    }
    
    int add(int val) {
        pq.push(val);

        while (pq.size() > kth) {
            pq.pop(); 
        }
        return pq.top(); 
    }
};