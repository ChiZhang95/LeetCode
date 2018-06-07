#include<stdlib.h>
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0], j = click[1];
        int m = board.size(), n = board[0].size();
        
        // if boom is clicked, game over
        if(board[i][j] == 'M'){
            board[i][j] = 'X';
            return board;
        }
        
        // use DFS to traverse the graph
        DFS(board,i,j,m,n);
        
        return board;
    }
    
    // DFS utility function
    void DFS(vector<vector<char>>& board, int i, int j, int m, int n){
        
        if(board[i][j] == 'E'){
            // A unrevealed space will be marked as revealed blank
            board[i][j] = 'B';
            
            // count number of adjacent booms
            int boom = checkadjacent(board,i,j,m,n);
            string num;
            if(boom > 0){
                num = to_string(boom);
                board[i][j] = num[0];
                return;
            }

            // search around
            for(int row=i-1; row<=i+1; row++){
                for(int col=j-1; col<=j+1; col++){
                    if(row >= 0 && col >= 0 && row <= board.size()-1 && col <= board[0].size()-1){
                        if(!(row == i && col == j)){                           
                            DFS(board,row,col,m,n);
                        }
                    }
                }
            }
        }
        
        return;
    }
    
    // Utility function to count the number of booms around given position
    int checkadjacent(vector<vector<char>>& board, int i, int j, int m, int n){
        int count=0;
        
        for(int row = i-1; row <= i+1; row++){
            for(int col = j-1; col <= j+1; col++){
                if(row >= 0 && col >= 0 && row <= m-1 && col <= n-1){
                    if(board[row][col] == 'M'){
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};