//
//  TreeNode.hpp
//  leetcode
//
//  Created by houguanhua on 2022/11/12.
//  Copyright © 2022 gaimanjing. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif /* TreeNode_hpp */
