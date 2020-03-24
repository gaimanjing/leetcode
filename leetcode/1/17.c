//  17.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/24.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* printNumbers(int n, int* returnSize){
    if (n < 1) {
        return NULL;
    }
    
    if (NULL == returnSize) {
        return NULL;
    }
    
    //int.max is 2147483647
    if (n >= 9) {
        return NULL;
    }
    
    int max = 1;
    while ( n ) {
        max *= 10;
        n--;
    }
    
    int* result = malloc(sizeof(int) * (max -1) );
    if (NULL == result) {
        return NULL;
    }
    
    for (int i = 1; i < max; i++) {
        result[i-1] = i;
    }
    
    *returnSize = max - 1;

    return result;
}

void test() {
    int* result = NULL;
    
    int size = 0;
    result = printNumbers(1, &size);
    if (size != 9) {
        printf("fail");
    }
    free(result);
    
    result = printNumbers(8, &size);
    printf("size = %d", size);
    if(result) {
        free(result);
    }

    result = printNumbers(0x7fffffff, &size);
    printf("size = %d", size);
    if(result) {
        free(result);
    }    
    
    printf("end");
}
