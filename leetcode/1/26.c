//  26.c
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

bool isSubStructureCore(struct TreeNode* A, struct TreeNode* B);

bool isSubStructure(struct TreeNode* A, struct TreeNode* B) {
    
    if (A == B) {
        return true;
    }
    
    if ((NULL == A) || (NULL == B)) {
        return false;
    }
    
    if (A->val == B->val) {
        return isSubStructureCore(A, B);
    } else {
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

}

bool isSubStructureCore(struct TreeNode* A, struct TreeNode* B) {

    if (A == B) {
        return true;
    }
    
    if ((NULL == A) || (NULL == B)) {
        return false;
    }
    
    if (A->val == B->val) {
        bool ret = true;

        if (B->left) {
            ret = ret && isSubStructureCore(A->left, B->left);
        }
        if (B->right) {
            ret = ret && isSubStructureCore(A->right, B->right);
        }

        return ret;
    } else {
        return false;
    }

}
