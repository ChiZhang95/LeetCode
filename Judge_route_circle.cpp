class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> pos = {0,0};
        for(int i=0; i<moves.size(); i++){
            if(moves[i] == 'U'){
                pos[1] += 1;
            }
            else if(moves[i] == 'D'){
                pos[1] += -1;
            }
            else if(moves[i] == 'L'){
                pos[0] += -1;
            }
            else{
                pos[0] += 1;
            }
        }
        return pos[0] == 0 && pos[1] == 0 ? true : false;
    }
};