//  11.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/19.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

int minArray(int* numbers, int numbersSize){
    if ( numbers == NULL || numbersSize == 0) {
        return 0;
    }
    
    int left = 0;
    int right = numbersSize - 1;
    int mid = left;
    
    while ( 1 ) {
        if (right == left) {
            mid = left;
            break;
        } else if( right - left == 1) {
            mid =  numbers[left] < numbers[right] ? left : right;
            break;
        } else if (numbers[left] < numbers[right]) {    //递增顺序
            mid = left;
            break;
        }
        
        
        mid = ( left + right ) / 2;
        
        if ( numbers[mid] > numbers[left] ) {
            left = mid;
        } else if ( numbers[mid] < numbers[right] ) {
            right = mid;
        } else if ( numbers[mid] == numbers[left] ) {
            left++;
        } else if ( numbers[mid] == numbers[right] ) {
            right--;
        }
        
    }
    
    return numbers[mid];
}

void test() {
    int numbers7[] = {3, 3, 1, 3};
    if (minArray(numbers7, 4) != 1 ) {
        printf("fail");
    }

    int numbers6[] = {10, 1, 10, 10, 10};
    if (minArray(numbers6, 5) != 1 ) {
        printf("fail");
    }

    int numbers5[] = {1};
    if (minArray(numbers5, 1) != 1 ) {
        printf("fail");
    }

    int numbers4[] = {3, 1, 3};
    if (minArray(numbers4, 3) != 1 ) {
        printf("fail");
    }

    int numbers3[] = {1, 3, 5};
    if (minArray(numbers3, 3) != 1 ) {
        printf("fail");
    }
    
    int numbers1[] = {3, 4, 5, 1, 2};
    if (minArray(numbers1, 5) != 1 ) {
        printf("fail");
    }
    
    int numbers2[] = {2, 2, 2, 0, 1};
    if (minArray(numbers2, 5) != 0 ) {
        printf("fail");
    }

}
