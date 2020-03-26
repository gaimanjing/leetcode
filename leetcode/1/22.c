//  22.c
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

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if (head == NULL || k < 1) {
        return NULL;
    }
    
    struct ListNode* retNode = NULL;
    struct ListNode* quickNode = head;
    
    for (int i = 1; i < k; i++) {
        if (quickNode->next) {
            quickNode = quickNode->next;
        } else {
            return NULL;
        }
    }

    retNode = head;
    while (quickNode->next) {
        quickNode = quickNode->next;
        retNode = retNode->next;
    }

    return retNode;
}
