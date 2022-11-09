//
//  largestRectangleArea.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/9.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef largestRectangleArea_hpp
#define largestRectangleArea_hpp

#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::max;

class Solution84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        vector<int> left(n), right(n, n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && (heights[mono_stack.top()] > heights[i])) {
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            
            left[i] = mono_stack.empty() ? -1 : mono_stack.top();
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};

#endif /* largestRectangleArea_hpp */
