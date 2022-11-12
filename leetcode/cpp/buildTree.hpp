//
//  buildTree.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/12.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef buildTree_hpp
#define buildTree_hpp

#include "TreeNode.hpp"

#include <algorithm>
#include <vector>
using std::vector;

class Solution105 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder[0]);
        
        auto left_len = it - inorder.begin();
        
        vector<int> left_pre_order(preorder.begin() + 1,
                                   preorder.begin() + 1 + left_len) ;
        vector<int> right_pre_order(preorder.begin() + 1 + left_len,
                                    preorder.end());
        
        vector<int> left_in_order(inorder.begin(), inorder.begin() + left_len);
        vector<int> right_in_order(it + 1, inorder.end());
        
        root->left = buildTree(left_pre_order, left_in_order);
        root->right = buildTree(right_pre_order, right_in_order);
        
        return root;
    }
};

#endif /* buildTree_hpp */
