//  29.c
//  leetcode
//
//  Created by gaimanjing on 2020/4/1.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void spiralOrderCore(int** matrix, int i, int j, int width, int height, int* output);


int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    if (NULL == matrix || (matrixSize < 1) || matrixColSize == NULL  || (*matrixColSize < 1) || NULL == returnSize) {
        if (returnSize) {
            *returnSize = 0;
        }
        return NULL;
    }
    
    int* ret = malloc(sizeof(int) * matrixSize * (*matrixColSize));
    if (ret) {
        *returnSize = matrixSize * (*matrixColSize);

        spiralOrderCore(matrix, 0, 0, *matrixColSize, matrixSize, ret);
        
    } else {
        *returnSize = 0;
    }
    
    return ret;
}

void spiralOrderCore(int** matrix, int i, int j, int width, int height, int* output) {
    if (width <= 0 || height <= 0) {
        return;
    }
    
    int index = 0;
    
    for (int column = 0; column < width; column++) {
        output[index] = matrix[i][j+column];
        index++;
    }
    
    if (width >= 1) {
        for (int row = 1; row < height; row++) {
            output[index] = matrix[i+row][j+width-1];
            index++;
        }
    }

    if (height >= 2) {
        for (int column = width-2; column >= 0; column--) {
            output[index] = matrix[i+height-1][j+column];
            index++;
        }
    }

    if (height >= 3 && width >= 2) {
        for (int row = height-2; row >= 1 ; row--) {
            output[index] = matrix[i+row][j];
            index++;
        }
    }
    
    spiralOrderCore(matrix, i+1, j+1, width-2, height-2, output+index);

}
