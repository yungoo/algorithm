//
//  climbing_stairs.cpp
//  test
//
//  Created by haiyang on 16/4/5.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        
        int a[2] = {2, 3};
        for (int i = 4; i <= n; i++) {
            int t = a[0] + a[1];
            a[0] = a[1];
            a[1] = t;
        }
        return a[1];
    }
        
};

int main3(int argc, const char * argv[]) {
    int n = 4;
    Solution s;
    int c = s.climbStairs(n);
    cout << "ways:" << c << endl;
    return 0;
}
