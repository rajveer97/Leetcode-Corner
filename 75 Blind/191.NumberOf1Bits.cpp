class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int help = 1;
        while(n > 0)
        {
            if(n & help)
                count++;
            
            n = n>>1;
        }
        
        return count;
    }
};