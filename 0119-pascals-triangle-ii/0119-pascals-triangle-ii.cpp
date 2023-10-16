class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>v;
        vector<int>e;
    for(int i=0;i<=rowIndex;i++)
    {
        vector<int>a;
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i){a.push_back(1);}
            else
            {
                a.push_back(v[i-1][j]+v[i-1][j-1]);
            }

        }
        if(i==rowIndex){return a;}
        v.push_back(a);
    }
    return e;
    }
};