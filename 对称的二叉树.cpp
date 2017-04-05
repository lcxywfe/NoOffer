//请实现一个函数，用来判断一颗二叉树是不是对称的。
//注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    bool same(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        
        if (!left || !right)
            return false;
        
        if (left->val != right->val)
            return false;
        
        return same(left->left, right->right) && same(left->right, right->left);
    }
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	if (!pRoot)
            return true;
        return same(pRoot->left, pRoot->right);
    }

};