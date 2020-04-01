//  28.c
//  leetcode
//
//  Created by gaimanjing on 2020/4/1.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetricCore(struct TreeNode* root1, struct TreeNode* root2);

bool isSymmetric(struct TreeNode* root){
    if (NULL == root) {
        return true;
    }
    
    return isSymmetricCore(root->left, root->right);
}

bool isSymmetricCore(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == root2) {
        return true;
    }
    
    if (NULL == root1 || NULL == root2) {
        return false;
    }
    
    if (root1->val == root2->val) {
        return isSymmetricCore(root1->left, root2->right) && isSymmetricCore(root1->right, root2->left);
    }
    
    return false;
}
