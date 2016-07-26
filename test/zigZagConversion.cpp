//
//  zigZagConversion.cpp
//  test
//
//  Created by haiyang on 16/4/8.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string convert2(string s, int numRows) {
        vector<string> results(numRows);
        
        int i = 0, j, gap = numRows - 2;
        while (i < s.size()) {
            // move down
            for (j = 0; i < s.size() && j < numRows; j++) results[j].append(1, s[i++]);
            // move diagonal
            for (j = gap; i < s.size() && j > 0; j--) results[j].append(1, s[i++]);
        }
        
        string ret;
        for (int i = 0; i < numRows; i++) {
            ret.append(results[i]);
        }
        return ret;
    }
    
    string convert(string s, int nRows) {
        //The cases no need to do anything
        if (nRows<=1 || nRows>=s.size()) return s;
        
        vector<string> r(nRows);
        int row = 0;
        int step = 1;
        for(int i=0; i<s.size(); i ++) {
            if (row == nRows-1) step = -1;
            if (row == 0) step = 1;
            //cout << row <<endl;
            r[row] += s[i];
            row += step;
        }
        
        string result;
        for (int i=0; i<nRows; i++){
            result += r[i];
        }
        return result;
    }
    
    string conver3(string s, int numRows) {
        if (numRows<=1 || numRows>=s.size()) return s;
        
        vector<string> results(numRows);
        
        int row = 0;
        int step = 1;
        
        for (int i = 0; i < s.size(); i++) {
            if (row == numRows - 1) step = -1;
            if (row == 0) step = 1;
            
            results[row] += s[i];
            row += step;
        }
        
        string ret;
        for (int i = 0; i < numRows; i++) {
            ret.append(results[i]);
        }
        return ret;
    }
};

int main_zigZagConversion(int argc, const char *argv[]) {
    Solution s;
    string ret = s.convert("AB", 1);
    cout << ret << endl;
    return 0;
}