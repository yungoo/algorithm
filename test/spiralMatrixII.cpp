//
//  spiralMatrixII.cpp
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
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return vector<vector<int>>{};
        
        vector<vector<int>> result(n, vector<int>(n));
        
        helper(result, 1, 0, n);
        return result;
    }
    
    void helper(vector<vector<int>>& mat, int cur, int e, int n) {
        if (e + e >= n) return;
        if (e + e == n - 1) {
            mat[e][e] = cur++;
            return;
        }
        
        for (int t = e; t < n - 1 - e; t++) {
            mat[e][t] = cur++;
        }
        
        for (int r = e; r < n - 1 - e; r++) {
            mat[r][n - 1 - e] = cur++;
        }
        
        for (int b = n - 1 - e; b > e; b--) {
            mat[n - 1 - e][b] = cur++;
        }
        
        for (int l = n - 1 - e; l > e; l--) {
            mat[l][e] = cur++;
        }
        
        helper(mat, cur, e + 1, n);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>{};
        
        vector<int> result;
        int n = matrix[0].size(), m = matrix.size();
        
        for (int e = 0; 2 * e < n && 2 * e < m; e++) {
            for (int i = e; i <= n - 1 - e; i++) {
                result.push_back(matrix[e][i]);
            }
            for (int i = e + 1; i <= m - 1 - e; i++) {
                result.push_back(matrix[i][n - 1 - e]);
            }
            if (m - 1 - 2 * e > 0) {
                for (int i = n - 1 - e - 1; i >= e; i--) {
                    result.push_back(matrix[m - 1 - e][i]);
                }
            }
            
            if (n - 1 - 2 * e > 0) {
                for (int i = m - 1 - e - 1; i > e; i--) {
                    result.push_back(matrix[i][e]);
                }
            }
        }
        return result;
    }
};

int main_spiralMatrix(int argc, const char *argv[]) {
    Solution s;
//    vector<vector<int>> m = s.generateMatrix(4);
//    ConsoleUtils::printMatrix(m);
    
    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> r = s.spiralOrder(m);
    ConsoleUtils::printVector(r);
    
    return 0;
}