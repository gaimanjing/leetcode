//
//  maxSubArray.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/2.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef maxSubArray_hpp
#define maxSubArray_hpp

#include <vector>
using std::vector;

class Solution53 {
public:
    int maxSubArray(vector<int>& nums);
    
private:
    int maxSubArray2(vector<int>& nums);
    struct Status {
        int lSum, rSum, mSum, iSum;
    };
    Status pushUp(Status left, Status right);
    Status get(vector<int>& nums, int left, int right);
};

#endif /* maxSubArray_hpp */
