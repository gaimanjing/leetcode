//
//  flatten.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/14.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef flatten_hpp
#define flatten_hpp

#include "TreeNode.hpp"

class Solution114 {
public:
    void flatten(TreeNode* root) {
        TreeNode head;
        TreeNode* phead = &head;
        
        dfs(root, &phead);
    }
    
private:
    void dfs(TreeNode* root, TreeNode** ptail) {
        if (!root) {
            return;
        }
        
        (*ptail)->right = root;
        *ptail = root;
        
        TreeNode* left = root->left;
        root->left = nullptr;
        
        TreeNode* right = root->right;
        root->right = nullptr;
        
        dfs(left, ptail);
        dfs(right, ptail);
    }
};

#endif /* flatten_hpp */
