/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

 

Constraints:

The number of elements of the BST is between 1 to 10^4.
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    
    void inorder_traverse(TreeNode *root, int k, int &found, int &val, int &pos){
        if(root == NULL)
            return;
        else{
            inorder_traverse(root->left,k,found,val,pos);
            if(found)
                return;
            pos++;
            if(pos == k){
                val = root->val;
                found = 1;
                return;
            }
            inorder_traverse(root->right,k,found,val,pos);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int found = 0;
        int val = root->val;
        int pos = 0;
        inorder_traverse(root,k,found,val,pos);
        return val;
    }
};