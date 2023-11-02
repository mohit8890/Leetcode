class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        char ans =arr[0];
        int si =0 , ei =arr.size()-1;
        while(si<=ei){
            int mid =si +(ei-si)/2;
            if (arr[mid]>target){
                ans = arr[mid];
                ei =mid-1;

            }else si = mid+1;

        }
        return ans;
        
    }
};