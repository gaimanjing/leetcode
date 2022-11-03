//
//  canJump.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/3.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "canJump.hpp"
#include <algorithm>

bool Solution55::canJump(vector<int>& nums) {
    int rightMost = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i <= rightMost) {
            rightMost = std::max(rightMost, i + nums[i]);
            if (rightMost >= nums.size() -1) {
                return true;
            }
        }
    }
    
    return false;
}
