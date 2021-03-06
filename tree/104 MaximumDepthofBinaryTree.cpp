//
//  MaximumDepthofBinaryTree.cpp
//  Leetcode
//
//  Created by Quinn on 2020/7/27.
//  Copyright © 2020 Quinn. All rights reserved.
//

#include "TreeNode.h"
#include <queue>
#include <stack>
using namespace::std;

// not a tail recursion because it does some computation after the recursive call returned.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*
 自顶向下
1. return specific value for null node
2. update the answer if needed                      // anwer <-- params
3. left_ans = top_down(root.left, left_params)      // left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
5. return the answer if needed                      // answer <-- left_ans, right_ans
 
 1. return if root is null
 2. if root is a leaf node:
 3.      answer = max(answer, depth)         // update the answer if needed
 4. maximum_depth(root.left, depth + 1)      // call the function recursively for left child
 5. maximum_depth(root.right, depth + 1)     // call the function recursively for right child
*/
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode *root, int depth, int &ans)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            ans = max(ans, depth + 1);
            return;
        }

        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);
    }
};


