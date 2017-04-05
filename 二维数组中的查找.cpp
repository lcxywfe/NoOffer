//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() < 1 || array[0].size() < 1 )
            return false;
        int i = 0;
        int j = array[i].size() - 1;
        while (i < array.size() && j >= 0) {
            if (array[i][j] == target)
                return true;
            if (array[i][j] < target)
                ++i;
            else
                --j;
        }
        
        
        return false;
        
    }
};