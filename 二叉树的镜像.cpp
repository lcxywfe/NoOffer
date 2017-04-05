//操作给定的二叉树，将其变换为源二叉树的镜像。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    void swapTree(TreeNode*& left, TreeNode*& right) {
        TreeNode* temp = left;
        left = right;
        right = temp;
    }
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot)
            return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        swapTree(pRoot->left, pRoot->right);

    }
};