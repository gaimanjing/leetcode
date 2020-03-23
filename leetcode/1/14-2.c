//  14-2.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/23.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

int cuttingRope(int n){
    if ( n < 2 || n > 1000) {
        return -1;
    }
    
    if ( n == 2 ) {
        return 1;
    }
    if ( n == 3 ) {
        return 2;
    }


    int timesOf3 = n / 3;
    int remain = n - 3 * timesOf3;
    if ( n % 3 == 1 ) {
        timesOf3 -= 1;
        remain += 3;
    }
        
    //答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
    long result = 1;
    for (int i = 1; i <= timesOf3; i++) {
//        signed integer overflow: 865810542 * 3 cannot be represented in type 'int'
        result *= 3;
        result %= 1000000007;
    }
    
    //remain: 0, 4(1+3), 2
    if (remain != 0) {
        result *= remain;
        result %= 1000000007;
    }
    
    return (int)result;
}

void test() {
    cuttingRope(1000);
    
    if (cuttingRope(2) != 1) {
        printf("fail");
    }

    if (cuttingRope(10) != 36) {
        printf("fail");
    }

    printf("end");

}
