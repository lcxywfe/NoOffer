//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

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
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result(0);
        if (!root)
            return result;
        
        vector<TreeNode*> curNodes(0);
        curNodes.push_back(root);
        vector<TreeNode*> tempNodes(0);
        while (curNodes.size() > 0) {
            tempNodes.clear();
            for (int i = 0; i < curNodes.size(); ++i) {
                result.push_back(curNodes[i]->val);
                if (curNodes[i]->left)
                    tempNodes.push_back(curNodes[i]->left);
                if (curNodes[i]->right)
                    tempNodes.push_back(curNodes[i]->right);
            }
            curNodes.clear();
            curNodes.swap(tempNodes);
        }
        
        return result;
    }
};