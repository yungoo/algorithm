//
//  palindromeLinkedList.cpp
//  test
//
//  Created by haiyang on 16/4/19.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if( head==NULL || head->next==NULL ) return true;
        // list has at least two nodes
        ListNode *pre = NULL, *pfirst = nullptr, *psecond = nullptr;
        auto px1 = head, px2 = head;
        // traversal 1: reverse the first half and get pfirst&psecond in position
        while(true) {
            px2 = px2->next->next;        // move px2 forward
            pfirst = px1; px1 = px1->next;// move px1 forward
            pfirst->next = pre;           // point curent next back
            if( px2 == NULL ) {           // 2n Nodes
                psecond = px1; break;
            } else if( px2->next == NULL ) { // 2n+1 Nodes
                psecond = px1->next; break;
            }
            pre = pfirst;
            
            dump("first", pfirst);
            dump("second", psecond);
        }
        
        // traversal 2: check node values
        while( pfirst!=NULL ) {
            if( pfirst->val != psecond->val ) return false;
            pfirst = pfirst->next; psecond = psecond->next;
        }
        return true;
    }
    
    bool isPalindrome_slower(ListNode* head) {
        if (!head || !head->next) return true;
        if (head->val == head->next->val && head->next->next == nullptr) return true;
        
        ListNode *rev = nullptr, *median = nullptr;
        while (head->next) {
            cout << "current: "<< head->val << endl;
            dump("L", rev);
            dump("R", head->next);
            if (median == nullptr) {
                median = head;
            }
            
            if (median->val != head->next->val) {
                if (eqals(rev, head->next)) {
                    return true;
                } else {
                    ListNode *t = head->next;
                    head->next = rev;
                    rev = median;
                    median = nullptr;
                    head = t;
                }
            } else {
                head = head->next;
            }
        }
        
        return false;
    }
    
private:
    void dump(string name, ListNode *a) {
        cout << name << ":[";
        while (a) {
            cout << a->val << ",";
            a = a->next;
        }
        cout << "]" << endl;
    }
    bool eqals(ListNode* a, ListNode* b) {
        while (a && b && a->val == b->val) {
            a = a->next;
            b = b->next;
        }
        
        return a == nullptr && b == nullptr;
    }
};

int main_isPalindrome(int argc, const char *argv[]) {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 5, 5, 5, 5, 5, 5, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    ListNode *root = new ListNode(values[0]), *t = root;
    for (int i = 1; i < values.size(); i++) {
        t = t->next = new ListNode(values[i]);
    }
    
    Solution s;
    bool ret = s.isPalindrome(root);
    cout << (ret ? "true" : "false") << endl;
    return 0;
}