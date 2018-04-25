class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size();
        vector<vector<int>> minsum(row,vector<int>(col,0));
        if(row == 0){return 0;}
        if(row == 1 && col == 1){return grid[0][0];}
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i == 0 && j == 0){minsum[i][j] = grid[i][j];}
                else if(i == 0){minsum[i][j] = minsum[i][j-1] + grid[i][j];}
                else if(j == 0){minsum[i][j] = minsum[i-1][j] + grid[i][j];}
                else{minsum[i][j] = grid[i][j] + min(minsum[i-1][j],minsum[i][j-1]);}
            }
        }
        return minsum[row-1][col-1];
    }
};