//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
//例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba
//输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

class Solution {
private:
    void dfs(vector<string>& result, string& temp, const string& str, vector<bool>& valid) {
        if (temp.size() == str.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < valid.size(); ++i) {
            if (valid[i] && (i==0 || str[i]!=str[i-1] || !valid[i-1])) {
                temp += str[i];
                valid[i] = false;
                dfs(result, temp, str, valid);
                valid[i] = true;
                temp = temp.substr(0, temp.size()-1);;
            }
        }
    }
public:
    vector<string> Permutation(string str) {
        vector<string> result(0);
        if (str.size() == 0)
            return result;
        
        sort(str.begin(), str.end());
        
        string temp = "";
        vector<bool> valid(str.size(), true);
        
        dfs(result, temp, str, valid);
        
        return result;
        
    }
};