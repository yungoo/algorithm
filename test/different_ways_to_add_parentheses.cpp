//
//  different_ways_to_add_parentheses.cpp
//  test
//
//  Created by haiyang on 16/4/6.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 跟LST的问题类似，需要附加条件： 符号才能作为父节点
     *
     * 对每一个符号
     **/
    vector<int> diffWaysToCompute(string input) {
        vector<string> statements = parse(input);
        
        return calculate(statements, 0, statements.size() - 1);
    }
    
private:
    
    vector<int> calculate(vector<string>& statements, int low, int high) {
        vector<int> values;
        
        if (low > high || low < 0 || high < 0) {
            return values;
        }
        
        if (low == high) {
            values.push_back(atoi(statements[low].c_str()));
            return values;
        }
        
        for (int i = low; i < high; i+=2) {
            int op = i + 1;
            vector<int> tl = calculate(statements, low, op - 1);
            vector<int> tr = calculate(statements, op + 1, high);
            
            for (int m = 0; m < tl.size(); m++) {
                for (int n = 0; n < tr.size(); n++) {
                    char opChar = statements[op][0];
                    int value = calc[opChar](tl[m], tr[n]);
                    
                    values.push_back(value);
                }
            }
        }
        
        return values;
    }
    
    unordered_map<char, function<int(int,int)>> calc {
        {'+', plus<int>()},{'-',minus<int>()},{'*',multiplies<int>()}
    };
    
    vector<string> parse(string input) {
        vector<string> statement;
        
        string id;
        for (int i = 0; i < input.length(); i++) {
            char x = input[i];
            if (isdigit(x)) {
                int begin = i;
                while (isdigit(input[i])) {
                    i++;
                }
                string el = input.substr(begin, i - begin);
                statement.push_back(el);
                i--;
            } else if (x == '+' || x == '-' || x == '*') {
                string op;
                op += x;
                statement.push_back(op);
            }
        }
        return statement;
    }
};

void print(int v) {
    printf("%d,", v);
}

int main_dwta(int argc, const char * argv[]) {
    Solution s;
    vector<int> results = s.diffWaysToCompute("15-7*6+24");
    for_each(results.begin(), results.end(), print);
    return 0;
}
