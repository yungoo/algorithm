//
//  uglyNumber.cpp
//  test
//
//  Created by haiyang on 16/4/12.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
};

int main_uglyNumber(int argc, const char *argv[]) {
    Solution s;
    bool ret = s.isUgly(1);
    cout << (ret ? "true" : "false") << endl;
    return 0;
}