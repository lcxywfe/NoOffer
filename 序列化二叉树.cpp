//请实现两个函数，分别用来序列化和反序列化二叉树

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
    void encode(string& result, TreeNode* node) {
        if (!node) {
            result += '#';
            return;
        }
        result += to_string(node->val) + '.';
        encode(result, node->left);
        encode(result, node->right);
    }
    
    TreeNode* decode(char*& str, int& k) {
        if (str[k] == '\0' || str[k] == '#')
            return nullptr;
        string num = "";
        while (str[k] != '.')
            num += str[k++];
        TreeNode* cur = new TreeNode(atoi(num.c_str()));
        ++k;
        cur->left = decode(str, k);
        ++k;
        cur->right = decode(str, k);
        
        return cur;
    }
public: 
    char* Serialize(TreeNode *root) {  
        if (!root)
            return nullptr;
        string result = "";
        encode(result, root);
        char* c = new char[result.size()+1];
        for (int i = 0; i < result.size(); ++i)
            c[i] = result[i];
        c[result.size()] = '\0';
        return c; 
    }
    TreeNode* Deserialize(char *str) {
    	if (!str)
            return nullptr;
        int k = 0;
        return decode(str, k);
    }
};