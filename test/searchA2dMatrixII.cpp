//
//  searchA2dMatrixII.cpp
//  test
//
//  Created by haiyang on 16/5/16.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix_iterator(vector<vector<int>>& matrix, int target) {
        int row = 0, col=matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col=matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            col = searhInCol(matrix, row, col, target);
            if (col < 0) return false;
            
            row = searhInRow(matrix, row, col, target);
            if (row < 0 || row >= matrix.size())
                return false;
            
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
            
//            cout << "searcing under row=" << row << " col=" << col << " val=" << matrix[row][col] << endl;
        }
        return false;
    }
    
    int searhInCol(vector<vector<int>>& matrix, int m, int n, int target) {
        vector<int>& row = matrix[m];
        int i = 0, j = n;
        while (i < j) {
            int m = (i + j)/2;
            if (row[m] == target) {
                return m;
            }
            
            if (row[m] < target) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        
        if (j >= 0) {
            if (row[j] > target) {
                j--;
            }
        }
        return j;
    }
    
    int searhInRow(vector<vector<int>>& matrix, int m, int n, int target) {
        int i = m, j = matrix.size() - 1;
        while (i < j) {
            int m = (i + j)/2;
            int v = matrix[m][n];
            if (v == target) {
                return m;
            }
            
            if (v < target) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        
        return i;
    }
};


int main_searchA2dMatrixII(int argc, const char *argv[]) {
    vector<vector<int>> matrix = {
        { 1, 3, 5, 7, 9},
        { 2, 4, 6, 8,10},
        {11,13,15,17,19},
        {12,14,16,18,20},
        {21,22,23,24,25}
        
//        { 1, 2, 3, 4, 5},
//        { 6, 7, 8, 9,10},
//        {11,12,13,14,15},
//        {16,17,18,19,20},
//        {21,22,23,24,25}
        
//        {-1}, {-1}
//        {1, 1}
//        {-5}
//        {1,   4,  7, 11, 15},
//        {2,   5,  8, 12, 19},
//        {3,   6,  9, 16, 22},
//        {10, 13, 14, 17, 24},
//        {18, 21, 23, 26, 30}
//        {1}, {3}, {5}
//        { 1, 3, 5, 7, 9},
//        { 2, 4, 6, 8,10},
//        {11,13,15,17,19},
//        {12,14,16,18,20},
//        {21,22,23,24,25}
    };
    
    Solution s;
    bool ret = s.searchMatrix(matrix, 21);
    cout << (ret ? "true" : "false") << endl;
    return ret;
}