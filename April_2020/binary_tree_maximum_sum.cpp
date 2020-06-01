/*
Binary Tree Maximum Path Sum
Solution
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    
    int maxi(int a, int b){
        if(a > b)
            return a;
        else
            return b;
    }
    
    int postordertraverse(TreeNode* root, int &res){
        if(root == NULL){
            return INT_MIN;
        }
        else{
            int lsum = postordertraverse(root->left,res);
            int rsum = postordertraverse(root->right,res);
            int maxsingle = maxi(maxi(lsum,rsum)+root->val,root->val);
            int maxtop = maxi(maxsingle,root->val + lsum + rsum);
            res = maxi(maxtop,res);
            return maxsingle;
            
        }
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        postordertraverse(root,res);
        return res;
    }
};
