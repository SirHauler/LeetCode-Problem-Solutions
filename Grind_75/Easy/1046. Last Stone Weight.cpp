class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top(); 
            pq.pop(); 

            if (x == y) {
                continue;
            } else {
                int z = (x > y) ? x - y: y - x;
                pq.push(z);
            }

        }

        return pq.empty() ? 0 : pq.top(); 

    }
};