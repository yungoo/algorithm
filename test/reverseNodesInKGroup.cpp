//
//  reverseNodesInKGroup.cpp
//  test
//
//  Created by haiyang on 16/4/16.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || !head) return head;
        
        ListNode dummy(0);
        
        ListNode *tail = &dummy, *pre = NULL;
        dummy.next = head;
        
        int i = 0;
        while (tail) {
            i++;
            if (i == k) {
                i = 0;
                tail = reverse(pre, tail);
            } else if (i == 0) {
                pre = tail;
                tail = tail->next;
            } else {
                tail = tail->next;
            }
            
        }
        return dummy.next;
    }
    
private:
    ListNode* reverse(ListNode *begin, ListNode *end) {
        ListNode *prehead = begin, *tail = end->next;
        
        ListNode *b = begin->next, *itr = b->next, *t;
        while (itr != tail) {
            t = itr->next;
            itr->next = b;
            b = itr;
            itr = t;
        }
        
        t = prehead->next;
        t->next = tail;
        prehead->next = b;
        return t;
    }
};

int main_reverseNodesInKGroup(int argc, const char *argv[]) {
    ListNode *h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    
    Solution s;
    ListNode *r = s.reverseKGroup(h, 3);
    
    while (r) {
        cout << r->val << "->";
        r = r->next;
    }
    cout << endl;
    return 0;
}