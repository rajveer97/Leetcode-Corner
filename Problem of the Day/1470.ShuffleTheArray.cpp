class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;

        int i = 0, j = n;
        bool flag = true;

        while(j < 2*n) {
            if(flag == true) {
                ans.push_back(nums[i]);
                flag = false;
                i = i+1;
            } else {
                ans.push_back(nums[j]);
                flag = true;
                j = j+1;
            }
        }

        return ans;
    }
};