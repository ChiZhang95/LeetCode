class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){return vector<int> (1,1);}
        vector<int> p(rowIndex+1,1);
        for(int i = 0; i<rowIndex; i++){
            for(int j=i; j>0; j--){
                p[j] = p[j] + p[j-1];
            }
        }
        return p;
    }
};