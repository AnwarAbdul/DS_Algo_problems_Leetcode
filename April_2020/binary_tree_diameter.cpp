/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

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

	int height_calc(TreeNode* root){
		if(root == NULL)
			return 0;
		return 1 + maxi(height_calc(root->left),height_calc(root->right));
	}

    int dia_calc(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	else{
    		int l_dia = dia_calc(root->left);
    		int r_dia = dia_calc(root->right);

    		int l_h = height_calc(root->left);
    		int r_h = height_calc(root->right);

    		int self_dia = l_h + r_h + 1;

    		return maxi(self_dia,maxi(l_dia,r_dia));
    	}
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
    	int res = dia_calc(root);
    	if(res == 0)
    		return 0;
    	else
    		return res-1;
    }
};