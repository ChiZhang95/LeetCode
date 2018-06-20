class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m=M.size();
        if(m==0){return M;}
        int n=M[0].size();
        vector<vector<int>> result(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int count=0,num=0;
                for(int r=max(i-1,0); r<=min(i+1,m-1); r++){
                    for(int c=max(j-1,0); c<=min(j+1,n-1); c++){
                        count += M[r][c];
                        num++;
                    }
                }
                result[i][j] = count/num;
            }
        }
        return result;
    }
};