//请实现一个函数按照之字形打印二叉树，
//即第一行按照从左到右的顺序打印，
//第二层按照从右至左的顺序打印，
//第三行按照从左到右的顺序打印，其他行以此类推。

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
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result(0);
        if (!pRoot)
            return result;
        
        int flag = 0;
        vector<TreeNode*> cur(0);
        cur.push_back(pRoot);
        while (cur.size() > 0) {
            vector<int> temp(0);
            if (flag == 0) {
                for (int i = 0; i < cur.size(); ++i)
                    temp.push_back(cur[i]->val);
            }
            if (flag == 1) {
                for (int i = cur.size()-1; i >= 0; --i)
                    temp.push_back(cur[i]->val);
            }
            result.push_back(temp);
            flag = (++flag) % 2;
            
            vector<TreeNode*> tempCur(0);
            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i]->left)
                    tempCur.push_back(cur[i]->left);
                if (cur[i]->right)
                    tempCur.push_back(cur[i]->right);
            }
            
            swap(cur, tempCur);
            vector<int>(0).swap(temp);
                          
        }
        
        return result;
    }
    
};