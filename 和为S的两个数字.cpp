//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
//如果有多对数字的和等于S，输出两个数的乘积最小的。 
//对应每个测试案例，输出两个数，小的先输出。

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result(0);
        if (array.size() < 2)
            return result;
        
        int i = 0, j = array.size() - 1;
        bool first = true;
        int tempA = 0, tempB = 0;
        while (i < j) {
            if (array[i] + array[j] == sum) {
                if (first) {
                    tempA = array[i];
                    tempB = array[j];
                    first = false;
                } else {
                    if (tempA * tempB > array[i] * array[j]) {
                        tempA = array[i];
                        tempB = array[j];
                    }
                }
                ++i;
                --j;
            } else if (array[i] + array[j]  < sum) {
                ++i;
            } else {
                --j;
            }
        }
        
        if (!first) {
        	result.push_back(tempA);
        	result.push_back(tempB);    
        }
        
        
        return result;
        
    }
};