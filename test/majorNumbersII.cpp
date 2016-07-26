//
//  majorNumbersII.cpp
//  test
//
//  Created by haiyang on 16/4/14.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> results;
        
        int major1 = 0, cnt1 = 0, major2 = 0, cnt2 = 0;
        for (auto num : nums) {
            if (cnt1 == 0 && num != major2) {
                major1 = num;
                cnt1++;
            } else if (num == major1) {
                cnt1++;
            } else if (cnt2 == 0) {
                major2 = num;
                cnt2++;
            } else if (num == major2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt2 = cnt1 = 0;
        for (auto num : nums) {
            if (num == major1) {
                cnt1++;
            } else if (num == major2) {
                cnt2++;
            }
        }
        
        if (cnt1 > nums.size() / 3) {
            results.push_back(major1);
        }
        if (cnt2 > nums.size() / 3) {
            results.push_back(major2);
        }
        return results;
    }
    
};

int main_majorNumberII(int argc, const char *argv[]) {
    vector<int> nums = {4, 3, 4};
    
    Solution s;
    vector<int> ret = s.majorityElement(nums);
    
    for (auto n : ret) {
        cout << n << ",";
    }
    return 0;
}