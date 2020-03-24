//  18.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/24.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode* delete = head;
    struct ListNode* preDelete = head;
    
    if (head) {
        if (head->val == val) {
            return head->next;
        } else {
            preDelete = head;
            delete = preDelete->next;
            
            while (delete) {
                if (delete->val == val) {
                    preDelete->next = delete->next;
                    break;
                } else {
                    preDelete = delete;
                    delete = preDelete->next;
                }
            }
        }
    }
    
    return head;
}
