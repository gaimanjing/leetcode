//
//  maxDepth.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/12.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef maxDepth_hpp
#define maxDepth_hpp

#include "TreeNode.hpp"

#include <vector>
using std::vector;

class Solution104 {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        
        vector<TreeNode*> currentLevel;
        if (root) {
            currentLevel.push_back(root);
        }
        
        while (!currentLevel.empty()) {
            ++ans;
            
            vector<TreeNode*> nextLevel;
            for (TreeNode* node : currentLevel) {
                if (node->left) {
                    nextLevel.push_back(node->left);
                }
                if (node->right) {
                    nextLevel.push_back(node->right);
                }
            }
            currentLevel = nextLevel;
        }

        return ans;
    }
};

#endif /* maxDepth_hpp */
