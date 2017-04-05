//输入两棵二叉树A，B，判断B是不是A的子结构。
//（ps：我们约定空树不是任意一个树的子结构）

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
    bool sameTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1->val != pRoot2->val)
            return false;
        bool left = !pRoot2->left;
        bool right = !pRoot2->right;
        if (pRoot1->left && pRoot2->left)
            left = sameTree(pRoot1->left, pRoot2->left);
        if (pRoot1->right && pRoot2->right)
            right = sameTree(pRoot1->right, pRoot2->right);
       	
        return left && right;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false;
        
		if (sameTree(pRoot1, pRoot2))
            return true;
        
        bool left = false;
        if (pRoot1->left)
            left = HasSubtree(pRoot1->left, pRoot2);
        bool right = false;
        if (pRoot1->right)
            right = HasSubtree(pRoot1->right, pRoot2);
        
        return left || right;
    }
};
