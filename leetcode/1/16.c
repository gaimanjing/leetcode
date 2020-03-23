//  16.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/23.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

double myPowCore(double x, unsigned n);

double myPow(double x, int n){

//    -100.0 < x < 100.0
//    n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
    
    double result = 0;

    bool negativeResult = false;   //正负数
    bool negativeExponent = false;  //倒数
    
    unsigned unsignedExponent = n;
    
    if (n == 0) {
        return 1;
    } else if( n < 0 ) {
        //negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself
        long exponent = n;
        unsignedExponent = (unsigned)(-exponent);
        negativeExponent = true;
    }

    if ( x == 0) {
        if (negativeExponent) {
            return -1;  //error
        } else {
            return 0;
        }
    } else if (x < 0) {
        x = -x;
        if ( n & 1) {
            negativeResult = true;
        }
    }
    
    result = myPowCore(x, unsignedExponent);
    if (negativeExponent) {
        result = 1 / result;
    }
    if (negativeResult) {
        result *= -1;
    }
    
    return result;
}

double myPowCore(double x, unsigned n) {
    double result = 0;
    
    if (x == 1) {
        return 1;
    }

    if ( n == 1 ) {
        return x;
    } else if ( n == 2 ) {
        return x * x;
    }
    
    result = myPowCore(myPowCore(x, n/2), 2);
    
    if ( n & 1) {
        result *= x;
    }
    
    return result;
}


void test() {
    printf("%f \n", myPow(1.0, -2147483648));
    
    printf("%f \n", myPow(0.44528, 0));

    printf("%f \n", myPow(2.0, 10));

    printf("%f \n", myPow(2.1, 3));

    printf("%f \n", myPow(2.0, -2));

}
