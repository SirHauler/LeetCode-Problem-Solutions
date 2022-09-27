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
        vector<Car> cars;
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