//
//  inorderTraversal.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/10.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef inorderTraversal_hpp
#define inorderTraversal_hpp

#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution94 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversal(ans, root);
        return ans;
    }
    
private:
    void inorderTraversal(vector<int>& ans, TreeNode* root) {
        if (root) {
            inorderTraversal(ans, root->left);
            ans.push_back(root->val);
            inorderTraversal(ans, root->right);
        }
    }
    
};

#endif /* inorderTraversal_hpp */
