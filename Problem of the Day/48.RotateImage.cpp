class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0; i<row; i++)
        {
            for(int j=i; j<col; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        
        for(int i=0; i<row; i++)
        {
            int f = 0;
            int l = col-1;
            
            while(f < l)
            {
                swap(matrix[i][f], matrix[i][l]);
                f++;
                l--;
            }
        }
        
    }
};