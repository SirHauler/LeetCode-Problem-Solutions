class Solution {
public:


    uint32_t reverseBits(uint32_t n) {
        /*
        Reverse n by using another var, res, which will
        pop on one value from the right most side of n
        at a time.
        */
        uint32_t res = 0;
        uint32_t curr = n;
        for (int i = 0; i < 32; i++) {
            res = res << 1;
            uint32_t mask = curr & 1;
            res |= mask;
            curr = curr >> 1;
        }
        return res;
    }
};