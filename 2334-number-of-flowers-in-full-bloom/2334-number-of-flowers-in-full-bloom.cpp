class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>st,bl;
        int n=flowers.size();
        for(auto i:flowers)
        {
            int x=i[0];
            int y=i[1];
            st.push_back(x);
            bl.push_back(y);
        }
        sort(st.begin(),st.end());
        sort(bl.begin(),bl.end());
        vector<int>v;
        for(int i=0;i<people.size();i++)
        {
            int p=st.size()-(upper_bound(st.begin(),st.end(),people[i])-st.begin());
            int q=bl.size()-(lower_bound(bl.begin(),bl.end(),people[i])-bl.begin());
            v.push_back(q-p);
        }
        return v;
    }
};