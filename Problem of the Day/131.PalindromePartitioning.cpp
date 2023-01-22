class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }

        return true;
    }

    void findpaths(int start, string &s, vector<vector<string>> &ans, vector<string> &path) {
        if(start == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int i=start; i<s.size(); i++) {
            if(isPalindrome(s, start, i) == true)    // (string, start, end)
            {   
                path.push_back(s.substr(start, i - start + 1));
                findpaths(i+1, s, ans, path);
                path.pop_back();   // backtracking
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> ans;
        vector<string> path;
        findpaths(0, s, ans, path);  // (starting index, given string, ans, path)
        return ans;
    }
};