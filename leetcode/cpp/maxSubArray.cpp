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
    return maxSubArray2(nums);
    
    int sum = 0;
    int result = nums[0];
    
    for (const auto &num : nums) {
        sum = max(sum + num, num);
        
        result = max(result, sum);
    }
    
    return result;
}


int Solution53::maxSubArray2(vector<int>& nums) {
    return get(nums, 0, nums.size()-1).mSum;
}

Solution53::Status Solution53::pushUp(Status left, Status right) {
    Status result;
    
    result.lSum = max(left.lSum, left.iSum + right.lSum);
    result.rSum = max(right.rSum, right.iSum + left.rSum);
    result.iSum = left.iSum + right.iSum;
    result.mSum = max(max(left.mSum, right.mSum), (left.rSum + right.lSum));
    
    return result;
}

Solution53::Status Solution53::get(vector<int> &nums, int left, int right) {
    if (left == right) {
        return Status{nums[left], nums[left], nums[left], nums[left]};
    }
    
    int mid = (left + right) / 2;
    
    Status leftStatus = get(nums, left, mid);
    Status rightStatus = get(nums, mid+1, right);
    
    return pushUp(leftStatus, rightStatus);
}
