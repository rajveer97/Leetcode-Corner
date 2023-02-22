class Solution {
public:

    bool isPossible(vector<int> &weights, int days, int mid) 
    {
        int sum = 0;
        int countDays = 1;
        int sz = weights.size();

        for(int i=0; i < sz; i++) {
            sum += weights[i];

            if(sum > mid) {
                countDays++;
                sum = weights[i];
            }
        }

        return (countDays <= days);

    }




    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = 0;
        int sz = weights.size();

        for(int i=0; i<sz; i++) {
            sum += weights[i];
            maxi = max(maxi, weights[i]);
        }

        int lo = maxi;
        int high = sum;
        int ans = 0;

        while(lo <= high) {
            int mid = lo + (high - lo)/2;

            if(isPossible(weights, days, mid) == true) {
                ans = mid;
                high = mid - 1;
            }
            else 
                lo = mid + 1;
        }

        return ans;
    }
};