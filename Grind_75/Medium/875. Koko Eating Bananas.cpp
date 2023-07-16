class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // O(n * log(m))  where m -> max in the pile
        int lo = 1; 
        int hi = 0; 
        for (int cur: piles) { 
            hi = max(hi, cur);
        }

        int result = hi;

        while (lo <= hi) {
            // cout << "Lo: " << lo << endl;
            // cout << "Hi: " << hi << endl;
            int mid = lo + (hi - lo) / 2;
            long int time = hours(mid, piles); // calculate time O(n)
            
            if (time <= h) {
                result = min(result, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return result;

    }

    int hours(int k, vector<int>& piles) {
        long int time = 0;
        for (int cur: piles) {
            time += ceil((double) cur / k);
        }
        return time;
    }
};