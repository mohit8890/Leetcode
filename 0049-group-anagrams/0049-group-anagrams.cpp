class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int sz=strs.size();
        unordered_map<string,int> smap;
        vector<vector<string>> output;
        int istr=0;
        for(auto& str : strs)
        {
            string s = str;
            sort(s.begin(),s.end());
            if(smap.find(s) ==smap.end()){
                smap[s] = istr;
                output.emplace_back(vector<string>{str});
                istr++;

            }else{
                output[smap[s]].emplace_back(str);
            }
        }
        return output;
        
    }
};