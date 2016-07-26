//
//  countPrimes.cpp
//  test
//
//  Created by haiyang on 16/4/13.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        bool* isPrime = new bool[n];
        memset(isPrime, true, sizeof(bool) * n);
        isPrime[0] = false;
        
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        
        int counter = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) counter++;
        }
        
        delete[] isPrime;
        
        return counter;
    }
    
};

int main_countPrimes(int argc, const char *argv[]) {
    Solution s;
    int count = s.countPrimes(1000);
    cout << count << endl;
    return 0;
}

