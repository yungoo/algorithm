//
//  lowestCommonAncestor.cpp
//  test
//
//  Created by haiyang on 16/4/13.
//  Copyright © 2016年 yingtian corp. All rights reserved.
//

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        return l && r ? root : l ? l : r;
    }
    
};

int main_lowestCommonAncestor(int argc, const char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    TreeNode *p = new TreeNode(4), *q = new TreeNode(5);
    root->left->left->left = p;
    root->left->left->right = q;
    
    Solution s;
    TreeNode* ret = s.lowestCommonAncestor(root, p, q);
    cout << ret->val << endl;
    return 0;
}