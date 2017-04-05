//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

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
            vector<TreeNode*> cur(0);
            cur.push_back(pRoot);
            while(cur.size() > 0) {
                vector<int> curVal(0);
                for (int i = 0; i < cur.size(); ++i)
                    curVal.push_back(cur[i]->val);
                result.push_back(curVal);
                
                vector<TreeNode*> temp(0);
                for (int i = 0; i < cur.size(); ++i) {
                    if (cur[i]->left)
                        temp.push_back(cur[i]->left);
                    if (cur[i]->right)
                        temp.push_back(cur[i]->right);
                } 
                swap(temp, cur);
                vector<int>(0).swap(curVal);
            }
            
            return result;
        }
    
};