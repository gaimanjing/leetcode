//
//  levelOrder.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/12.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef levelOrder_hpp
#define levelOrder_hpp

#include "TreeNode.hpp"

#include <vector>

using std::vector;

class Solution102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        vector<TreeNode*> currentLevel;
        if (root) {
            currentLevel.push_back(root);
        }
        
        while (!currentLevel.empty()) {
            vector<int> levelValue;
            vector<TreeNode*> nextLevel;
            
            for (TreeNode* node : currentLevel) {
                levelValue.push_back(node->val);
                
                if (node->left) {
                    nextLevel.push_back(node->left);
                }
                if (node->right) {
                    nextLevel.push_back(node->right);
                }
            }
            
            ans.push_back(levelValue);
            currentLevel = nextLevel;
        }
        
        return ans;
    }
};

#endif /* levelOrder_hpp */
