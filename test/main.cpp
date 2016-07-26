//
//  main.cpp
//  test
//
//  Created by haiyang on 16/4/5.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

#include <vector>

using namespace std;

//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        return count(amount, coins, coins.size() - 1);
//    }
//private:
//    int count(int amount, vector<int>& coins, int index) {
//        if (amount == 0) {
//            return 0;
//        }
//        
//        if (amount < 0 || index < 0) {
//            return INT_MAX - 1;
//        }
//        
//        int t = min(count(amount, coins, index - 1), count(amount - coins[index], coins, index) + 1);
//        return t;
//    }
//    
//};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int MAX = amount + 1;
        vector<int> dp(amount + 1, MAX);
        
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == MAX ? -1 : dp[amount];
    }
};

int main2(int argc, const char * argv[]) {
    vector<int> coins;
//    coins.push_back(186);
//    coins.push_back(419);
//    coins.push_back(83);
//    coins.push_back(408);
//    int total = 6249;
    
//        coins.push_back(1);
//        coins.push_back(2);
//        coins.push_back(5);
//        int total = 11;
    
        coins.push_back(3);
        coins.push_back(7);
        coins.push_back(405);
        coins.push_back(436);
        int total = 8839;
    
    Solution s;
    int c = s.coinChange(coins, total);
    cout << "pieces:" << c << endl;
    return 0;
}
