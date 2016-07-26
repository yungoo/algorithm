//
//  moveZeroes.cpp
//  test
//
//  Created by haiyang on 16/4/13.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, end = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                int start = max(end, i+1);
                for (int j = start; j < len; j++) {
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        end = j;
                        break;
                    }
                }
                
                if (end > len) {
                    break;
                }
            }
        }
    }
};

int main_moveZeros(int argc, const char *argv[]) {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(nums);
    
    cout << "[";
    for_each(nums.begin(), nums.end(), [](int v) { cout << v << ","; });
    cout << "]" << endl;
    
    return 0;
}


