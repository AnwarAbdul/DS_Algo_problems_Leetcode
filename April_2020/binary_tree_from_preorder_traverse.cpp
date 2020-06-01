/*
Construct Binary Search Tree from Preorder Traversal
Solution
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct.
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *createNode(int val){
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<TreeNode*> tree_stack;
        TreeNode *root;
        if(preorder.size() == 0){
            root = NULL;
            return root;
        }
        root = createNode(preorder.front());
        tree_stack.push_back(root);
        TreeNode *temp;
        for(int i = 1; i < preorder.size(); i++){
            temp = createNode(preorder[i]);
            if(temp->val < tree_stack.back()->val){
                tree_stack.back()->left = temp;
                tree_stack.push_back(temp);
                continue;
            }
            auto it_front = tree_stack.begin();
            auto it_rear = tree_stack.end();
            for(int j = 0; j < tree_stack.size(); j++){
                if(temp->val > tree_stack[j]->val){
                    tree_stack[j]->right = temp;
                    tree_stack.erase(it_front+j,it_rear);
                    tree_stack.push_back(temp);
                    continue;
                }
            }
        }
        return root;
    }
};