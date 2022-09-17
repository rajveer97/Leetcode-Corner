// Method 1: TLE 
/*
class Solution {
public:
    bool isPalindrome(string str)
    {
        string rev = str;
        reverse(str.begin(), str.end());
        
        return (rev == str);
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        for(int i=0; i<words.size(); i++)
        {
            for(int j=0; j<words.size(); j++)
            {
                if(i == j) continue;
                
                string check = words[i] + words[j];
                if(isPalindrome(check))
                    ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};
*/

//-------------------------------------------------------------------------

// Method 2: Using Trie
struct TrieNode
{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};
class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index)
    {
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr)
                continue;
            for (int j : cur->wordIndex)
            {
                if (i == j)
                    continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};

// Time Complexity: O(n * k^2) where n is the number of words and k is 
// the length of the longest word
// Space Complexity: O(n * k)