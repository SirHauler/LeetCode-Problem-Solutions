class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cheapestDay = sys.maxsize
        profit, bestProfit = 0, 0
        
        # the approach is to find the lowest day to buy
        # and then progressively check for the highest day to sell
        for i in range(len(prices)): 
            if (prices[i] < cheapestDay): 
                cheapestDay = prices[i]
            profit = prices[i] - cheapestDay
            
            if (profit > bestProfit): 
                bestProfit = profit
            
        return bestProfit

### C++ Solution Below

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestPrice = INT_MAX; 
        int profit = 0; 
        int bestProfit = 0; 
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < bestPrice) {
                bestPrice = prices[i]; 
            }
            
            profit = prices[i] - bestPrice; 
            
            if (profit > bestProfit) { 
                bestProfit = profit; 
            }          
        }
        
        return bestProfit; 
    }
};


