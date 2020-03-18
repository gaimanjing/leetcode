//  07.c
//  leetcode
//
//  Created by gaimanjing on 2020/3/18.
//  Copyright © 2020 gaimanjing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(!preorder ||
       preorderSize == 0 ||
       !inorder ||
       preorderSize != inorderSize) {
        return NULL;
    }
    
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    if(!root) {
        return NULL;
    }
    
    root->val = preorder[0];
    
    for(int i = 0; i < inorderSize; i++) {
        if(inorder[i] == root->val) {
            int leftSize = i;
            int rightSize = preorderSize - 1 - leftSize;
            
            root->left = buildTree((preorder + 1), leftSize, inorder, leftSize);
            root->right = buildTree((preorder + 1 + leftSize), rightSize, (inorder + leftSize + 1), rightSize);
            
            break;
        }
    }
    
    return root;
}

void test() {

    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    
    struct TreeNode* root = buildTree(preorder, 5, inorder, 5);

}
