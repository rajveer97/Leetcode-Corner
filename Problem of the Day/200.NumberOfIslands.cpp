class Solution {
public:
    void visited(vector<vector<char>> &grid, int  i, int j,int row,int col)
    {
        if(grid[i][j] == '0')
            return ;
        
        grid[i][j] = '0';
        
        if(i-1 >= 0) visited(grid, i-1, j, row, col);    // Up
        if(i+1 < row) visited(grid, i+1, j, row, col);   // Down
        if(j-1 >= 0) visited(grid, i, j-1, row, col);    // Left
        if(j+1 < col) visited(grid, i, j+1, row, col);   // Right
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    visited(grid, i, j, row, col);
                }
            }
        }
        
        return count;
    }
};