//
//  happyNumber.cpp
//  test
//
//  Created by haiyang on 16/4/12.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> seenNumber;
        while (n > 1 && seenNumber.find(n) == seenNumber.end()) {
            seenNumber.insert(n);
            n = happy(n);
        }
        return n == 1;
    }
    
private:
    int happy(int n) {
        int sum = 0;
        while (n != 0) {
            int m = n % 10;
            sum += m * m;
            n /= 10;
        }
        return sum;
    }
};

int main_happyNumber(int argc, const char *argv[]) {
    Solution s;
    bool ret = s.isHappy(19);
    cout << (ret ? "happy" : "unhappy") << endl;
    return 0;
}