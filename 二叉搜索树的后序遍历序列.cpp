//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
private:
    bool verify(vector<int>& sequence, int l, int r) {
        if (r - l <= 1)
            return true;
        bool small = true;
        int index = l;
        for (int i = l; i <= r-1; ++i) {
            if (sequence[i] > sequence[r]) {
                if (small) {
                	small = false;
                    index = i;
                }
            } else {
                if (!small)
                    return false;
            }
        }
        return verify(sequence, l, index-1) && verify(sequence, index, r-1);
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0)
            return false;
        return verify(sequence, 0, sequence.size()-1);
    }
};