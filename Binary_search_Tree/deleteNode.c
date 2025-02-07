class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int gd) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        // Find the node to delete
        for (; curr && curr->val != gd; prev = curr, curr = (curr->val > gd ? curr->left : curr->right));

        if (curr) {
            // Case 1: Node has two children
            if (curr->left && curr->right) {
                TreeNode* a = curr->right;
                while (a->left)
                    a = a->left;
                a->left = curr->left;
                curr->left = nullptr;

                if (curr == root)
                    root = curr->right;
                else {
                    if (prev->val < curr->val)
                        prev->right = curr->right;
                    else
                        prev->left = curr->right;
                }
                delete curr;
            }
            // Case 2: Leaf node
            else if (!curr->left && !curr->right) {
                if (curr == root) {
                    root = nullptr;
                } else {
                    if (prev->val > curr->val)
                        prev->left = nullptr;
                    else
                        prev->right = nullptr;
                }
                delete curr;
            }
            // Case 3: Node has only one child
            else {
                TreeNode* child = (curr->left) ? curr->left : curr->right;

                if (curr == root) {
                    root = child;
                } else {
                    if (prev->val > curr->val)
                        prev->left = child;
                    else
                        prev->right = child;
                }
                delete curr;
            }
        }
        return root;  // Ensure the updated tree is returned
    }
};
