//
//  medianOfTwoSortedArrays.cpp
//  test
//
//  Created by haiyang on 16/4/8.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 **/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int median = (n1 + n2) >> 1;
        if ((n1 + n2) & 1) {
            return findkth(nums1, 0, n1, nums2, 0, n2, median + 1);
        } else {
            return (findkth(nums1, 0, n1, nums2, 0, n2, median + 1) + findkth(nums1, 0, n1, nums2, 0, n2, median)) * 0.5f;
        }
    }
    
private:
    int findkth(vector<int> &num1, int b1, int e1, vector<int> &num2, int b2, int e2, int kth) {
        int l1 = e1 - b1, l2 = e2 - b2;
        
        // makesure len(num1) < len(num2)
        if (l1 > l2) return findkth(num2, b2, e2, num1, b1, e1, kth);
        
        if (l1 == 0) return num2[b2 + kth - 1];
        if (kth == 1) return min(num1[b1], num2[b2]);
        
        int m1 = min(kth/2, l1), m2 = kth - m1;
        
        if (num1[b1 + m1 - 1] < num2[b2 + m2 - 1]) {
            return findkth(num1, b1 + m1, e1, num2, b2, b2 + m2, kth - m1);
        } else if (num1[b1 + m1 - 1] > num2[b2 + m2 - 1]) {
            return findkth(num1, b1, b1 + m1, num2, b2 + m2, e2, kth - m2);
        } else {
            return num1[b1 + m1 - 1];
        }
    }
};

int main_findMedianSortedArrays(int argc, const char *argv[]) {
    Solution s;
    vector<int> a = {1}, b = {2, 3, 4};
    double ret = s.findMedianSortedArrays(a, b);
    cout << ret << endl;
    return 0;
}