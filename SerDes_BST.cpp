/*
Autor: pointnotfoe
Leetcode:https://leetcode.com/problems/serialize-and-deserialize-bst/
449. Serialize and Deserialize BST
Medium

3025

145

Add to List

Share
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.
*/

/*
Runtime: 88 ms, faster than 33.37% of C++ online submissions for Serialize and Deserialize BST.
Memory Usage: 26.9 MB, less than 56.29% of C++ online submissions for Serialize and Deserialize BST.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string output;
        serialize_recr(root, output);
        // cout << output << "\n";
        return output;
    }
    void serialize_recr(TreeNode* node, string &ser) {
        if (node == NULL)
        {    
            ser += "n ";
            return;
        }
        else
        {
            ser += to_string(node->val) + ' ';
            serialize_recr(node->left, ser);
            serialize_recr(node->right, ser);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data << "\n";
        if (data == "n " || data.size() == 0)
            return NULL;
        
        int cur = 0;
        TreeNode *root;
        des_rec(&root, data, cur);
        return root;
    }
    void des_rec(TreeNode **node, string &data, int &cur)
    {
        if (cur >= data.size())
            return;
        if (data[cur] == 'n')
        {
            cur += 2;
            return;
        }
        else
        {
            int next = data.find(' ', cur);
            string str_val = data.substr(cur, next - cur);
            int int_val = stoi(str_val);
            // cout <<"cur: " <<cur <<", space at: " << next << ", str_val: "<<str_val << ", int_val: "<< int_val <<"\n";
            *node = new TreeNode(int_val);
            cur = next+1;
            des_rec(&((*node)->left), data, cur);
            des_rec(&((*node)->right), data, cur);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;