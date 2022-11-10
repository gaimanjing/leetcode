//
//  isValidBST.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/10.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef isValidBST_hpp
#define isValidBST_hpp

#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution98 {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, long long min, long long max) {
        if(root) {
            if (root->val <= min || root->val >= max) {
                return false;
            }
            
            return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
        
        } else {
            return true;
        }
    }
};

#endif /* isValidBST_hpp */
