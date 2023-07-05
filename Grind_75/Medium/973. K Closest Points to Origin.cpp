class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<double>> pq;

        for (vector<int> p: points) {
            double dist = sqrt((p[0] * p[0]) + (p[1] * p[1])); 
            pq.push({dist, static_cast<double>(p[0]), static_cast<double>(p[1])});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            vector<double> temp = pq.top(); 
            pq.pop();
            res.push_back({static_cast<int>(temp[1]), static_cast<int>(temp[2])}); 
        }

        return res; 
    }
};