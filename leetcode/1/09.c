//  09.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/18.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 10000

typedef struct {
    int headStack[STACK_MAX_SIZE]; //head, deleteHead
    int headStackIndex;
    
    int tailStack[STACK_MAX_SIZE]; //tail, appendTai
    int tailStackIndex;
    
} CQueue;


CQueue* cQueueCreate() {
    CQueue* queue = malloc(sizeof(CQueue));

    if (queue) {
        queue->headStackIndex = -1;
        queue->tailStackIndex = -1;
    }

    return queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
    if (!obj) {
        return;
    }
    
    if (obj->tailStackIndex == (STACK_MAX_SIZE - 1) ) {
        return;
    }
    
    int nextIndex = obj->tailStackIndex + 1;
    
    obj->tailStack[nextIndex] = value;
    
    obj->tailStackIndex = nextIndex;

}

int cQueueDeleteHead(CQueue* obj) {
    if (!obj) {
        return -1;
    }
    
    if (obj->headStackIndex >= 0 ) {
        int value = obj->headStack[obj->headStackIndex];
        obj->headStackIndex -= 1;
        return value;
    } else if (obj->tailStackIndex >= 0) {
        
        while (obj->tailStackIndex >= 0) {
            obj->headStackIndex++;
            obj->headStack[obj->headStackIndex] = obj->tailStack[obj->tailStackIndex];
            obj->tailStackIndex--;
        }
        
        return cQueueDeleteHead(obj);
    } else {
        return -1;
    }
    

}

void cQueueFree(CQueue* obj) {
    if(obj) {
        free(obj);
    }
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/


void test1() {

    CQueue* obj = cQueueCreate();
    cQueueAppendTail(obj, 3);
    
    int param_2 = cQueueDeleteHead(obj);
    param_2 = cQueueDeleteHead(obj);
    
    cQueueFree(obj);
}

void test2() {

    CQueue* obj = cQueueCreate();
    
    int deleteResult = cQueueDeleteHead(obj);
    cQueueAppendTail(obj, 5);
    cQueueAppendTail(obj, 2);

    deleteResult = cQueueDeleteHead(obj);
    deleteResult = cQueueDeleteHead(obj);
    
    cQueueFree(obj);
}

void test() {
    test1();
    test2();
}
