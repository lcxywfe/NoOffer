//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
//则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> result(0);
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        
        int flag = 0; // 0:right  1:down  2:left  3:up
        int i = 0, j = 0;
        int up = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        while(1) {
            result.push_back(matrix[i][j]);
            if (flag == 0) {                 //right
                if (j == right) {
                    if (i == down)
                        return result;
               		++i;
                    flag = 1;
                    ++up;
                } else {
                    ++j;
                }
            } else if (flag == 1) {          //down
                if (i == down) {
                    if (j == left)
                        return result;
                    --j;
                    flag = 2;
                    --right;
                } else {
                    ++i;
                }
            } else if (flag == 2) {           //left
                if (j == left) {
                    if (i == up) 
                        return result;
                    --i;
                    flag = 3;
                    --down;
                } else {
                    --j;
                }
            } else if (flag == 3) {           //up
                if (i == up) {
                    if (j == right)
                        return result;
                    ++j;
                    flag = 0;
                    ++left;
                } else {
                    --i;
                }
            }
        }
        
        return result;
    }
};