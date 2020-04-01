//  27.c
//  leetcode
//
//  Created by gaimanjing on 2020/4/1.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* mirrorTree(struct TreeNode* root){
    if (NULL == root) {
        return root;
    }

    struct TreeNode* left = root->left;
    
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(left);
    
    return root;
}
