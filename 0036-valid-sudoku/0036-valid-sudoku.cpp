class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        // Row Check
        for(auto row:board)
            for(int i=0; i<9; i++)
                if(count(row.begin(), row.end(), row[i]) > 1 && row[i] != '.')
                    return false;


        // Column Check
        unordered_map<int, int> map;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[j][i] != '.' && ++map[board[j][i]] > 1)
                    return false;
            }
            map.clear();
        }


        // Grid check
        for(int i=0; i<=8; i+=3)
        {
            for(int j=0; j<=8; j+=3)
            {
                for(int l=0; l<=2; l++)
                {
                    for(int k=0; k<=2; k++)
                    {
                        if(board[i+l][j+k] != '.' && ++map[board[i+l][j+k]] > 1)
                        {
                            return false;
                        }
                    }
                }

                map.clear();
            }
        }

        return true; 
    }
};