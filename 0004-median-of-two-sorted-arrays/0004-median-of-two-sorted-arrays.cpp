class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2=nums2.size();
        int total = n1 + n2;
        int medianIdx = total / 2;
        int i = 0, j = 0;
        double prev = 0, ans = 0;

        for (int count = 0; count <= medianIdx; count++) {
            prev = ans;
            if (i < n1 && j < n2) {
                if (nums1[i] < nums2[j]) {
                    ans = nums1[i];
                    i++;
                }
                else {
                ans = nums2[j];
                j++;
                }
            } 
            else if (i < n1) {
                ans = nums1[i];
                i++;
            }
            else {
                ans = nums2[j];
                j++;
            }
        }

        if (total % 2 == 0) {
            return (prev + ans) / 2.0; // Calculate average for even-sized arrays
        }
        else {
            return ans; // Return the median element for odd-sized arrays
        }
    }
};