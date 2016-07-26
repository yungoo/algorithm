//
//  rotateImage.cpp
//  test
//
//  Created by haiyang on 16/5/9.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>
#include "utils.hpp"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // round 0 ~ n/2
        for (int r = 0; r < n / 2; r++) {
            vector<int> t = matrix[r];
            
            int nr = n - r;
            for (int i = r; i < nr - 1; i++) {
                int t = matrix[r][n-1-i];
                
                // top-right
                matrix[r][n-1-i] = matrix[i][r];
                
                // left-top
                matrix[i][r] = matrix[nr-1][i];
                
                // bottom-left
                matrix[nr-1][i] = matrix[n-1-i][nr-1];

                // right-bottom
                matrix[n-1-i][nr - 1] = t;
            }
        }
    }
};


int main_rotateImage(int argc, const char *argv[]) {
    vector<vector<int>> matrix = {
//        {1,2,3,4},
//        {5,6,7,8},
//        {9,10,11,12},
//        {13,14,15,16}
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
    Solution s;
    s.rotate(matrix);
    
    ConsoleUtils::printMatrix(matrix);
    
    return 0;
}