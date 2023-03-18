#include<bits/stdc++.h>
using namespace std;

// MEDIUM 1
// Question - Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      
      TreeNode(int x)
      {
        val = x;
        left = NULL;
        right = NULL;
      }
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){return root;}

// if values of both p and q nodes are smaller than current root node val check in left subtree
        if(p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

// if values of both p and q nodes are greater than current node val check in right subtree
        else if(p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

// if val of p node is smaller than current root and q node val is greater than current root (or vice versa) then this root is the LCA
        else return root;
    }
};

// TIME COMPLEXITY - O(Log N) or the max depth of the tree
// SPACE COMPLEXITY - O(Log N) for call stack (max depth of the tree)