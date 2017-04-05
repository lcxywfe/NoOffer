//输入一棵二叉树，判断该二叉树是否是平衡二叉树。

class Solution {
private:
    bool isBalanced(TreeNode* node, int& Dep) {
        if (!node) {
            Dep = 0;
            return true;
        }
        
        int leftDep = 0;
        int rightDep = 0;
        if (isBalanced(node->left, leftDep) && isBalanced(node->right, rightDep)) {
            if (leftDep - rightDep >= -1 && leftDep - rightDep <= 1) {
                Dep = (leftDep > rightDep ? leftDep : rightDep) + 1;
                return true;
            } else
                return false;
        }
        
        return false;
    }
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return isBalanced(pRoot, dep);
    }
};
