//
//  maximalRectangle.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/9.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef maximalRectangle_hpp
#define maximalRectangle_hpp

#include <vector>
#include <stack>
#include <algorithm>

using std::vector;
using std::stack;
using std::max;

class Solution85 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        
        int rows = static_cast<int>(matrix.size());
        int columns = static_cast<int>(matrix[0].size());
        
        vector<vector<int>> left(rows, vector<int>(columns));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (matrix[i][j] == '1') {
                    if(j > 0) {
                        left[i][j] = left[i][j-1] + 1;
                    } else {
                        left[i][j] = 1;
                    }
                } else {
                    left[i][j] = 0;
                }
            }
        }
        
        vector<vector<int>> up(rows, vector<int>(columns));
        vector<vector<int>> down(rows, vector<int>(columns, rows));
        
        for (int j = 0; j < columns; ++j) {
            stack<int> mono_stack;
            for (int i = 0; i < rows; ++i) {
                while (!mono_stack.empty() && (left[mono_stack.top()][j] > left[i][j])) {
                    down[mono_stack.top()][j] = i;
                    mono_stack.pop();
                }
                
                up[i][j] = mono_stack.empty() ? -1 : mono_stack.top();
                mono_stack.push(i);
            }
        }
        
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                ans = max(ans, left[i][j] * (down[i][j] - up[i][j] - 1));
            }
        }
        return ans;
    }
};

#endif /* maximalRectangle_hpp */
