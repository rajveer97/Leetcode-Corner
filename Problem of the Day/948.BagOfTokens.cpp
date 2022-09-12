class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int ans = 0;
        int n = tokens.size();
        
        int i=0, j=tokens.size()-1;
        while(i<=j)
        {
            if(tokens[i] <= power)
            {
                score++;
                ans = max(ans, score);
                power -= tokens[i++];
            }
            else if(score > 0)
            {
                score -= 1;
                power = power + tokens[j--];
            }
            else
            {
                break;
            }
        }
        
        return ans;
    }
};