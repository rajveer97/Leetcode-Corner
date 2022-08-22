class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        
        while(n > 1)
        {
            if(n % 4) return false;
            n = n/4;
        }
        
        return n==1;
    }
};