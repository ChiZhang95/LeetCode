class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> update = board;
        int neighbor;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                neighbor = board[i][j] == 0? neighbors(board,i,j): neighbors(board,i,j)-1;
                std::cout << neighbor << board[i][j]<< endl;
                if(neighbor < 2 || neighbor > 3){update[i][j] = 0;}
                if(neighbor == 3){update[i][j] = 1;}
            }
        }
        board = update;
    }
    int neighbors(vector<vector<int>> board, int i, int j){
        int n = 0;
        int ru = i-1, rd = i+1, cl = j-1, cr = j+1;
        if(i == 0){ru = i;}
        if(i == board.size()-1){rd = i;}
        if(j == 0){cl = j;}
        if(j == board[0].size()-1){cr = j;}
        for(int r = ru; r <= rd; r++){
            for(int c = cl; c <= cr; c++){
                if(board[r][c] == 1){n++;}
            }
        }
        return n;
    }
};