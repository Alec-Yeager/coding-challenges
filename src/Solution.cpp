#include <stdio.h>
#include <vector>
#include <iostream>


using namespace std;
class Solution {
//using namespace std    
public:
    // 88
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

    // 27
    int removeElement(vector<int>& nums, int val) {
        int kIdx = 0;
        for (auto it : nums) {
            if (it != val) {
                nums[kIdx] = it;
                kIdx++;
            }
        }
        return kIdx;
    }

    //26
    int removeDuplicates26(vector<int>& nums) {
        int kIdx = 1;
        int prev = nums[0];
        for (auto i : nums) {
            if (i != prev) {
                nums[kIdx] = i;
                kIdx++;
            }
            prev = i;
        }
        return kIdx;
    }

    //80
    int removeDuplicatesSlow(vector<int>& nums) {
        int kIdx = 1;
        int prev = nums[0];
        bool firstStrike = true;
        for (auto it = nums.begin() + 1; it != nums.end(); it++) {
            int i = *it;
            if (i != prev) {
                nums[kIdx] = i;
                kIdx++;
                firstStrike = true;
            }
            else if (firstStrike) {
                nums[kIdx] = i;
                kIdx++;
                firstStrike = false;
            }
            prev = i;
        }
        return kIdx;
    }

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int mIdx = 2;
        int kIdx = 2;
        int offByTwoPrev = nums[0];
        while (mIdx < nums.size()) {
            if (nums[mIdx] != offByTwoPrev) {
                offByTwoPrev = nums[mIdx - 1];
                nums[kIdx] = nums[mIdx];
                kIdx++;
            } else {
                offByTwoPrev = nums[mIdx - 1];
            }
            mIdx++;
        }
        return kIdx;
    }

};

int main() {
    int m = 5;
    int n = 4;
    vector<int> nums1 = {0, 1, 1, 3, 3, 3, 4, 8, 0, 0, 0, 0, 5};
    vector<int> nums2 = {1, 1, 1, 2, 2, 3};
    vector<int> numsSingular = {2, 2, 2, 2, 2};
    Solution sol;
    int k = sol.removeDuplicates(nums2);

    std::cout << k << std::endl;
    for (auto i : nums2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
