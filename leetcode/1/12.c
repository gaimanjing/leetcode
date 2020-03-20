//  12.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/20.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool exist_core(char** board, int boardRowSize, int boardColSize, char* word, bool* boardMark, int currentRowIndex, int currentColIndex);


bool exist(char** board, int boardSize, int* boardColSize, char* word){
    if ( !board || boardSize<=0 || !boardColSize || *boardColSize<=0 || !word ) {
        return false;
    }
    
    u_long len = strlen(word);
    if (len == 0) {
        return false;
    }
    
    int elementCount = boardSize * (*boardColSize);
    bool* boardMark = malloc(sizeof(bool) * elementCount);
    if (boardMark) {
        
        for (int i=0; i < elementCount; i++) {
            boardMark[i] = false;
        }

        for (int i=0; i < boardSize; i++) {
            for (int j=0; j < *boardColSize; j++) {
                if (board[i][j] == word[0] ) {
                    
                    boardMark[i * (*boardColSize) + j] = true;
                    if (exist_core(board, boardSize, *boardColSize, word+1, boardMark, i, j)) {
                        free(boardMark);

                        return true;
                    } else {
                        boardMark[i * (*boardColSize) + j] = false;
                    }
                       
                }
            }
        }
        
        free(boardMark);
    }

    return false;
}

bool exist_core(char** board, int boardRowSize, int boardColSize, char* word, bool* boardMark, int currentRowIndex, int currentColIndex) {
    if (*word == 0) {   //结束符
        return true;
    }
    
    int nextRowIndex = 0;
    int nextColIndex = 0;

    int nextDirection[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; //left, right, up, down

    for (int i = 0; i < 4; i++) {
        nextRowIndex = currentRowIndex + nextDirection[i][0];
        nextColIndex = currentColIndex + nextDirection[i][1];
        
        if ((nextRowIndex >= 0) && (nextRowIndex < boardRowSize)
            && (nextColIndex >= 0) && (nextColIndex < boardColSize)
            && (false == boardMark[nextRowIndex * boardColSize + nextColIndex])
            && (board[nextRowIndex][nextColIndex] == word[0])) {
            
            boardMark[nextRowIndex * boardColSize + nextColIndex] = true;
            
            if (exist_core(board, boardRowSize, boardColSize, word+1, boardMark, nextRowIndex, nextColIndex)) {
                return true;
            }
            
            boardMark[nextRowIndex * boardColSize + nextColIndex] = false;
        }

    }

    
    return false;
}


void test() {
    char* board3[] = { "ABCE", "SFES", "ADEE"};
    char* word3 = "ABCESEEEFS";
    
    int boardColSize3 = 4;
    if (!exist(board3, 3, &boardColSize3, word3)) {
        printf("fail");
    }

    char* board1[] = { "ABCE", "SFCS", "ADEE"};
    char* word1 = "ABCCED";
    
    int boardColSize1 = 4;
    if (!exist(board1, 3, &boardColSize1, word1)) {
        printf("fail");
    }

    char* board2[] = {"ab",
        "cd"};
    char* word2 = "abcd";
    
    int boardColSize2 = 2;
    if (exist(board2, 2, &boardColSize2, word2)) {
        printf("fail");
    }


}
