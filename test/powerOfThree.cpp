//
//  powerOfThree.cpp
//  test
//
//  Created by haiyang on 16/4/15.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int const Max3PowerInt = 1162261467; // 3^19, 3^20 =
    int const MaxInt = 1162261467; // 2^31 - 1
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > Max3PowerInt) return false;
        return Max3PowerInt % n == 0;
    }
};

int main_powerOfThree(int argc, const char *argv[]) {
    Solution s;
    bool ret = s.isPowerOfThree(9);
    cout << (ret ? "true" : "false") << endl;
    return 0;
}