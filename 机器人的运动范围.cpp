//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
//每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。
//请问该机器人能够达到多少个格子？

class Solution {
private:
    bool small(int i, int j, const int& threshold) {
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i /= 10;
        }
        while (j != 0) {
            sum += j % 10;
            j /= 10;
        }
        
        return sum <= threshold;
    }
    void dfs(vector<vector<bool>>& valid, const int& rows, const int& cols, int i, int j, const int& threshold) {
        if (!small(i, j, threshold))
            return;
        
        valid[i][j] = false;
        
        if (i-1 >=0 && valid[i-1][j])
            dfs(valid, rows, cols, i-1, j, threshold);
        if (i+1 < rows && valid[i+1][j])
            dfs(valid, rows, cols, i+1, j, threshold);
        if (j-1 >= 0 && valid[i][j-1])
            dfs(valid, rows, cols, i, j-1, threshold);
        if (j+1 < cols && valid[i][j+1])
            dfs(valid, rows, cols, i, j+1, threshold);
    }
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int result = 0;
        if (rows == 0 || cols == 0)
            return 0;
        
        vector<vector<bool>> valid(0);
        for (int i = 0; i < rows; ++i) {
            vector<bool> temp(cols, true);
            valid.push_back(temp);
        }
        
        dfs(valid, rows, cols, 0, 0, threshold);
        
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (!valid[i][j])
                    ++result;
        
        return result;
        
    }
};