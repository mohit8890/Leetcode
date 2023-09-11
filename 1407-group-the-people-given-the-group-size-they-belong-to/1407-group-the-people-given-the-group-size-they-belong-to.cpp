class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Keep track of current group people with required group size
        unordered_map<int,vector<int>> currGrpMembersMap;
        vector<vector<int>> groups;
        for(int i = 0 ; i < groupSizes.size() ; i++ ) {
            vector<int> currGrp;
            // Fetch current group of groupSizes[i] size otherwise create new if no current present
            if( currGrpMembersMap.find(groupSizes[i]) == currGrpMembersMap.end()) {
                currGrp = {};
            } else {
                currGrp = currGrpMembersMap[groupSizes[i]];
            }
            // Add current memeber in group of groupSizes[i] size
            currGrp.push_back(i);
            // If we get groupSizes[i] number of members with groupSizes[i] as required group size
            if(currGrp.size() == groupSizes[i]) {
                groups.push_back(currGrp); // Put this group in answer
                currGrpMembersMap[groupSizes[i]] = {}; // initilise the group with 0 members
            } // Else update group with groupSizes[i] size
            else {
                currGrpMembersMap[groupSizes[i]] = currGrp;
            }
        }
        return groups;
    }
};