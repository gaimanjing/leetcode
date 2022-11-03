//
//  maxSubArray.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/2.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "maxSubArray.hpp"

#include <algorithm>
using std::max;

int Solution53::maxSubArray(vector<int>& nums) {
    int sum = 0;
    int result = nums[0];
    
    for (const auto &num : nums) {
        sum = max(sum + num, num);
        
        result = max(result, sum);
    }
    
    return result;
}
