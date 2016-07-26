//
//  add_two_numers.cpp
//  test
//
//  Created by haiyang on 16/4/7.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = l1, *r = l2, *root = NULL, **t = &root;
        int carry = 0, sum;
        while (l || r) {
            sum = carry;
            if (l) {
                sum += l->val;
                l = l->next;
            }
            
            if (r) {
                sum += r->val;
                r = r->next;
            }
            
            carry = sum / 10;
            
            ListNode *node = new ListNode(sum % 10);
            *t = node;
            t = &node->next;
        }
        
        if (carry > 0) {
            *t = new ListNode(carry);
        }
        
        return root;
    }
};

int main_a_t_n(int argc, const char * argv[]) {
    Solution s;
    ListNode *l1 = new ListNode(1);
    
    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    
    ListNode *result = s.addTwoNumbers(l1, l2);
    
    cout << "[";
    while (result) {
        cout << result->val << ",";
        result = result->next;
    }
    cout << "]" << endl;
    
    return 0;
}