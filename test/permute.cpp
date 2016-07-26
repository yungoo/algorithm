//
//  permute.cpp
//  test
//
//  Created by haiyang on 16/5/5.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size() + 1);
        dp[0].push_back(vector<int>{});
        
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>>& pre = dp[i];
            vector<vector<int>>& cur = dp[i + 1];
            
            for (int j = 0; j < pre.size(); j++) {
                vector<int> &p = pre[j];
                
                if (p.empty()) {
                    cur.push_back(vector<int>{nums[i]});
                } else {
                    for (int k = p.size(); k >= 0; k--) {
                        vector<int> pN = p;
                        pN.insert(pN.begin() + k, nums[i]);
                        cur.push_back(pN);
                    }
                }
            }
        }
        
        return dp[nums.size()];
    }
    
    vector<vector<int>> permuteII(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size());
        dp[0].push_back(vector<int>{nums[0]});
        
        for (int i = 1; i < nums.size(); i++) {
            vector<vector<int>>& pre = dp[i-1];
            vector<vector<int>>& cur = dp[i];
            
            for (int j = 0; j < pre.size(); j++) {
                vector<int> &p = pre[j];
                int psize = p.size();
                for (int k = 0; k <= psize; k++) {
                    if (k - 1 >= 0 && p[k - 1] == nums[i]) {
                        break;
                    }
                    vector<int> pN = p;
                    pN.insert(pN.begin() + k, nums[i]);
                    cur.push_back(pN);
                }
            }
        }
        
        return dp[nums.size() - 1];
    }
    
    vector<vector<int>> permute_dfs(vector<int>& nums) {
        vector<vector<int>> result;
        helper(result, nums, 0);
        return result;
    }
    
private:
    void helper(vector<vector<int>>& result, vector<int>& nums, int cur) {
        if (cur == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        
        for (int i = cur; i < nums.size(); i++) {
            if (isDuplicated(nums, cur, i)) continue;
            
            swap(nums[i], nums[cur]);
            helper(result, nums, cur + 1);
            swap(nums[i], nums[cur]);
        }
    }
    
    bool isDuplicated(const vector<int>& nums, int begin, int curr) {
        for (int i = begin; i < curr; i++) {
            if (nums[i] == nums[curr]) {
                return true;
            }
        }
        return false;
    }
};

int main_permute(int argc, const char *argv[]) {
//    vector<int> input = {1,1,0,0,1,-1,-1,1};
    vector<int> input = {0,0,1,1};
    Solution s;
    vector<vector<int>> ret = s.permute_dfs(input);
    
    return 0;
}