//
//  longestIncreasingSubsequence.cpp
//  test
//
//  Created by haiyang on 16/6/7.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLIS_worked(vector<int>& nums) {
        int ret = 0;
        vector<int> len(nums.size(), 1);
        int maxPos = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int m = 1;
            if (nums[i] < nums[maxPos]) {
                m = len[maxPos] + 1;
                maxPos = i;
            } else {
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[i] < nums[j]) {
                        m = max(m, len[j] + 1);
                    }
                }
            }
            
            len[i] = m;
            ret = max(ret, m);
        }
        return ret;
    }
    
    int lengthOfLIS_TimeExceeded(vector<int>& nums) {
        int m = 0;
        m = helper(nums, 0, m, INT_MIN);
        return m;
    }
    
    int lengthOfLIS_usingMap(vector<int>& nums) {
        map<int, int, greater<int>> len;
        len[1] = nums.back();
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            int m = 1;
            for (auto itr = len.cbegin(); itr != len.cend(); itr++) {
                cout << "v:" <<  nums[i] << " f:" << itr->first << " sen:" << itr->second << endl;
                if (nums[i] < itr->second) {
                    m = itr->first + 1;
                    break;
                }
            }
            
            len[m] = max(nums[i], len[m]);
        }
        return len.cbegin()->first;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        
        vector<int> vec;
        vec.push_back(nums[0]);
        
        for(int i=1; i < nums.size(); i++) {
            int n = vec.back();
            
            if (n < nums[i]) {
                vec.push_back(nums[i]);
            } else {
                auto iter = lower_bound(vec.begin(), vec.end(), nums[i]);
                *iter = nums[i];
            }
        }
        
        return vec.size();
    }
    
private:
    int helper(vector<int>& nums, int pos, int acc, int last) {
        if (pos >= nums.size()) {
            return acc;
        }
        
        if (nums[pos] > last) {
            int includedIt = helper(nums, pos + 1, acc + 1, nums[pos]);
            int excluedIt = helper(nums, pos + 1, acc, last);
            return max(includedIt, excluedIt);
        }
        
        return acc;
    }
};


int main_longestIncreasingSubsequence(int argc, const char *argv[]) {
    vector<int> args = {10,9,2,5, 6, 7, 8,3,7,101,18};
    
    Solution s;
    int c = s.lengthOfLIS(args);
    
    cout << c << endl;
    return 0;
}