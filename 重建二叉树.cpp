//输入某二叉树的前序遍历和中序遍历的结果，
//请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	TreeNode* construct(vector<int>& pre, vector<int>& vin, int pl, int vl, int k) {
        if (k < 1)
            return NULL;
        TreeNode* root = new TreeNode(pre[pl]);
        int kTemp = 0;
        for (int i = vl; i < vl+k; ++i) {
            if (vin[i] == pre[pl])
                break;
            ++kTemp;
        }
        root->left = construct(pre, vin, pl+1, vl, kTemp);
        root->right = construct(pre, vin, pl+kTemp+1, vl+kTemp+1, k-kTemp-1);
        
        return root;
    }    
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		return construct(pre, vin, 0, 0, pre.size());
    }
};
