//  15.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/23.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

int hammingWeight(uint32_t n) {
    int count = 0;

    while (n) {
        count++;
        
        n = n & (n - 1);
    }
    
    return count;
}

void test() {
        
    if (hammingWeight(0b00000000000000000000000000001011) != 3) {
        printf("fail");
    }

    if (hammingWeight(0b00000000000000000000000010000000) != 1) {
        printf("fail");
    }

    if (hammingWeight(0b11111111111111111111111111111101) != 31) {
        printf("fail");
    }

    printf("end");
}
