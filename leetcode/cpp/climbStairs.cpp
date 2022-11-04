//
//  climbStairs.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/4.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "climbStairs.hpp"

int Solution70::climbStairs(int n) {
    int pp = 0;
    int p = 1;
    int r = 0;
    
    for (int i = 1; i <= n; ++i) {
        r = pp + p;
        
        pp = p;
        p = r;
    }
    
    return r;
}
