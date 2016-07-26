//
//  countAndSay.cpp
//  test
//
//  Created by haiyang on 16/4/19.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        int cnt;
        char pre;
        while (--n > 0) {
            pre = s[0];
            cnt = 1;
            ostringstream os;
            for (int i = 1; i < s.length(); i++) {
                if (s[i] == pre) {
                    cnt += 1;
                } else {
                    os << cnt << pre;
                    pre = s[i];
                    cnt = 1;
                }
            }
            
            if (cnt > 0) {
                os << cnt << pre;
            }
            s = os.str();
        }
        return s;
    }
};

int main_countAndSay(int argc, const char *argv[]) {
    Solution s;
    string ret = s.countAndSay(4);
    cout << ret << endl;
    return 0;
}

