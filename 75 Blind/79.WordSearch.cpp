class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int r = board.size();
        int c = board[0].size();
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(adjacentSearch(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
    
    bool adjacentSearch(vector<vector<char>>& board, 
                        string word, int i, int j, int index)
    {
        if(index == word.size())    // end condition
            return true;
        
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1)
            return false;
        
        // Do not match
        if(board[i][j]!=word[index])
            return false;
        
        // Matched
        board[i][j] = '*';
        
        bool furtherSearch = adjacentSearch(board, word, i-1, j, index+1) || // up
                             adjacentSearch(board, word, i+1, j, index+1) || // down
                             adjacentSearch(board, word, i, j-1, index+1) || // left
                             adjacentSearch(board, word, i, j+1, index+1);   // right
        
        board[i][j] = word[index];  // modify it back!
        
        return furtherSearch;
    }
    
};
