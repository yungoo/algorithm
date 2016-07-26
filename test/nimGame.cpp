//
//  nimGame.cpp
//  test
//
//  Created by haiyang on 16/4/12.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main_minGame(int argc, const char *argv[]) {
    Solution s;
    bool ret = s.canWinNim(33);
    cout << (ret ? "true" : "false") << endl;
    return 0;
}