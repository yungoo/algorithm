//
//  longestPalindromicSubstring.cpp
//  test
//
//  Created by haiyang on 16/4/8.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        int start = 0;
        for (int k = 0; k < s.length(); k++) {
            int i = k, j = k;
            
            while (j < s.length() - 1 && s[j] == s[j+1]) {
                j++;
            }
            
            while (i > 0 && j <= s.length() - 1 && s[i-1] == s[j+1]) {
                i--;
                j++;
            }
            
            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                start = i;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

int main_longestPalindrome(int argc, const char *argv[]) {
    Solution s;
    string ret = s.longestPalindrome("bb");
    cout << ret << endl;
    return 0;
}
