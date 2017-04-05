//给定一颗二叉搜索树，请找出其中的第k大的结点。
//例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。

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
    void dfs(TreeNode* node, TreeNode*& result, int& k) {
        
        if (!node)
            return;
        if (node->left) {
            dfs(node->left, result, k);
        }
        if (result)
            return;
        if (k == 1) {
            result = node;
            return;
        }
        --k;
        if (node->right) {
            dfs(node->right, result, k);
        }
    }
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode* result = nullptr;
        if (!pRoot)
            return nullptr;
        dfs(pRoot, result, k);
        
        return result;
    }

    
};