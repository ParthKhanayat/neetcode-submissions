class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowSeen;
        vector<unordered_set<char>> colSeen(9);
        unordered_set<char> box1Seen;
        unordered_set<char> box2Seen;
        unordered_set<char> box3Seen;
        for(int i=0;i<board.size();i++)
        {
            // i-> rows, j->cols
            if(i%3==0)
            {
                box1Seen.clear();
                box2Seen.clear();
                box3Seen.clear();
            }
            for(int j=0;j<board[i].size();j++)
            {
                char c=board[i][j];
                if(c=='.')
                {
                    continue;
                }
                else if(rowSeen.find(c)!=rowSeen.end() ||
                    colSeen[j].find(c)!=colSeen[j].end()
                )
                {
                    return false;
                }
                rowSeen.insert(c);
                colSeen[j].insert(c);
                if(j<3)
                {
                    if(box1Seen.find(c)!=box1Seen.end())
                    {
                        return false;
                    }
                    box1Seen.insert(c);
                }
                else if(j<6)
                {
                    if(box2Seen.find(c)!=box2Seen.end())
                    {
                        return false;
                    }
                    box2Seen.insert(c);
                }
                 else if(j<9)
                {
                    if(box3Seen.find(c)!=box3Seen.end())
                    {
                        return false;
                    }
                    box3Seen.insert(c);
                }
            }
            rowSeen.clear();
        }
        return true;
    }
};
