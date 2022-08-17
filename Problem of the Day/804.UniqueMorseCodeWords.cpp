class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string alphaString[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                             ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                             "...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string, int> m;
        
        for(int i=0; i<words.size(); i++)
        {
            string temp = "";
            for(int j=0; j<words[i].size(); j++)
            {
                temp += alphaString[words[i][j] - 'a'];
            }
            
            m[temp]++;
        }
        
        return m.size();     
    }
};