#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;
class Solution {
//using namespace std    
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Iter(nums1);
        int combIdx = 0;
        int i = 0;
        int j = 0;
        while (combIdx < m + n) {
            if (i < m && j < n) {
                if (nums1Iter[i] < nums2[j]) {
                    nums1[combIdx] = nums1Iter[i];
                    i++;
                } else {
                    nums1[combIdx] = nums2[j];
                    j++;
                }
            } else if (i >= m) {
                nums1[combIdx] = nums2[j];
                j++;
            } else {
                nums1[combIdx] =  nums1Iter[i];
                i++;
            }
            combIdx ++;
        }
    }
};

int main() {
    int m = 5;
    int n = 4;
    vector<int> nums1 = {0, 1, 3, 4, 8, 0, 0, 0, 0};
    vector<int> nums2 = {-3, 0, 1, 9};
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    for (int i : nums1) {
        std::cout << i << std::endl;
    }
    return 0;
}