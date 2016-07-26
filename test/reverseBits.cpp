//
//  reverseBits.cpp
//  test
//
//  Created by haiyang on 16/4/19.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t l, h, m, o, p;
        for (int i = 0; i < 16; i++) {
            l = n & (1 << i);
            h = n & (1 << (31 - i));
            p = l << (31 - 2 * i) | (h >> (31 - 2 *i));
            m = 1 << (31 - i) | (1 << i);
            o = ~m & n;
            n = o | p;
            cout << bitset<32>(l) << "=>" << bitset<32>(m) << " :" << bitset<32>(n) << endl;
        }
        return n;
    }
};


int main_reverseBits(int argc, const char *argv[]) {
    Solution s;
    uint32_t r = s.reverseBits(65536);
    cout << "return:" << r << endl;
    return 0;
}