class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> plusone = digits;
        int point = digits.size()-1;
        int flag = 0;
        plusone[point] = (digits[point]+1)%10;
        if((digits[point]+1)/10 > 0){flag = 1;}
        
        while(flag == 1){
            if(point < 0){
                plusone.insert(plusone.begin(),1);
                break;
            }
            plusone[point] = (digits[point]+1)%10;
            if((digits[point]+1)/10 > 0){
                flag = 1;
            }
            else{
                flag = 0;
            }
            point--;
        }
        
        return plusone;
    }
};