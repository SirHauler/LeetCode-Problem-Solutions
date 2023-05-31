class Solution {
public:

    /*
    
    Keep a stack of the values and only remove when you find a greater value than the top. 
    At which point we take the difference in the indices and store them in the resulting
    array. This solution uses a counting method instead but idealy the indices should be stored
    alone with the value instead of a count.

    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res (n); 
        stack<pair<pair<int, int>, int>> stk;  
        for (int i = 0; i < n; i++) {
            
            if (!stk.empty()) {
                stk.top().second++;
            }


            while (!stk.empty()) {
                // remove all smaller vals
                pair<pair<int, int>, int> tmp = stk.top();
                int val = tmp.first.first; 
                if (val < temperatures[i]) {
                    int count = tmp.second;

                    // remove the value
                    stk.pop(); 

                    // add value to the result
                    int index = tmp.first.second;
                    res[index] = count;

                    // add that values count to the next val if applicable
                    if (!stk.empty()) {
                        stk.top().second += count;
                    }
                    

                } else {
                    break;
                }
            }

            if (stk.empty() || stk.top().first.first >= temperatures[i]) {
                pair<int, int> p1 = make_pair(temperatures[i], i);
                stk.push(make_pair(p1, 0)); 
            }
        }

        while(!stk.empty()) {
            cout << stk.top().second << endl;
            stk.pop();
        }

        return res;
    }
};