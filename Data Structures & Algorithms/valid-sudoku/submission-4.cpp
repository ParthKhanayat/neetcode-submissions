class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int , set<char>> rows;
        unordered_map<int , set<char>> cols;
        unordered_map<int , set<char>> boxes; //(r//3,c//3) is the key here
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                int boxIndex=(i/3)*3+(j/3);
                if(board[i][j]=='.')
                {
                    continue;
                }
                if(rows[i].find(board[i][j])!=rows[i].end() || 
                    cols[j].find(board[i][j])!=cols[j].end() ||
                    boxes[boxIndex].find(board[i][j])!= boxes[boxIndex].end() )
                    {
                        return false;
                    }
                else
                {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[boxIndex].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
