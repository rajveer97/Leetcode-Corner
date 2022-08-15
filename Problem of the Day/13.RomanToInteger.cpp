class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                      {'C', 100}, {'D', 500}, {'M', 1000}};
        
        
        for(int i=0; i<s.length(); i++)
        {
            int curr = m[s[i]];
            
            int next = m[s[i+1]];
            
            if(curr >= next)
                ans += curr;
            
            else 
                ans -= curr;
        }
        
        return ans;
    }
};