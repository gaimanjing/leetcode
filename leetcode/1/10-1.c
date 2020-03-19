//  10-1.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/19.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

int fib(int n) {
    
    int pre_pre_fn = 0;
    int pre_fn = 1;
    int fn = 0;

    if(n < 0) {
        return -1;
    }
    
    if (n == 0) {
        return 0;
        
    } else if ( n == 1) {
        return 1;
        
    } else  { // n >= 2
        int current = 2;
        
        while (current <= n) {
            fn = pre_fn + pre_pre_fn;
            
//            答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
            fn %= 1000000007;
            
//          前 300 个 Fibonacci 数：  http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibtable.html
//            printf(" fib( %d ) = %d \n", (current), fn);
            
            pre_pre_fn = pre_fn;
            pre_fn = fn;
            
            current += 1;
        }
    }
    
    return fn;
}

void test() {
    if ( fib(45) != 134903163) {
        printf("fib 45 fail");
    }
    
    if( fib(2) != 1 ) {
        printf("case 2 fail");
    }

    if( fib(5) != 5 ) {
        printf("case 5 fail");
    }

}
