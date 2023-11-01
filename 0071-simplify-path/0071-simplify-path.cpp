class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i=0;
        while(i<path.size()){
            if(path[i]=='/'){
                string word;
                while(i<path.size() && path[i]=='/')i++;
                while(i<path.size() && path[i]!='/'){
                    word.push_back(path[i++]);

                }
                if(word=="." || word.size()==0)continue;
                if(word==".."){
                    if(!v.empty())v.pop_back();

                }
                else v.push_back(word);

            }
        }
        string ans;
        for(string s:v){
            ans+="/";
            ans+=s;

        }
        if(ans.empty())ans+="/";
        return ans;
    }
};