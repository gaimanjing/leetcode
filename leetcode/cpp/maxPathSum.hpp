//
//  maxPathSum.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/15.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef maxPathSum_hpp
#define maxPathSum_hpp

#include "TreeNode.hpp"

#include <limits>
#include <algorithm>
using std::max;

class Solution124 {
public:
    int maxPathSum(TreeNode* root) {
        maxSumEndWith(root);
        return maxSum;
    }
    
private:
    int maxSum = std::numeric_limits<int>::min();
    
    int maxSumEndWith(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int left = max(0, maxSumEndWith(root->left));
        int right = max(0, maxSumEndWith(root->right));
        
        int inPathSum = left + root->val + right;
        maxSum = max(inPathSum, maxSum);
        
        return root->val + max(left, right);
    }
};

#endif /* maxPathSum_hpp */
