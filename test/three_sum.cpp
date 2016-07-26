//
//  three_sum.cpp
//  test
//
//  Created by haiyang on 16/4/7.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() < 3) return results;
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while (i < nums.size() - 2) {
            int a = nums[i];
            int begin = i + 1, end = nums.size() - 1;
            
            while (begin < end) {
                int b = nums[begin], c = nums[end];
                
                if (a + b + c == 0) {
                    results.push_back(vector<int>{a, b, c});
                    end = rskip(nums, begin, end);
                } else if (a + b + c < 0) {
                    begin = skip(nums, begin, end);
                } else {
                    end = rskip(nums, begin, end);
                }
            }
            
            i = skip(nums, i, nums.size() - 3);
        }
        return results;
    }
    
    vector<vector<int>> threeSum2(vector<int>& nums) {
        vector<vector<int>> results;
        search(nums, results, vector<int>{}, 0, 0);
        
        return results;
    }
   
private:
    int skip(const vector<int>& nums, int start, int end) {
        int tmp = nums[start];
        while(start <= end && nums[start] == tmp)
            start++;
        return start;
    }
    
    int rskip(const vector<int>& nums, int start, int end) {
        int tmp = nums[end];
        while(end >= start && nums[end] == tmp)
            end--;
        return end;
    }
    
private:
    void search(vector<int> &nums, vector<vector<int>> &results, vector<int> solution, int pos, int target) {
        if (target == 0 && solution.size() == 3) {
            if (solution[0] == -1 && solution[1] == 0 && solution[2] == 0) {
                results.push_back(solution);
            }
            return;
        }
        
        if (solution.size() >= 3) {
            return;
        }
        
        for (int i = pos; i < nums.size(); i++) {
            solution.push_back(nums[i]);

            search(nums, results, solution, pos + 1, target - nums[i]);
        }
    }
};

int main_3sums(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> results = s.threeSum(nums);
    
    cout << "[" << endl;
    for (int i = 0; i < results.size(); i++) {
        vector<int> &solution = results[i];
        cout << "\t[";
        for (int j = 0; j < solution.size(); j++) {
            cout << solution[j];
            if (j != solution.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != results.size() - 1) {
            cout << "," << endl;
        } else {
            cout << endl;
        }
    }
    cout << "]" << endl;
    
    return 0;
}