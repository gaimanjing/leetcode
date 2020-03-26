//  25.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/26.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (NULL == l1) {
        return l2;
    }
    
    if (NULL == l2) {
        return l1;
    }
    
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            if (tail) {
                tail->next = l1;
            } else {
                head = l1;
                tail = l1;
            }

            tail = l1;
            l1 = l1->next;
        } else {
            if (tail) {
                tail->next = l2;
            } else {
                head = l2;
                tail = l2;
            }

            tail = l2;
            l2 = l2->next;
        }
    }
    
    if (l1) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return head;
}
