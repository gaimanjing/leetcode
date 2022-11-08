//
//  subsets.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/8.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "subsets.hpp"

vector<vector<int>> Solution78::subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> item;
    for (int mask = 0; mask < (1 << nums.size()); ++mask) {
        for (int i = 0; i < nums.size(); ++i) {
            if ( (1 << i) & mask) {
                item.push_back(nums[i]);
            }
        }
        result.push_back(item);
        item.clear();
    }
    return result;
}
