//
//  containerWithMostWater.cpp
//  test
//
//  Created by haiyang on 16/5/13.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>
#include "utils.hpp"

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() == 1) return 0;
        
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                int area = (j - i) * min(height[j], height[i]);
                if (area > maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }
    
    int maxArea_exceedTimeLimit(vector<int>& height) {
        return helper(height, height.size() - 1);
    }
    
    int helper(vector<int>& height, int e) {
        if (e <= 0) return 0;
        
        int maxArea = 0;
        for (int i = 0; i < e; i++) {
            int area = (e - i) * min(height[e], height[i]);
            maxArea = max(maxArea, area);
        }
        return max(maxArea, helper(height, e - 1));
    }
};


int main_containerWithMostWater(int argc, const char *argv[]) {
    vector<int> input = {1, 1};
    Solution s;
    int area = s.maxArea(input);
    cout << "area = " << area << endl;
    return 0;
}