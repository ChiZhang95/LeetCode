class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,int> row;
        map<int,int> col;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(row[i]>0||col[j]>0) matrix[i][j] = 0;
            }
        }
    }
};