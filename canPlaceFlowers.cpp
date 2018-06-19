class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(i<flowerbed.size()){
            if(flowerbed[i] == 1){
                i += 2;
                continue;
            }
            else if(flowerbed[i] == 0 && i == flowerbed.size()-1){
                n--;
            }
            else if(flowerbed[i] == 0 && flowerbed[i+1] == 0){
                n--;
                i += 2;
                continue;
            }
            i++;
        }
        cout << n << endl;
        return n <= 0? true:false;
    }
};