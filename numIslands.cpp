class Solution {
public:
void DFS(int r,int c,vector<vector<char>>& grid){
    if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()){
        grid[r][c] = '0';
    }

    if(r > 0 && grid[r-1][c] == '1'){
        DFS(r-1,c,grid);
    }
    if(r < grid.size()-1 && grid[r+1][c] == '1'){
        DFS(r+1,c,grid);
    }
    if(c > 0 && grid[r][c-1] == '1'){
        DFS(r,c-1,grid);
    }
    if(c < grid[0].size()-1 && grid[r][c+1] == '1'){
        DFS(r,c+1,grid);
    }
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    DFS(i,j,grid);
                    num++;
                }
            }
        }
        return num;
    }

};