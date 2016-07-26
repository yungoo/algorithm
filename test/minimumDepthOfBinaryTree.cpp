//
//  minimumDepthOfBinaryTree.cpp
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        
        int l = INT_MAX;
        if (root->left) {
            l = 1 + minDepth(root->left);
        }
        
        int r = INT_MAX;
        if (root->right) {
            r = 1 + minDepth(root->right);
        }
        
        int nodes = min(l, r);
        
        //cout << "l:" << l << " r:" << r << " nodes:" << nodes << endl;
        
        return nodes;
    }
    
};

int main_minimumDepthOfBinaryTree(int argc, const char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = new TreeNode(5);
    
    
    Solution s;
    int count = s.minDepth(root);
    
    cout << count << endl;
    
    return 0;
}