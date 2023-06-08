class Car {
public:
    Car(int pos, int speed) {
        this->pos = pos; 
        this->speed = speed;
    }
    int speed; 
    int pos;
};

class Solution {
public:
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars; // could be achieved with pair<int, int>
        for (int i = 0; i < position.size(); i++){
            cars.emplace_back(position[i], speed[i]); 
        }
        
        sort(cars.begin(), cars.end(), [](const Car &a, const Car &b) {
            return a.pos < b.pos;
        }); 
        
        stack<float> mono; 
        
        for (int i = 0; i < position.size(); i++) {
            float time = (target - cars[i].pos) / (float) cars[i].speed;
            while (!mono.empty() && time >= mono.top()) {
                mono.pop();
            }
            mono.push(time);
        }
        return mono.size(); 
    }
};

// another solution using map and stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // one solution uses map
        int n = position.size(); 
        vector<double> steps (n); 
        
        if (n == 0) {
            return 0;
        }

        map<int, int> mp; 
        for (int i = 0; i < n; i++) {
            mp[position[i]] = speed[i]; 
        }

        int i = 0;
        for (const auto& [key, value] : mp) {
            int tgt = target - key; 
            double step = (double) tgt / value;
            steps[i] = step; 
            i++; 
        }

        stack<double> stk;
        stk.push(steps[n - 1]); 
        for (int i = n - 2; i >= 0; i--) {
            double cur = steps[i];
            double top = stk.top(); 
            if (cur > top) {
                stk.push(cur);
            } else {
                continue;
            }
        }

        return stk.size();

        // runtime: O(n * log(n))


    }
};