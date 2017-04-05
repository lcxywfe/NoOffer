//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

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
    void dfs(vector<vector<int>>& result, vector<int>& tempResult, TreeNode* node, int& tempNumber, const int& expectNumber) {
        
        tempResult.push_back(node->val);
        tempNumber += node->val;
        
        if (!node->left && !node->right) {
            if (tempNumber == expectNumber) {
                result.push_back(tempResult);
            }
            tempNumber -= node->val;
            tempResult.pop_back();
            return;
        }
        
        if (node->left) {
            dfs(result, tempResult, node->left, tempNumber, expectNumber);
        }
        if (node->right) {
            dfs(result, tempResult, node->right, tempNumber, expectNumber);
        }
        
        tempNumber -= node->val;
        tempResult.pop_back();
        
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>> result(0);
        if (!root)
            return result;
        
        vector<int> tempResult(0);
        int tempNumber = 0;
        dfs(result, tempResult, root, tempNumber, expectNumber);
        
        return result;
    }
};