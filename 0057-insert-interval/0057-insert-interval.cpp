class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newinterval) {
         int n=interval.size();

         int i=0,j=0;
         vector<vector<int>> ans;
         if(n==0){
             ans.push_back(newinterval);
             return ans;
         }
         
         while(i<n&&j<1){
                 if(interval[i][1]<newinterval[0]){
                     ans.push_back(interval[i++]);
                     continue;
                 }
            else if(newinterval[1]<interval[i][0]){
                ans.push_back(newinterval);
                j++;
               break;
            }
             int a=min(interval[i][0],newinterval[0]);
            int d=max(newinterval[1],interval[i][1]);
             
                 while(i<n&&interval[i][0]<=d){
                     if(interval[i][0]<=d)
                     d=max(d,interval[i][1]);
                     i++;
                 }

                cout<<i<<d;
                 j++;
                 ans.push_back({a,(d)});
             }

          if(j==0) ans.push_back(newinterval);


         while(i<n){
             ans.push_back(interval[i]);
             i++;
         }
   return ans;
    }
};