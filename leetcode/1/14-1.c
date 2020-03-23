//  14-1.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/21.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

int cuttingRope(int n){
    
    if (n < 2 || n > 58) {
        return -1;
    }
    
    if (n == 2) {
        return 1;
    } else if (n == 3){
        return 2;
    }
    
    int allMax[59] = {0};
    allMax[1] = 1;
    allMax[2] = 2;
    allMax[3] = 3;
        
    
    for (int i = 4; i <= n; i++) {
        
        for (int j = 1; j <= i/2; j++) {
            
            int m1 = j;
            int m2 = i - j;
            
            m1 = allMax[m1];
            m2 = allMax[m2];
            
            int tmp = m1 * m2;
            if (allMax[i] < tmp) {
                allMax[i] = tmp;
                                
                //printf("111, n: %d = %d + %d; max: %d = %d * %d \n", i, j, (i-j), allMax[i], m1, m2);
            }
            
        }
    }
    
    return allMax[n];
}

int cuttingRope_x(int n){
    if (n <= 1) {
        return 1;
    }
    
    int max = 0;
    int tmp = 0;
    for (int i = n/2; i > 0; i--) {
        int max1 = i;
        int max2 = n - i;
        
        tmp = cuttingRope(max1);
        if (max1 < tmp) {
            max1 = tmp;
        }
        
        tmp = cuttingRope(max2);
        if (max2 < tmp) {
            max2 = tmp;
        }
        
        tmp = max1 * max2;
        if (max < tmp) {
            max = tmp;
            
            printf("n=%d, %d = %d * %d \n", n, max, max1, max2);
        }
    }
    
    return max;
}

void test() {
    if( cuttingRope(2) != 1 ) {
        printf("fail");
    }

    if( cuttingRope(10) != 36 ) {
        printf("fail");
    }

    printf("end");
}
