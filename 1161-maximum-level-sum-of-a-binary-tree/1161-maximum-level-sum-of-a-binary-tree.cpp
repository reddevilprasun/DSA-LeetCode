/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) { // Using BFS
        queue<TreeNode*> q;
        int maxSum = INT_MIN;
        int level = 0;
        int maxLevel = 0;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            int sum = 0;
            level++;
            for (int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
};