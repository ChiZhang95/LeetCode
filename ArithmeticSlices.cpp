class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3) return 0;
        int p=-1,q=-1,count=0;
        for(int i=0; i<A.size()-2; i++){
            if(A[i+1] - A[i] == A[i+2] - A[i+1]){
                if(p==-1){p = i;}
                q = i+2;
                if(i == A.size()-3){
                    count += (q-p-1)*(q-p)/2;
                    break;
                }
            }
            else{
                if(p!=-1) {
                    count += (q-p-1)*(q-p)/2;
                    p = -1;
                    q = -1;
                }
            }
        }

        return count;
    }
};