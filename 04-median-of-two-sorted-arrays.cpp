/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> mergeNums(nums1.size() + nums2.size());

        int i = 0, j = 0;

        for (int k = 0; k < mergeNums.size(); k ++) {
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])) {
                mergeNums[k] = nums1[i];
                i++;
            } else if (j < nums2.size()) {
                mergeNums[k] = nums2[j];
                j++;
            }
        }

        
        for (int i = 0; i < mergeNums.size(); i++) {
            std::cout << mergeNums[i] << " ";
        }
        
        if (mergeNums.size() % 2 == 0 and mergeNums.size() != 0){
            return (mergeNums[mergeNums.size() / 2 - 1] 
            + mergeNums[mergeNums.size() / 2]) / 2.0;
        } else if (mergeNums.size() != 0)  {
            return (mergeNums[mergeNums.size() / 2]);
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 = {2};
    vector<int> nums2 = {1, 3};

    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Mediana: " << median << endl;

    return 0;
}
