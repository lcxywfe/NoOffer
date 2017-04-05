//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
//要求不能创建任何新的结点，只能调整树中结点指针的指向。

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
struct Nodes {
    TreeNode* min;
  	TreeNode* max;
    Nodes() {
        min = NULL;
        max = NULL;
    }
};
    Nodes func(TreeNode* root) {
        Nodes result;
        result.min = root;
        result.max = root;
        
        if (!root->left && !root->right) {
            return result;
        }
        
        if (root->left) {
            Nodes leftNodes = func(root->left);
            result.min = leftNodes.min;
            leftNodes.max->right = root;
            root->left = leftNodes.max;
        }
        
        if (root->right) {
            Nodes rightNodes = func(root->right);
            result.max = rightNodes.max;
            root->right = rightNodes.min;
            rightNodes.min->left = root;
        }
        
        return result;
        
        
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree)
            return NULL;
        Nodes result = func(pRootOfTree);
        
        return result.min;
    }
};