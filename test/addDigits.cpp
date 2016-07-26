//
//  addDigits.cpp
//  test
//
//  Created by haiyang on 16/4/12.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return 1 + ((num - 1) % 9);
    }

private:
    
};


int main_addDigits(int argc, const char *argv[]) {
    Solution s;
    int ret = s.addDigits(83);
    cout << ret << endl;
    return 0;
}