//
//  reverseLinkedListII.cpp
//  test
//
//  Created by haiyang on 16/4/15.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *tail = &dummy;
        
        ListNode *begin = &dummy;
        head = begin;
        
        int i = 0;
        while (head) {
            if (i < m) {
                tail = begin = head;
                head = head->next;
                i++;
            } else if (n >= m) {
                n--;
                
                ListNode *t = head->next;
                head->next = tail;
                tail = head;
                head = t;
            } else {
                break;
            }
        }
        
        if (begin->next) {
            ListNode *t = begin->next;
            begin->next = tail;
            t->next = head;
        }
        
        return dummy.next;
    }
};

int main_reverseLinkedList(int argc, const char *argv[]) {
    ListNode *header = new ListNode(1);
    header->next = new ListNode(2);
    header->next->next = new ListNode(3);
    header->next->next->next = new ListNode(4);
    header->next->next->next->next = new ListNode(5);
    
    Solution s;
    ListNode *r = s.reverseBetween(header, 2, 4);
    while (r) {
        cout << r->val << "->";
        r = r->next;
    }
    return 0;
}