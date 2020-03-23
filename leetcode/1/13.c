//  13.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/21.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int m, int n, int k, bool* visited, int i, int j);
bool canVisit(int i, int j, int k);

int movingCount(int m, int n, int k){
    
    if (m <= 0 || n <= 0 || k < 0) {
        return 0;
    }
    
    int total = m * n;
    
    bool* visited = malloc( total * sizeof(bool));
    if (!visited) {
        return 0;
    }
    memset(visited, 0, total * sizeof(bool));
    
    dfs(m, n, k, visited, 0, 0);
    
    int visitedCount = 0;
    for (int i = 0; i < total; i++) {
        if (visited[i]) {
            visitedCount++;
        }
    }
    
    free(visited);
    
    return visitedCount;
    
}

void dfs(int m, int n, int k, bool* visited, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }

    //has visited
    if (visited[ i * n + j]) {
        return;
    }

    if (canVisit(i, j, k)) {
        visited[ i * n + j] = true;
        
        dfs(m, n, k, visited, i, j-1);
        dfs(m, n, k, visited, i, j+1);
        
        dfs(m, n, k, visited, i-1, j);
        dfs(m, n, k, visited, i+1, j);
    }
    
}

bool canVisit(int i, int j, int k) {
    int sum = 0;
    
    do {
        sum += i % 10;
        i = i / 10;
    } while (i > 0);

    do {
        sum += j % 10;
        j = j / 10;
    } while (j > 0);

    return sum <= k;
}

void test() {
    if (movingCount(2, 3, 1) != 3) {
        printf("fail");
    }

    if (movingCount(3, 1, 0) != 1) {
        printf("fail");
    }
    
    printf("test end");

}
