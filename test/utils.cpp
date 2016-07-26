//
//  utils.cpp
//  test
//
//  Created by haiyang on 16/5/9.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include "utils.hpp"

#include <iostream>
using namespace std;

void ConsoleUtils::printMatrix(vector<vector<int> > &ret) {
    for (int i = 0; i < ret.size(); i++) {
        cout << "[";
        auto &p = ret[i];
        for (int j = 0; j < p.size(); j++) {
            cout << p[j];
            if (j != p.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
    
    cout << endl;
}

void ConsoleUtils::printVector(vector<int>& p) {
    cout << "[";
    for (int j = 0; j < p.size(); j++) {
        cout << p[j];
        if (j != p.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}