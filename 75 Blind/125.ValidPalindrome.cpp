class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        string curr = ""; 
        for(int i=0; i<s.size(); i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            {
                curr += s[i];
            }
        }
        
        string str2 = curr;
        reverse(curr.begin(), curr.end());
        
        return curr == str2;
    }
};