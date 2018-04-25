class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0){return 0;}
        vector<int> uniquepath(n,0);
        uniquepath[0] = 1;
        for(int i=0; i<m; i++){
            for(int j=1; j<n; j++){
                uniquepath[j] += uniquepath[j-1];
            }
        }
        return uniquepath[n-1];
    }
};