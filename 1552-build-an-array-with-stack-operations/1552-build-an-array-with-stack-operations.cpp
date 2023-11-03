class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>v;
        stack<int>st;
      int i=0;int count=1;
      while(i<target.size())
      {
          st.push(count);
          v.push_back("Push");
          count++;
          if(st.top()!=target[i])
          {
              st.pop();
              v.push_back("Pop");

          }
          else{
              i++;

          }

      }
      return v;
        
    }
};