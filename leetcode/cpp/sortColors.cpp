//
//  sortColors.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/4.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "sortColors.hpp"

#include <algorithm>

void Solution75::sortColors(vector<int>& nums) {
    int p = 0;
    for (int i=0; i<nums.size(); ++i) {
        if (nums[i] == 0) {
            std::swap(nums[p], nums[i]);
            ++p;
        }
    }
    
    for (int i=p; i<nums.size(); ++i) {
        if (nums[i] == 1) {
            std::swap(nums[p], nums[i]);
            ++p;
        }
    }
}
