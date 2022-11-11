//
//  isSymmetric.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/11.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef isSymmetric_hpp
#define isSymmetric_hpp

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution101 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
    
private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        
        if (!left || !right) {
            return false;
        }
        
        if (left->val != right->val) {
            return false;
        }
        
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

#endif /* isSymmetric_hpp */
