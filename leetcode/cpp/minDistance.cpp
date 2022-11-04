//
//  minDistance.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/4.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "minDistance.hpp"

#include <vector>
#include <algorithm>

using std::vector;
using std::min;

int Solution72::minDistance(string word1, string word2){
    auto m = word1.size();
    auto n = word2.size();
    
    if (m == 0) {
        return static_cast<int>(n);
    }
    if (n == 0) {
        return static_cast<int>(m);
    }
    
    vector<vector<int>> d(m+1, vector<int>(n+1));
    d[0][0] = 0;
    for (int i=1; i<=m; ++i) {
        d[i][0] = i;
    }
    
    for (int j=1; j<=n; ++j) {
        d[0][j] = j;
    }
    
    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            if (word1[i-1] == word2[j-1]) {
                d[i][j] = min(min((d[i-1][j] + 1), (d[i][j-1] + 1)), d[i-1][j-1]);
            } else {
                d[i][j] = min(min((d[i-1][j]), (d[i][j-1])), d[i-1][j-1]) + 1;
            }
        }
    }
    
    return d[m][n];
}
