//  24.c
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


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* newHead = NULL;
    struct ListNode* tmpNode = NULL;

    while (head) {
        tmpNode = head;
        head = tmpNode->next;
        tmpNode->next = newHead;
        newHead = tmpNode;
    }

    return newHead;
}
