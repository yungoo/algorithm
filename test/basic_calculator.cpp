//
//  class Solution {  public:      int calculate(string s) {                }  basic_calculator.cpp
//  test
//
//  Created by haiyang on 16/4/6.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;


class Solution {
public:
    int calculate2(string s) {
        istringstream ss("+"+s);
        
        return exec(ss);
    }
    
    int calculate(string s) {
        istringstream ss("+"+s);
        
        return execII(ss);
    }
    
private:
    int execII(istringstream &ss) {
        int sum = 0;
        int num;
        int interim = 0;
        char op;
        
        while (ss >> op) {
            ignoreBlank(ss);
            
            if (op == '+' || op == '-') {
                ignoreBlank(ss);
                
                ss >> num;
                sum += interim;
                interim = (op == '+'? 1 : -1) * num;
                
            } else if (op == '*') {
                ss >> num;
                interim *= num;
                
            } else if (op == '/') {
                ss >> num;
                interim /= num;
            }
        }
        
        sum += interim;
        
        return sum;
    }
    
    int exec(istringstream &ss) {
        int sum = 0;
        int num;
        char op;
        
        while (ss >> op) {
            ignoreBlank(ss);
            
            if (op == '+' || op == '-') {
                ignoreBlank(ss);
                
                if (isdigit(ss.peek())) {
                    ss >> num;
                    sum += (op == '+'? 1 : -1) * num;
                } else {
                    sum += (op == '+'? 1 : -1) * exec(ss);
                }
            } else if (op == '(') {
                if (isdigit(ss.peek())) {
                    ss >> num;
                    sum += num;
                } else {
                    sum += exec(ss);
                }
            } else if (op == ')'){
                return sum;
            }
        }
        
        return sum;
    }
    
    void ignoreBlank(istringstream &ss) {
        while (ss.peek() == ' ') ss.get();
    }
};

int main_basic_calculator(int argc, const char * argv[]) {
    Solution s;
    int ret = s.calculate("3+2*2");
    cout << ret << endl;
    return 0;
}