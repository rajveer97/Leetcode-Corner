class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;

        for(int i=0; i<order.size(); i++) {
            mp[order[i]] = i;
        }

        for(int i=0; i<words.size()-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];

            int j = 0;
            while(j<s1.size() && j<s2.size() && s1[j] == s2[j])
                j++;
            
            if((j == s2.size() && j != s1.size()) || (mp[s1[j]] > mp[s2[j]])) {
                return false;
            }
        }

        return true;
    }
};