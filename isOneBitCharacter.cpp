class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        if(bits.size()==1) return true;
        while(i<bits.size()){
            if((i==bits.size()-3&&bits[i]==1)||(i==bits.size()-2&&bits[i]==0)) return true;
            else if(i==bits.size()-2&&bits[i]==1) return false;
            if(bits[i] == 0) i++;
            else{i=i+2;}
        }
        return false;
    }
};