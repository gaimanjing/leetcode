//
//  merge.cpp
//  leetcode
//
//  Created by houguanhua on 2022/11/3.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#include "merge.hpp"

#include <algorithm>

vector<vector<int>> Solution56::merge(vector<vector<int>> &intervals) {
    vector<vector<int>> merged;
    
    sort(intervals.begin(), intervals.end());
    
    for (auto r : intervals) {
        if (merged.empty()) {
            merged.push_back(r);
        } else {
            vector<int>& lastRange = merged.back();
            
            if(r[0] <= lastRange[1]) {
                lastRange[1] = std::max(lastRange[1], r[1]);
            } else {
                merged.push_back(r);
            }
        }
    }
    
    return merged;
}
