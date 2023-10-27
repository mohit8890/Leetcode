class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int sc = 0, ec = n, sr = 0, er = n;
        int cnt = 1;
        int row = 0, col = 1, i;
        vector<vector<int>>v( n , vector<int> (n, 0));
        while (cnt <=(n * n))
        {
         
            for (int i = sc; i < ec && cnt <= (n * n); i++)
                v[sr][i] = cnt++;
            col = ec-1;
            for (int i = sr + 1; i < ec && cnt <= (n * n); i++)
                v[i][col] = cnt++;
                ec--;
            for (col = ec - 1; col >= sc && cnt <= (n * n); col--)
                v[er - 1][col] = cnt++;
                er--;
            for (int i = er - 1; i > sc && cnt <= (n * n); i--)
                v[i][sc] = cnt++;
            sc++, sr++;
        }

        return v;
    }
};