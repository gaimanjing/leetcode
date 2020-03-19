//  10-2.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/19.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

int numWays(int n){
    int ways = 0;
        
    if (n <= 1) {
        return 1;
        
    } else if ( n == 2 ) {
        return 2;
        
    } else {    //n >= 3
        int pre_pre_ways = 1;
        int pre_ways = 2;
        
        int current = 3;
        while ( current <= n ) {
            ways = pre_pre_ways + pre_ways;
            
            //答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
            ways %= 1000000007;
//            printf(" n=%d, ways=%d \n", current, ways);
            
            pre_pre_ways = pre_ways;
            pre_ways = ways;
            
            current += 1;
        }
    }
    
    return ways;
}

void test() {

    int ways = 0;
    
    ways = numWays(2);
    if (ways != 2) {
        printf("n=2 fail, returned ways=%d \n", ways);
    }

    ways = numWays(7);
    if (ways != 21) {
        printf("n=7 fail, returned ways=%d \n", ways);
    }

}
