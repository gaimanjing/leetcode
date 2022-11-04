//
//  minPathSum.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/4.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "minPathSum.hpp"

#include <algorithm>

int Solution64::minPathSum(vector<vector<int>>& grid) {
    const auto m = grid.size();
    const auto n = grid.front().size();
    
    vector<vector<int>> f(m, vector<int>(n));
    
    f[0][0] = grid[0][0];
    for (int i=1; i<m; ++i) {
        f[i][0] = f[i-1][0] + grid[i][0];
    }
    for (int j=1; j<n; ++j) {
        f[0][j] = f[0][j-1] + grid[0][j];
    }
    
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] = std::min(f[i-1][j], f[i][j-1]) + grid[i][j];
        }
    }
    
    return f[m-1][n-1];
}
