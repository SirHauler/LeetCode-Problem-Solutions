

// brute for solution

class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        recurStairs(n, count); 
        return count; 
    }
    
    
    void recurStairs(int n, int &count) {
        for (int i = 1; i < 3; i++) {
            if (n - i < 0) {
                return; 
            } else if (n - i == 0) {
                count++; 
            } else if (n - i > 0) {
                recurStairs(n - i, count); 
            }
            
        }
        return; 
    }
};


// best solution

int climbStairs (int n) {
    int count = 0; 
    map<int, int> m; 
    return recurStairs(n + 1, m) 
    
}
// fibonacci sequence
int recurStairs (int n) {
    if (n <= 1) {
        return n;
    }

    if (m[n] != 0) {
        return m[n]; 
    }

    m[n] = recurStairs(n-1, m) + recurStairs(n-2, m); 

    return m[n]; 
}

// last but not least there is a better solution



int climbStairs(int n) {
    
}