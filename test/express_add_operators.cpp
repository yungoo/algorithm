//
//  express_add_operators.cpp
//  test
//
//  Created by haiyang on 16/4/7.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

#include <vector>
#include <unordered_map>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> results;
        searchByDFS(results, "", num, 0, target, 0, 0, ' ');
        return results;
    }
    
private:
    void searchByDFS(vector<string> &results, string path, string num, int pos, long target, long current, long prev, char preop) {
        if (current == target && pos == num.size()) {
//                if ("1-2*3*4+56-7-8-9" == path) {
                    results.push_back(path);
//                }
            return;
        }
        
        if (pos == num.size()) return;
        
        string value;
        long v = 0;
        for (int i = pos; i < num.length(); i++) {
            if (value == "0") break;
            
            value = value + num[i];
            v = v*10 + num[i]-'0';
            
            if (path.empty()) {
                searchByDFS(results, value, num, i + 1, target, v, 0, ' ');
            } else {
                searchByDFS(results, path + "+" + value, num, i + 1, target, current + v, v, '+');
                searchByDFS(results, path + "-" + value, num, i + 1, target, current - v, v, '-');
                
                if (preop == '+') {
                    searchByDFS(results, path + "*" + value, num, i + 1, target, current - prev + prev * v, prev * v, preop);
                } else if (preop == '-') {
                    searchByDFS(results, path + "*" + value, num, i + 1, target, current + prev - prev * v, prev * v, preop);
                } else {
                    searchByDFS(results, path + "*" + value, num, i + 1, target, current * v, v, '*');
                }
            }
        }
    }
    
    unordered_map<char, function<int(int,int)>> calc {
        {'+', plus<int>()},
        {'-', minus<int>()},
        {'*', multiplies<int>()},
        {'/', divides<int>()}
    };
};

//class Solution {
//public:
//    vector<string> addOperators(string num, int target) {
//        vector<string> result;
//        if (num.size() == 0) return result;
//        helper(num, target, result, "", 0, 0, 0, ' ');
//        return result;
//    }
//    
//    //DFS algorithm
//    void helper(const string &num, const int target, //`num` and `target` never change
//                vector<string>& result, // the array store all of the answers
//                string solution, //the current potential answer.
//                int idx, // the current index of `num` array
//                long long val, // the current value we calculated so far
//                long long prev, // the lastest value we used for calculation, which used for operation prioirty adjustment
//                char preop ) // the latest "+" or "-" operation, which used for operation prioirty adjustment
//    {
//        
//        if (target == val && idx == num.size()){
//            result.push_back(solution);
//            return;
//        }
//        if (idx == num.size()) return;
//        
//        string n;
//        long long v=0;
//        for(int i=idx; i<num.size(); i++) {
//            //get rid of the number which start by "0"
//            //e.g.  "05" is not the case.
//            if (n=="0") return;
//            
//            n = n + num[i];
//            v = v*10 + num[i]-'0';
//            
//            if (solution.size()==0){
//                // the first time for initialization
//                helper(num, target, result, n, i+1, v, 0, ' ');
//            }else{
//                // '+' or '-' needn't to adjust the priority
//                helper(num, target, result, solution + '+' + n, i+1, val+v, v, '+');
//                helper(num, target, result, solution + '-' + n, i+1, val-v, v, '-');
//                
//                //if we meet multiply operation, we need adjust the calcualtion priority
//                // e.g. if the previous value is calculated by 2+3=5,
//                //      then if we need to multipy 4, it is not 5*4, it is 2+3*4=2+12=24
//                //      we need be careful about multiply again, such as: 2+3*4*5
//                if (preop=='+') {
//                    helper(num, target, result, solution + '*' + n, i+1, (val-prev)+prev*v, prev*v, preop);
//                }else if (preop=='-'){
//                    helper(num, target, result, solution + '*' + n, i+1, (val+prev)-prev*v, prev*v, preop);
//                }else {
//                    helper(num, target, result, solution + '*' + n, i+1, val*v, v, '*');
//                }
//            }
//        }
//        
//    }
//};

int main_eao(int argc, const char * argv[]) {
    Solution s;
//    vector<string> results = s.addOperators("2147483648", -2147483648);
//    vector<string> results = s.addOperators("123", 6);
    vector<string> results = s.addOperators("123456789", 45);
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    
    string expects[] = {"1*2*3*4*5-6-78+9","1*2*3*4+5+6-7+8+9","1*2*3+4+5+6+7+8+9","1*2*3+4+5-6*7+8*9","1*2*3+4-5*6+7*8+9","1*2*3+4-5*6-7+8*9","1*2*3-4*5+6*7+8+9","1*2*3-4*5-6+7*8+9","1*2*3-4*5-6-7+8*9","1*2*3-45+67+8+9","1*2*34+56-7-8*9","1*2*34-5+6-7-8-9","1*2+3*4-56+78+9","1*2+3+4+5*6+7+8-9","1*2+3+4-5+6*7+8-9","1*2+3+4-5-6+7*8-9","1*2+3+45+67-8*9","1*2+3-45+6+7+8*9","1*2+34+5-6-7+8+9","1*2+34+56-7*8+9","1*2+34-5+6+7-8+9","1*2+34-56+7*8+9","1*2+34-56-7+8*9","1*2-3*4+5+67-8-9","1*2-3+4-5-6*7+89","1*2-3-4*5+67+8-9","1*2-3-4+56-7-8+9","1*2-34+5*6+7*8-9","1*23+4*5-6+7-8+9","1*23-4-56-7+89","1+2*3*4*5+6+7-89","1+2*3*4+5*6+7-8-9","1+2*3*4-5+6*7-8-9","1+2*3+4*5*6+7-89","1+2*3+4*5-6+7+8+9","1+2*3-4-5-6*7+89","1+2*34-5*6+7+8-9","1+2+3*4*5+6-7-8-9","1+2+3*4+5+6*7-8-9","1+2+3*45-6-78-9","1+2+3+4+5+6+7+8+9","1+2+3+4+5-6*7+8*9","1+2+3+4-5*6+7*8+9","1+2+3+4-5*6-7+8*9","1+2+3-4*5+6*7+8+9","1+2+3-4*5-6+7*8+9","1+2+3-4*5-6-7+8*9","1+2+3-45+67+8+9","1+2-3*4*5+6+7+89","1+2-3*4+5*6+7+8+9","1+2-3*4-5+6*7+8+9","1+2-3*4-5-6+7*8+9","1+2-3*4-5-6-7+8*9","1+2-3+4*5+6*7-8-9","1+2-3+45+6-7-8+9","1+2-3+45-6+7+8-9","1+2-3-4-5*6+7+8*9","1+2-3-45-6+7+89","1+2-34+5+6+7*8+9","1+2-34+5+6-7+8*9","1+2-34-5-6+78+9","1+23*4+5-6-7*8+9","1+23*4-5-6*7+8-9","1+23*4-56+7-8+9","1+23+4+5+6+7+8-9","1+23+4-5*6+7*8-9","1+23+4-5-67+89","1+23-4*5+6*7+8-9","1+23-4*5-6+7*8-9","1+23-4-5+6+7+8+9","1+23-4-5-6*7+8*9","1+23-45+67+8-9","1-2*3*4+5-6+78-9","1-2*3*4-5-6+7+8*9","1-2*3+4*5+6+7+8+9","1-2*3+4*5-6*7+8*9","1-2*3+4+5+6*7+8-9","1-2*3+4+5-6+7*8-9","1-2*3+4+56+7-8-9","1-2*3+45-67+8*9","1-2*3-4+5*6+7+8+9","1-2*3-4-5+6*7+8+9","1-2*3-4-5-6+7*8+9","1-2*3-4-5-6-7+8*9","1-2*34+5*6-7+89","1-2+3*4*5-6-7+8-9","1-2+3+4-5*6+78-9","1-2+3+45+6-7+8-9","1-2+3-4*5-6+78-9","1-2+3-45+6-7+89","1-2-3*4+5+6+7*8-9","1-2-3*4-5-6+78-9","1-2-3+4-5+67-8-9","1-2-3+45-6-7+8+9","1-2-34+5+6+78-9","1-2-34+56+7+8+9","1-2-34-5+6+7+8*9","1-23*4+5+6*7+89","1-23+4*5-6*7+89","1-23+4-5+67-8+9","1-23+45-67+89","1-23-4+5+67+8-9","1-23-4-5-6-7+89","12*3*4-5*6-78+9","12*3+4+5+6-7-8+9","12*3+4+5-6+7+8-9","12*3-4-5-6+7+8+9","12*3-4-56+78-9","12+3*4+5+6-7+8+9","12+3*45-6-7-89","12+3+4-56-7+89","12+3-4*5+67-8-9","12+3-45+6+78-9","12+34-5-6-7+8+9","12-3*4*5+6+78+9","12-3*4-5+67-8-9","12-3+4*5+6-7+8+9","12-3+4+56-7-8-9","12-3-4+5*6-7+8+9","12-3-4-56+7+89","12-3-45-6+78+9"};
    
    int expectSize = sizeof(expects) / sizeof(string);
    
    for (int i = 0; i < expectSize; i++) {
        string v = expects[i];
        
        vector<string>::iterator r = find(results.begin(), results.end(), v);
        if (r == results.end()) {
//            cout << "miss! " << v << endl;
        } else {
            results.erase(r);
        }
    }
    
    if (!results.empty()) {
        for (int i = 0; i < results.size(); i++) {
            cout << "wrong:" << results[i] << endl;
        }
    }
    
    return 0;
}