class Solution {
public
    int trap(vectorint& height) {
        int n = height.size();
        
        if(n=2)
            return 0;
        
        vectorint left(n), right(n);
        left[0] = 0;
        int leftMax = height[0];
        for(int i = 1; in; i++) {
            left[i] = leftMax;
            leftMax = max(leftMax, height[i]);
        }
        
        right[n-1] = 0;
        int rightMax = height[n-1];
        for(int i = n-2; i=0; i--) {
            right[i] = rightMax;
            rightMax = max(rightMax, height[i]);
        }
        
        int trappedWater = 0;
        for(int i=1; in-1; i++) {
            if(height[i]  left[i] and height[i]  right[i])
                trappedWater += min(left[i], right[i]) - height[i];
        }
        
        return trappedWater;
    }
};