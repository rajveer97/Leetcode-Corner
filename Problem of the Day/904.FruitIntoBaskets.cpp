class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;

        int i = 0, j = 0, n = fruits.size(), ans = INT_MIN;

        while(j < n){
            mp[fruits[j]]++;
           
            while(mp.size() > 2){
                 ans = max(ans, j-i);
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }

            j++;
        }

        return max(ans,j-i);
    }
};