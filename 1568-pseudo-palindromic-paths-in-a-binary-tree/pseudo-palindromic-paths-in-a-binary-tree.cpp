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
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> digits(10, 0);
        // Start DFS traversal from the root.
        return dfs(root, digits);
    }

private:
private:
    // Recursive function for DFS traversal.
    int dfs(TreeNode* root, vector<int>& digits) {
        // Base case: If the current node is NULL, return 0.
        if (root == nullptr)
            return 0;

        // Increment the count of the current digit.
        digits[root->val]++;

        // If the current node is a leaf, check if the path is
        // pseudo-palindromic.
        if (root->left == nullptr && root->right == nullptr) {
            int cnt = countOdd(digits);
            digits[root->val]--; // Backtrack by decrementing the count.

            return (cnt <= 1) ? 1 : 0;
        }

        // Recursively traverse the left and right subtrees.
        int leftCount = dfs(root->left, digits);
        int rightCount = dfs(root->right, digits);

        // Backtrack by decrementing the count of the current digit.
        digits[root->val]--;

        return leftCount + rightCount;
    }
    int countOdd(const vector<int>& digits) {
        int cnt = 0;

        for (int i = 1; i < 10; ++i) {
            if ((digits[i]) & 1)
                cnt++;
        }
        return cnt;
    }
};