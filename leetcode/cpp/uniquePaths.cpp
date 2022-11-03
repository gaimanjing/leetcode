//
//  uniquePaths.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/3.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "uniquePaths.hpp"

#include <vector>
using std::vector;

int Solution62::uniquePaths(int m, int n) {
    vector<vector<int>> flag(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        flag[i][0] = 1;
    }
    
    for (int j = 0; j < n; ++j) {
        flag[0][j] = 1;
    }
    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            flag[i][j] = flag[i-1][j] + flag[i][j-1];
        }
    }
    
    return flag[m-1][n-1];
}
