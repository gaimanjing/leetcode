//  21.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/26.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* exchange(int* nums, int numsSize, int* returnSize){
    if ((NULL == nums) || (numsSize < 1) || (NULL == returnSize)) {
        if (returnSize) {
            *returnSize = 0;
        }
        return NULL;
    }
    
    int* retNums = malloc(sizeof(int) * numsSize);
    if (NULL == retNums) {
        return NULL;
    }
    int head = 0;
    int tail = numsSize - 1;
    for (int i = 0; i< numsSize; i++) {
        if (nums[i] & 1) {
            retNums[head] = nums[i];
            head++;
        } else {
            retNums[tail] = nums[i];
            tail--;
        }
    }
    
    *returnSize = numsSize;
    return retNums;
}

void test() {
    int* retNums;
    int returnSize;
    
    int nums1[] = {1, 2, 3, 4};
    retNums = exchange(nums1, 4, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d, ", retNums[i]);
    }
    printf("\n");
}

