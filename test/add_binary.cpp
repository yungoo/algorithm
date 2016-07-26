//
//  add_binary.cpp
//  test
//
//  Created by haiyang on 16/4/7.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int ca = 0, cb = 0, c = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                ca = a[i] - '0';
                i--;
            } else {
                ca = 0;
            }
            if (j >= 0) {
                cb = b[j] - '0';
                j--;
            } else {
                cb = 0;
            }
            
            int sum = c + ca + cb;
            c = sum / 2;
            
            ret.insert(ret.begin(), sum % 2 + '0');
        }
        
        if (c > 0) {
            ret = "1" + ret;
        }
        
        return ret;
    }
};

int main_ab(int argc, const char * argv[]) {
    Solution s;
    string ret = s.addBinary("11", "1");
    
    cout << ret << endl;
    return 0;
}

