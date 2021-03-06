/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
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
    
    void postordertraversal(TreeNode* root, int depth, int parent, int &global_depth, int &global_parent,int key){
        if(root == NULL)
            return;
        else{
            postordertraversal(root->left,depth+1,root->val,global_depth,global_parent,key);
            postordertraversal(root->right,depth+1,root->val,global_depth,global_parent,key);
            if(root->val == key){
                global_depth = depth;
                global_parent = parent;
            }
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int depth1,parent1,depth2,parent2;
        depth1 = -1; parent1 = -1; depth2 = -1; parent2 = 1;
        postordertraversal(root,0,root->val,depth1,parent1,x);
        postordertraversal(root,0,root->val,depth2,parent2,y);
        if(depth1 == depth2 && parent1 != parent2)
            return true;
        else
            return false;
    }
};