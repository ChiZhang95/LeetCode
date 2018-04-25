class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> minpath(triangle);
        int depth = triangle.size();
        for(int i=0; i<depth; i++){
            for(int j=0; j<i+1; j++){
                if(i == 0){minpath[i][j] = triangle[i][j];}
                else if(j == 0){minpath[i][j] = triangle[i][j] + minpath[i-1][j];}
                else if(j == i){minpath[i][j] = triangle[i][j] + minpath[i-1][j-1];}
                else{minpath[i][j] = triangle[i][j] + min(minpath[i-1][j],minpath[i-1][j-1]);}
            }
        }
        return *min_element( minpath[depth-1].begin(), minpath[depth-1].end());
    }
};