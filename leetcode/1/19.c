//  19.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/24.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool isMatchCore(char* s, char* p);

bool isMatch(char* s, char* p){
    
    if(NULL == s || NULL == p) {
        return false;
    }
        
    return isMatchCore(s, p);
}

bool isMatchCore(char* s, char* p) {
    if (*s == '\0' && *p == '\0') {
        return true;
    }

    if (*s != '\0' && *p == '\0') {
        return false;
    }
    
    if (*(p+1) == '*') {
        if ( (*p == *s) || (*p == '.' && *s != '\0') ) {
            return isMatchCore(s+1, p+2) ||
                isMatchCore(s+1, p) ||
                isMatchCore(s, p+2);
        } else {
            return isMatchCore(s, p+2);
        }
    }
    
    if ( (*p == *s) || (*p == '.' && *s != '\0') ) {
        return isMatchCore(s+1, p+1);
    }
    
    return false;
}


void test() {
    if (isMatch("a", "ab*a") != false) {
        printf("fail \n");
    }
    
    if (isMatch("aaa", "a*a") != true) {
        printf("fail \n");
    }
    
    if (isMatch("ab", ".*c") != false) {
        printf("fail \n");
    }

    if (isMatch("aa", "a") != false) {
        printf("fail \n");
    }

    if (isMatch("aa", "a*") != true) {
        printf("fail \n");
    }

    if (isMatch("ab", ".*") != true) {
        printf("fail \n");
    }

    if (isMatch("aab", "c*a*b") != true) {
        printf("fail \n");
    }

    printf("end \n");

}
