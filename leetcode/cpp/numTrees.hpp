//
//  numTrees.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/10.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef numTrees_hpp
#define numTrees_hpp

#include <vector>

using std::vector;

class Solution96 {
public:
    int numTrees(int n) {
        vector<int> ans(n+1, 0);
        
        ans[0] = 1;
        ans[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                ans[i] += ans[j-1] * ans[i-j];
            }
        }
        
        return ans[n];
    }
};

#endif /* numTrees_hpp */
