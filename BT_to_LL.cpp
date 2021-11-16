/**
Autor: pointnotfoe
Leetcode: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/#
*/
/*
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
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
class Solution {//Mine some issues
public:
    void flatten(TreeNode* root) {
        if (nullptr == root || 0 == root->val)// || nullptr == root->right || nullptr == root->left)
        {
            return;
        }
        static TreeNode * prev = nullptr;
//        static TreeNode * prev_right = nullptr;
        //prev = root;
        flatten(root->left);
        if (nullptr != prev && root != prev->right)
        {
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        //prev_right = root->right;
        prev = root;
        flatten(root->right);
    }
   // TreeNode * prev;
};
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!
class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now)
		{
			if(now->left)
			{
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};
//reverse pre order etc https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
private TreeNode prev = null;

public void flatten(TreeNode root) {
    if (root == null)
        return;
    flatten(root.right);
    flatten(root.left);
    root.right = prev;
    root.left = null;
    prev = root;
}

int main()
{
    Solution two_sum;
    vector<int> test_data = {1,2,3,10,50,78,6};
    vector<int> answer = test_data.twoSum(test_data,64);

    return 0;

}
