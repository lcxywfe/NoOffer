//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
//使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
//并保证奇数和奇数，偶数和偶数之间的相对位置不变。

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for (int i = 0; i < array.size(); ++i) {
            if (array[i] % 2 == 0) {
                bool hasEven = false;
                for (int j = i+1; j < array.size(); ++j) {
                    if (array[j] % 2 != 0) {
                        int temp = array[j];
                        for (int k = j; k >= i+1; --k) {
                            array[k] = array[k-1];
                        }
                        array[i] = temp;
                        hasEven = true;
                        break;
                    }
                }
                if (!hasEven)
                    return;
            }
        }
    }
};