//
//  multiple_strings.cpp
//  test
//
//  Created by haiyang on 16/4/8.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> results(num1.length() + num2.length(), 0);
        
        for (int i = num2.length() - 1; i >= 0; i--) {
            for (int j = num1.length() - 1; j >= 0; j--) {
                // i 作为进位
                results[j + 1 + i] += (num1[j] - '0') * (num2[i] - '0');
            }
        }
        
        for (int i = results.size() - 1; i > 0; i--) {
            results[i - 1] += results[i] / 10;
            results[i] = results[i] % 10;
        }
        
        ostringstream oss;
        int i = 0;
        while (i < results.size() - 1 && results[i] == 0) {i++;}
        for (;i < results.size(); i++) {
            oss << results[i];
        }
        
        return oss.str();
    }
};

int main_multiple_strings(int argc, const char *argv[]) {
    Solution solution;
    string ret = solution.multiply("9999", "1111");
    cout << "result: " << ret << endl;
    return 0;
}