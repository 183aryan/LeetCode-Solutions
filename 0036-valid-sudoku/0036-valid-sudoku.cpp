class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int sub_matrix[9][9] = {0};
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.') continue;
                
                int x = board[i][j] - '0' - 1;
                int k = i / 3 * 3 + j / 3;
                if(row[i][x] || col[j][x] || sub_matrix[k][x]) return false;
                
                row[i][x] = 1;
                col[j][x] = 1;
                sub_matrix[k][x] = 1;
            }
        }
        return true;
    }
};