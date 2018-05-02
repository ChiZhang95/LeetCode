class Solution {
public:
    int numTrees(int n) {
        vector<int> numtree(n+1,0);
        numtree[0] = 1;
        numtree[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                numtree[i] += numtree[j]*numtree[i-j-1];
            }
        }
        return numtree.back();
    }
};