
// Method 1: TLE
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;
                else
                    ans[i] = ans[i]*nums[j];
            }
        }
        
        return ans;
    }
};
// TC :: O(n²) and SC :: O(1)


//-----------------------------------------------------------
// Method 2: 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_product(n);
        vector<int> right_product(n);
        
        left_product[0] = 1;
        for(int i=1; i<n; i++)
        {
            left_product[i] = left_product[i-1] * nums[i-1];
        }
        
        right_product[n-1] = 1;
        for(int i=n-2; i>=0; i--)
        {
            right_product[i] = right_product[i+1] * nums[i+1];
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i] = left_product[i] * right_product[i];
        }
           
        return ans;
    }
};

// TC :: O(n) and SC :: O(n)

















