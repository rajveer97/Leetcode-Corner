class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> mxheap;
        int mini=INT_MAX,diff=INT_MAX;
        for(auto it:nums){
            if(it%2!=0) it*=2;
            mini=min(mini,it);
            mxheap.push(it);
        }
        while(mxheap.top()%2==0){
            int mx=mxheap.top();
            mxheap.pop();
            diff=min(diff,mx-mini);
            mini=min(mini,mx/2);
            mxheap.push(mx/2);
        }
        return min(diff,mxheap.top()-mini);
    }
};