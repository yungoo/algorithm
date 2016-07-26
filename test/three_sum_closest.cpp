//
//  three_sum_closest.cpp
//  test
//
//  Created by haiyang on 16/4/7.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = -1;
        if (nums.size() < 3) return closest;
        
        sort(nums.begin(), nums.end());
        
        int distance = INT_MAX;
        int i = 0;
        while (i < nums.size() - 2) {
            int a = nums[i];
            int begin = i + 1, end = nums.size() - 1;
            while (begin < end) {
                int sum = a + nums[begin] + nums[end];
                int diff = abs(sum - target);
                if (diff < distance) {
                    closest = sum;
                    distance = abs(target - closest);
                }
                
                if (sum < target) {
                    begin++;
                } else {
                    end--;
                }
            }
            
            i++;
        }
        return closest;
    }
    
};

int main_tsc(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {1,1,-1,-1,3};
    int result = s.threeSumClosest(nums, -1);
    cout << "result: " << result << endl;
    return 0;
}