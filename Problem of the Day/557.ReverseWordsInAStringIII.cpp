class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        
        int j = 0;
        int i=0;
        for(i=0; i<n; i++)
        {
            int k = i;
            if(s[k] == ' ')
            {
                k = k-1;
                while(j<=k)
                {
                    swap(s[k--], s[j++]);
                }
                
                j = i+1;
            }
        }
        
        // cout << s[j] <<endl;
        // cout<<s[i-1]<<endl;
        i = i-1;
        
        while(j < i)
        {
            swap(s[i], s[j]);
            i--;
            j++;
        }
        
        
        return s;
    }
};