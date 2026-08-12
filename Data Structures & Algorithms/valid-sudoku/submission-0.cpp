class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row valid col valid 3* 3 valid
        // row handle
        unordered_map<char,int> mp;
        for(int i=0;  i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                mp[board[i][j]]++;
            }
            for(auto it: mp){
                if(it.second > 1) return false;
            }
            mp.clear();
        }
        // for col
        for(int i=0;  i<9; i++){
            for(int j=0; j<9; j++){
                if(board[j][i] == '.') continue;
                mp[board[j][i]]++;
            }
            for(auto it: mp){
                if(it.second > 1) return false;
            }
            mp.clear();
        }
        // for 3*3 matrix
        for(int i=0;  i<9; i+=3){
            for(int m=0; m<9; m+=3){
                for(int j=i; j<i+3; j++){
                for(int k=m; k<m+3; k++){
                    if(board[j][k] == '.') continue;
                    mp[board[j][k]]++;
                }
            }
            for(auto it: mp){
                if(it.second > 1) return false;
            }
            mp.clear();
            }
            
        }
        return true;

    }
};
