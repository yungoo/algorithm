//
//  loanCalclator.cpp
//  test
//
//  Created by haiyang on 16/5/4.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double calculate_averageCapitalPlusInterest(double capital, double rate, int months) {
        double pn = pow(1 + rate, months);
        return capital * rate * pn / (pn - 1);
    }
    
    double calculate(double capital, double rate, int months) {
        return capital / months + capital * rate;
    }
    
    double calculate_delayFee(double money, int days, double rate) {
        return money * rate * days;
    }
    
    double calculate_money(double fee, int days, double rate) {
        return fee / (days * rate);
    }
    
};

int main_loanCalcaulator(int argc, const char *argv[]) {
    Solution s;
//    double money = s.calculate(100800.f, 0.0065f, 12);
//    double money = s.calculate_delayFee(503.75f + 3.77f, 269, 0.002);
//    double money = s.calculate_delayFee(3500.f + 26.25f + 39.26f, 337, 0.002);
//    double money = s.calculate_money(276.22f, 267, 0.002);
    double money = s.calculate_averageCapitalPlusInterest(10000.f, 0.1f/12.0, 12);
    cout << money << endl;
    return 0;
}
