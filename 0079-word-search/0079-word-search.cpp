class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int len){
        if(word.size() == len) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if(board[i][j] != word[len]) return false;
        
        char ch = board[i][j];
        board[i][j] = '#';
        
        bool ans = (dfs(i+1, j, board, word, len+1) ||
           dfs(i, j+1, board, word, len+1) ||
           dfs(i-1, j, board, word, len+1) || 
           dfs(i, j-1, board, word, len+1));
        
        board[i][j] = ch;
        
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};