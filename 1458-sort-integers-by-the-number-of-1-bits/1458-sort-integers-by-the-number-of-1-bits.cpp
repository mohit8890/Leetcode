class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int, multiset<int>> mp;
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i], cnt = 0;
            while (x > 0) {
                if (x & 1) cnt++;
                x = x >> 1;
            }
            mp[cnt].insert(arr[i]);
        }
        
        vector<int> v;
        for (auto x : mp) {
            for (auto y : x.second) {
                v.push_back(y);
            }
        }
        return v;
    }
};
