//  20.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/24.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool scanUnsignedInt(char* s, char** end);
bool scanSignedInt(char* s, char** end);

bool isDigit(char ch) {
    return (ch >= '0') && (ch <= '9');
}

bool isEnd(char* s) {
    while (*s == ' ') {
        s++;
    }
    return *s == '\0';
}

bool isNumber(char* s){
    if(NULL == s) {
        return false;
    }

    //trim begin
    while (*s == ' ') {
        s++;
    }
    
    bool isNumber = false;
    char* str;
    isNumber = scanSignedInt(s, &str);

    if (*str == '.') {
        str++;
        isNumber = scanUnsignedInt(str, &str) || isNumber;
    }
    
    if (*str == 'e' || *str == 'E') {
        str++;
        
        isNumber = isNumber && scanSignedInt(str, &str);
    }
    
    return isNumber && isEnd(str);
}

bool scanUnsignedInt(char* s, char** end) {
    bool isNumber = false;
    
    while (isDigit(*s)) {
        s++;
        isNumber = true;
    }
    
    *end = s;
    
    return isNumber;
}

bool scanSignedInt(char* s, char** end) {
    if (*s == '+' || *s=='-') {
        s++;
    }
    
    return scanUnsignedInt(s, end);
}

void fail() {
    printf("false \n");
}

void test() {
    if (isNumber("1 ") != true) {
        fail();
    }

    if (isNumber("+100") != true) {
        fail();
    }
    if (isNumber("5e2") != true) {
        fail();
    }
    if (isNumber("-123") != true) {
        fail();
    }
    if (isNumber("3.1416") != true) {
        fail();
    }
    if (isNumber("0123") != true) {
        fail();
    }
    if (isNumber("-1E-16") != true) {
        fail();
    }

    if (isNumber("12e") != false) {
        fail();
    }
    if (isNumber("1a3.14") != false) {
        fail();
    }
    if (isNumber("1.2.3") != false) {
        fail();
    }
    if (isNumber("+-5") != false) {
        fail();
    }
    if (isNumber("12e+5.4") != false) {
        fail();
    }
}
