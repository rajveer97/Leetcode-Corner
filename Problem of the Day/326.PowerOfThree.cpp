// Method 1: Loop (O(log3(n)))
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n > 1)
        {
            if(n%3 != 0) return false;
                
            n = n/3;    
        }
        
        return true;
    }
};

//-------------------------------------------
// Method 2: Recursive

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 1) return n==1;
        
        return (n%3 == 0) && isPowerOfThree(n/3);    
    }
};
